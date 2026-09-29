# DMV_TargetSystem

## Design intent
**Gather actors in the world and categorize them by the use they will have in the game.**

To categorize them, the system uses **filters**: "Find nearby candidates, filter them, pick one (or many)."

The system's aim is not to have an specific functionality, but to **provide to other systems**.

The system is centralized instead of shared, so the responsibility is easy to access and we don't need to re-implement the logic multiple times.

It answers to **"Who is the current target for context X on this local player."** continuously, **every tick.**

## Selection modes (`ENumberOfTargets`)
- **`SingleTarget`** - takes the first candidate that survives the Filters array, in whatever
  order the subsystem/filters left it. No tie-breaking logic.
- **`SingleTargetUseInterest`** - runs `UpdateInterest()` (angle- and/or distance-based scoring,
  toggled independently via `bUpdateInterestByConeAngle`/`bUpdateInterestByDistance`) over the
  candidates, then takes whichever has the highest `Interest`. Interest persists on the
  `UDMVTargetComponent` itself and decays continuously (a `0.01f` timer on the component, see
  `ResetInterest`), so a target that was recently "hot" stays slightly favored for a moment even
  if it briefly leaves the cone/range - a basic sticky-target behavior.
- **`MultiTarget`** - every candidate that survives the Filters array becomes a target. **No cap**
  - if you need to bound how many targets a group can have, do it in a Filter (e.g. a filter that
  sorts by distance/interest and truncates), not by expecting the evaluator to cap it.

`GetCurrentTarget()`/`GetCurrentTargetComponent()` always return the *first* current target for a
group (works unmodified for `SingleTarget`/`SingleTargetUseInterest`, since they only ever store
one). `GetCurrentTargets()`/`GetCurrentTargetComponents()` return the full list and are the ones
`MultiTarget` consumers should use.

## Use example
For basic interaction:
Two separate contexts, registered independently, doing two
different jobs off the same underlying actors:

- `ID.TargetGroup.CanInteract`, mode `MultiTarget` - every interactable actor within range/filter
  criteria, all at once. This is what UI reads to decide *which actors currently show an interact
  prompt* - there can legitimately be several at once (e.g. two pickups near each other).
- `ID.TargetGroup.Interact`, mode `SingleTarget` or `SingleTargetUseInterest` - the *one* actor
  that would actually be interacted with if the player pressed the interact button right now
  (typically the closest, or the one closest to screen-center via Interest). This is what the
  interact action itself resolves against.

Both contexts can watch the same `UDMVTargetComponent`s (an interactable actor would carry both
`ID.TargetGroup.CanInteract` and `ID.TargetGroup.Interact` in its `TargetContextIdentifiers`) -
they're independent `UTargetGroup`s evaluated separately, each with its own selection mode and
its own Filters, not two views of one shared result. The same pattern generalizes beyond
interaction: an "everything the player can currently target" MultiTarget context feeding UI,
paired with a "what would actually be hit/selected" single-target context feeding the action -
e.g. a lock-on reticle context (MultiTarget, feeds which enemies show a lock-on icon) alongside
an active-lock context (SingleTargetUseInterest, feeds which one enemy a homing ability actually
fires at).

Because each context is independent, **the selection mode is a per-context choice made when that
context is registered** - see `AddTargetEvaluationContext`'s `NumberOfTargets` parameter below,
not a global setting or something decided later.

## Core concepts

| Concept | Class | Role |
|---|---|---|
| Target Component | `UDMVTargetComponent` | Attached to anything that should be targetable. Registers itself with the subsystem under one or more context tags. |
| Target Subsystem | `UDMVTargetSubsystem` | `UGameInstanceSubsystem`. The single global registry: context tag &rarr; currently-registered `UDMVTargetComponent`s. |
| Target Evaluator | `UDMVTargetEvaluator` | An `ActorComponent`, meant to live on a `PlayerController`. Every tick, re-evaluates every active Target Group and decides its current target(s). |
| Target Group | `UTargetGroup` | One "thing I want targeted": a context tag, a list of Filters, and a selection mode (`ENumberOfTargets`). Created by calling `AddTargetEvaluationContext`. |
| Filter | `UDMVTargetFilter_Base` (+ subclasses) | A candidate-list transform - narrows/reorders the raw candidate list for one Target Group. |
| Interest | `UDMVTargetComponent::Interest` | A per-target "hotness" score that rises while it's the closest candidate by angle/distance and decays otherwise. Only consulted by the `SingleTargetUseInterest` selection mode. |

- Category: Is a target context tag; what a category is
*for*
- NumberOfTargets: Decides per context how many actors are 

## Data flow

```
targetable actor's UDMVTargetComponent::BeginPlay()
        |
        v
UDMVTargetSubsystem::RegisterTargetForContexts()   <-- keyed by ID.TargetGroup.* tag(s)
        |
        | (every tick, local controller only)
        v
UDMVTargetEvaluator::AnalyseTargetGroups()
        |
        |  for each active UTargetGroup:
        |    1. subsystem->GetTargetsForContext(GroupID)   -> raw candidates
        |    2. ApplyFiltersToCandidates()                  -> filtered candidates
        |    3. select per NumberOfTargets                  -> SingleTarget / SingleTargetUseInterest / MultiTarget
        v
CurrentTargetsMap[GroupID] = selected target(s)
        |
        v
callers poll GetCurrentTarget(GroupID) / GetCurrentTargets(GroupID)
```

OPEN ISSUE: There is no "target found" event, so a consumer reads the evaluator every tick
(or every frame it cares) rather than subscribing to a callback.

### Execution model: local-only, not replicated

`UDMVTargetEvaluator::BeginPlay` disables its own tick unless the owning `PlayerController` is
`IsLocalController()`. This is deliberate - targeting here is a per-viewer cosmetic concern (what
*this* player's screen should highlight/aim-assist toward), not gameplay-authoritative state nothing
here replicates, and `CurrentTargetsMap` only ever exists client-side, one per local player. **Never
use this system's answer to decide something that must be server-authoritative** (e.g. don't trust
"the current target" to resolve hit/damage - the server must independently validate any hit).

## Visibility

`UDMVTargetComponent` exposes multi-point visibility sampling, meant for any line-of-sight-style
filter to use instead of tracing to a single point (see `BP_TargetFilter_LineOfSight` below).

**Why not just trace to `GetComponentLocation()`?** A single point is a coin flip against partial
cover - if a wall happens to cover exactly where that point sits (e.g. a target's chest) but not
the rest of the target, a single-point trace reports "not visible" even though the target is
plainly visible (an arm or head sticking out past the wall, say). Sampling several points spread
across the target's actual extent and treating it as visible if **any** of them has a clear line
of sight fixes that.

### `EDMVTargetVisibilitySource`

- **`Point`** (default) - unchanged behavior: a single point at `GetComponentLocation()`. No extra
  setup.
- **`ProxyCollision`** - an explicit collision shape the actor author places and configures on the
  actor (e.g. a capsule roughly matching the body), referenced via `VisibilityProxy` (an
  `FComponentReference` - `UDMVTargetComponent` only points at it, doesn't spawn or own it). Best
  when the mesh's own collision is a poor fit for what "visible" should mean (way too
  tight/loose, or nonexistent).
- **`OwnerMeshCollision`** - reuses the actor's existing mesh collision automatically
  (`FindComponentByClass<UMeshComponent>()`), no extra shape needed. Set `VisibilityMeshOverride`
  only if the actor has more than one mesh component and auto-resolving would be ambiguous.

`ResolveVisibilityComponent()` resolves whichever shape `VisibilitySource` points at (or `nullptr`
in `Point` mode, or if `OwnerMeshCollision`/`ProxyCollision` can't find anything valid).

### `GetVisibilityTracePoints()`

Returns the world-space points a line-of-sight scan should trace against:

- `Point` mode, or no visibility component resolves: just `{ GetComponentLocation() }` - a single
  element, so a filter written for the multi-point case needs no special-casing for this fallback.
- Otherwise: 7 points spread across the resolved component's bounds - center, top, bottom, left,
  right, front, back:

```
Side view (Z)                    Top-down view (X/Y)

        top                              front
         |                                 |
         |                                 |
origin ->+   (center)          left ------>+<------ right
         |                                 |
         |                                 |
       bottom                             back
```

### Using it in a filter

1. Set the target's `VisibilitySource` (usually `OwnerMeshCollision` - zero extra setup).
2. In the scan/filter's trace logic, call `GetVisibilityTracePoints()` on the candidate's
   `UDMVTargetComponent` instead of tracing to a single location.
3. Loop over the returned points, running a line trace from the viewer to each. Treat the target
   as visible the moment **any** trace comes back unobstructed (no blocking hit, or the hit actor
   is the target itself) - don't require every point to be clear.

## Filters

A Filter is a `UDMVTargetFilter_Base` subclass (native or Blueprint) that implements
`PerformFilter(PotentialTargets, PlayerController, OutFilteredTargets)`. `OutFilteredTargets` is a
fresh, already-empty array `ApplyFiltersToCandidates` constructs new every call - add surviving
candidates to it, don't build/return a separate array of your own (there's nothing to return -
this is `void`, not a returned `TArray`). A
`UTargetGroup`'s `Filters` array holds actual filter **instances** (`Instanced` `UObject*`s, not
just class references), run in array order, each filter narrowing/reordering the previous
filter's output.

### Per-usage configuration

Filter instances are individually configured, not shared per class. Because
`UDMVTargetFilter_Base` is `EditInlineNew`/`Blueprintable`, a Blueprint child (e.g.
`BP_TargetFilter_ViewCone`) can add its own properties (a `MaxAngle`, a `TargetTag` to require,
whatever that filter needs - the base class no longer has a generic `Threshold` field, each
filter defines whatever comparison value(s) it actually needs) - that part of the class hierarchy already
worked before this change. What didn't work is *reusing the same filter class with different
settings in two different contexts*: `AddTargetEvaluationContext` used to take a plain
`TSubclassOf<UDMVTargetFilter_Base>` + one generic `float Value`, so every usage of a class got
identical property values.

Now `AddTargetEvaluationContext` takes `const TArray<UDMVTargetFilter_Base*>&` - actual
pre-configured instances, each with whatever custom properties you set on it - and
**duplicates each one** (`DuplicateObject`) into the new `UTargetGroup`'s own ownership. That
means:

- The same `BP_TargetFilter_ViewCone` class can be used with a 30° cone in one context and a 60°
  cone in another - build two separate instances (e.g. two `Instanced` `UPROPERTY`s on your
  `PlayerController`, each independently configured in its Details panel), pass each to a
  different `AddTargetEvaluationContext` call.
- The source instance you pass in is never mutated - `AddTargetEvaluationContext` always works on
  a duplicate, so the same source instance (or a shared `UDMVTargetFilter_Data` preset, see below)
  can safely be reused across multiple contexts/controllers without them stepping on each other.
- Filters no longer need per-tick construction - `ApplyFiltersToCandidates` just runs the
  `UTargetGroup`'s already-owned instances directly every tick instead of calling `NewObject` for
  each one (this also resolves the per-tick-allocation concern previously listed under Known
  Gaps).

### Convention: which properties should be per-usage tunable

When a filter instance is edited inline inside an `Instanced` array slot (a `UTargetGroup`'s
`Filters`, or a `UDMVTargetFilter_Data`'s `FilterList`), the engine already only shows properties
that aren't `EditDefaultsOnly` - no custom "exposed" flag or category scheme needed, this is just
the standard `EditAnywhere`/`EditInstanceOnly` vs. `EditDefaultsOnly` distinction:

- **`EditAnywhere` (or `EditInstanceOnly`)** - shows up on every per-usage instance, so use it for
  anything that's meant to vary per context: any property a Blueprint subclass adds that a
  specific usage should be able to tune (a `MaxAngle`, a required tag, etc.). Prefer
  `EditAnywhere` over `EditInstanceOnly` when a sensible shared starting value exists (it's then
  also settable as that filter class's own default, so a fresh instance doesn't start at a bare
  `0`/`nullptr`); use `EditInstanceOnly` only if the property should never have a class-level
  default at all.
- **`EditDefaultsOnly`** - only editable on the filter *class*'s own Class Defaults, hidden from
  every per-usage instance. Use it for anything that's a fixed choice baked into that filter
  class rather than something a level/context author should retune each time it's used -
  `ScanClass` on the base class is already marked this way for exactly that reason.

This is a per-property choice, not a per-class one - a single filter can freely mix both kinds of
properties. `Category` is still worth using to visually group the exposed properties in the
Details panel, but it doesn't control what's shown - `EditDefaultsOnly` vs. `EditAnywhere`/
`EditInstanceOnly` does.

**From a Blueprint filter subclass** (the expected way most filters get authored - see the
example filters below), these C++ specifiers aren't directly on the variable creation UI, but
they map onto standard Blueprint variable flags. For a new variable in the Blueprint's My
Blueprint panel:

1. Expose it at all - click its eye icon in the My Blueprint list (or check **Editable** in its
   Details tab). An unexposed variable doesn't show in any Details panel, Class Defaults or
   per-instance - only in the Blueprint's own graphs.
2. Once exposed, its Details tab has an **Instance Editable** checkbox:
   - **Checked** - per-usage tunable (the `EditAnywhere` bucket above). Use this for anything
     like `MaxAngle` that a specific context should be able to retune.
   - **Unchecked** - Class Defaults only (the `EditDefaultsOnly` bucket above). Use this for
     anything fixed per filter class, like `ScanClass`.

There's no Blueprint-variable equivalent of the narrower `EditInstanceOnly` (hidden from Class
Defaults, visible only per-instance) - that combination is C++-only. From Blueprint it's a binary
choice: **Instance Editable on** for tunable properties, **off** for fixed ones.

**Footgun:** the base `PerformFilter_Implementation` leaves `OutFilteredTargets` empty, and
`SortCandidates_Implementation` returns an **empty array** - neither is the input unmodified. A
`Filter` subclass that forgets to override `PerformFilter` doesn't act as a no-op/pass-through -
it silently excludes every candidate for that group. Always override `PerformFilter` in any new
filter, and always add to `OutFilteredTargets` rather than building/returning a separate array -
see [Filters](#filters) above for why that specific mistake used to cause targets to get "stuck"
and never clear.

`SortCandidates` is declared (also `BlueprintNativeEvent`) but **the evaluator never calls it** -
if a filter needs to sort, do it inside its own `PerformFilter`.

For per-candidate checks too expensive to inline (e.g. a line trace), a filter can use
`SpawnActorToScan(PlayerController, Target)`, which spawns its `ScanClass`
(`ADMVScanForActors` subclass, overriding `PerformScan`), asks it to do the check, then destroys
it - one actor spawned and destroyed per candidate per call. Fine at small candidate counts; a hot
path if a `MultiTarget` group with many candidates uses a scan-based filter every tick.

Existing example filters, shipped as Blueprints in this plugin's own
[`Content/FilterLibrary/`](Content/FilterLibrary) (not yet referenced by any Labslop content):

- `BP_TargetFilter_Distance` - presumably thresholds candidates by distance from the player.
- `BP_TargetFilter_ViewCone` (+ `ViewAngleByDistance_Curve`) - presumably thresholds candidates by
  view angle, with the allowed angle varying by distance via the curve asset.
- `BP_TargetFilter_LineOfSight` (+ `BP_Scan_LineOfSight` as its `ScanClass`) - a per-candidate
  visibility trace via the scan-actor pattern above, using the multi-point sampling described in
  [Visibility](#visibility) below rather than a single trace to the target's location.

### Reusable presets: `UDMVTargetFilter_Data`

`UDMVTargetFilter_Data` (a `UDataAsset` holding an `Instanced` array of filters, `FilterList`)
lets a designer author a reusable, individually-configured set of filters once - as an asset,
not buried in a `PlayerController` Blueprint graph - and reuse it across multiple contexts.
Call `Evaluator->AddTargetEvaluationContextFromData(GroupTag, FilterDataAsset, NumberOfTargets,
...)` instead of `AddTargetEvaluationContext` to consume one directly; it duplicates
`FilterData->FilterList` the same way the base function duplicates any other filter array, so the
same asset stays a safe, unmutated template no matter how many contexts pull from it.

### Proximity culling

By default, every target registered under a context tag reaches that `UTargetGroup`'s Filters,
every tick - fine at small scale, but every registered target then pays whatever cost the Filters
chain has (a scan-based filter is the extreme case, see [above](#filters)), even ones nowhere near
the player. `AddTargetEvaluationContext`/`AddTargetEvaluationContextFromData`'s optional trailing
`MaxCullDistance` parameter (default `0.f`, meaning no culling - identical behavior to before this
parameter existed) drops a candidate before it ever reaches Filters if it's farther than that from
the player's view location.

Culling isn't a plain per-candidate distance check, because that would still mean touching every
registered target under the tag once per query - the same cost it's meant to avoid. Instead,
`UDMVTargetSubsystem::GetTargetsForContext` maintains a spatial hash grid (`SpatialGrid`, bucketed
by `SpatialGridCellSize`, default 500cm cells) over every registered target regardless of tag. A
radius query only walks the grid cells overlapping the query sphere, then filters that (usually
much smaller) set down by tag and exact distance - so the cost scales with how many targets are
actually near the query point, not with how many are registered under the tag in total. The
tradeoff: the grid is rebucketed periodically (`SpatialGridRebuildInterval`, default `0.1f`
seconds) rather than every tick, since rebuilding it requires touching every registered target's
current location anyway - a moving target can be positionally stale by up to that interval before
a query reflects its new cell. Neither the grid nor its rebuild timer exist until the first caller
actually passes `MaxCullDistance > 0.f` - a context that never culls pays nothing extra, and
`GetTargetsForContext` falls back to returning every registered target for the tag exactly as it
did before culling existed.

**Possible future option: physics-overlap-based proximity instead of a polling grid.** The grid
still touches every registered target once per rebuild interval to find out where it currently is
- there's no way to skip that within a polling design, since you can't know something is far away
without ever checking its position. An alternative that avoids polling entirely: attach a large
`USphereComponent` proximity trigger to each local player and let Unreal's physics broadphase
(which already maintains its own optimized spatial structure) push
`OnComponentBeginOverlap`/`OnComponentEndOverlap` events when a targetable actor's collision
enters/exits range, instead of us scanning for it. The subsystem would maintain a per-player
"currently nearby" set purely from those events - zero cost for anything outside the sphere between
crossings, and no periodic scan at all. Tradeoff: it requires every targetable actor to carry a
collision component on a dedicated trace channel plus a sphere trigger per local player (more setup
surface than the grid), and overlap events are binary ("in range" or not, not a distance), so a
`MaxCullDistance`-style radius would still need a secondary distance check over the now much
smaller overlapping set. Not worth building without evidence the polling grid is an actual
bottleneck - noted here as the answer if that evidence shows up.

## Integrating it into a project

1. Add a `UDMVTargetEvaluator` component to your `PlayerController` Blueprint/class. It
   self-disables on every machine except the owning client, so it's safe to add unconditionally.
2. On anything that should be targetable, add a `UDMVTargetComponent` (or a Blueprint subclass of
   it) and set its `TargetContextIdentifiers` to the `ID.TargetGroup.*` tag(s) it should be
   findable under (see [Gameplay tags](#gameplay-tags) below - you'll need to declare your own).
3. Wherever you want a target (a weapon's aim-assist, an ability's targeting, an interact prompt),
   call `Evaluator->AddTargetEvaluationContext(GroupTag, Filters, NumberOfTargets, ...)` (or
   `AddTargetEvaluationContextFromData` with a `UDMVTargetFilter_Data` asset) once (e.g. on equip/
   activate) to register a `UTargetGroup` - explicitly choosing `SingleTarget`,
   `SingleTargetUseInterest`, or `MultiTarget` for *this* context, per
   [Design intent](#design-intent) above, and passing already-configured filter instances (see
   [Filters](#filters) above for per-usage configuration). Keep the returned `UTargetGroup*` if you
   need to change `Filters`/`NumberOfTargets` later.
4. Poll `Evaluator->GetCurrentTarget(GroupTag)` (or `GetCurrentTargets` for a `MultiTarget` group)
   wherever you need the answer - there's no push/event API yet, see below.
5. Call `Evaluator->RemoveTargetEvaluationContext(GroupTag)` when you're done with it (e.g. on
   unequip/ability end) so the evaluator stops evaluating a group nobody's reading anymore.

## Gameplay tags

Target contexts are `FGameplayTag`s under the `ID.TargetGroup` category (enforced via
`meta=(Categories="ID.TargetGroup")` on every tag-typed parameter/property in this plugin). The
plugin itself only declares one placeholder, `ID.TargetGroup.Example`
(`DMV_TargetingGameplayTags.h`), meant purely as an illustration for the tag picker - consuming
projects are expected to declare their own. Labslop's own `LBP_GameplayTags.h`/`.cpp` currently
declares `ID.TargetGroup.Enemy` and `ID.TargetGroup.InteractActor`, also not yet consumed by
anything.
