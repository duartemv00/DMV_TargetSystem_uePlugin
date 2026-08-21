# DMV_TargetSystem

A client-local candidate-selection plugin: given a set of "targetable" actors in the world, it
picks which one (or ones) a specific local player is currently "targeting" for a given purpose -
aim-assist, a lock-on reticle, ability targeting, an interact prompt, and so on. It does not
apply damage, does not replicate, and is not itself an aiming/input system - it only answers
"who is the current target for context X on this local player," continuously, every tick.

**Status:** foundational and not yet wired into Labslop. Nothing in `Source/Labslop` currently
adds a `UDMVTargetEvaluator` to a `PlayerController` or a `UDMVTargetComponent` to any actor -
the plugin is a self-contained system with its own example filters in
[`Content/FilterLibrary/`](Content/FilterLibrary), ready to be integrated when the first
consuming system (aim-assist, enemy lock-on, an interact prompt, etc.) needs it. See
[Integrating it into a project](#integrating-it-into-a-project) below for how that hookup should
look.

## Core concepts

| Concept | Class | Role |
|---|---|---|
| Target Component | `UDMVTargetComponent` | Attached to anything that should be targetable. Registers itself with the subsystem under one or more context tags. |
| Target Subsystem | `UDMVTargetSubsystem` | `UGameInstanceSubsystem`. The single global registry: context tag &rarr; currently-registered `UDMVTargetComponent`s. |
| Target Evaluator | `UDMVTargetEvaluator` | An `ActorComponent`, meant to live on a `PlayerController`. Every tick, re-evaluates every active Target Group and decides its current target(s). |
| Target Group | `UTargetGroup` | One "thing I want targeted": a context tag, a list of Filters, and a selection mode (`ENumberOfTargets`). Created by calling `AddTargetEvaluationContext`. |
| Filter | `UDMVTargetFilter_Base` (+ subclasses) | A candidate-list transform - narrows/reorders the raw candidate list for one Target Group. |
| Interest | `UDMVTargetComponent::Interest` | A per-target "hotness" score that rises while it's the closest candidate by angle/distance and decays otherwise. Only consulted by the `SingleTargetUseInterest` selection mode. |

### Data flow

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

It's a **polling** model: there is no "target found" event today (see
[Known gaps](#known-gaps--open-design-questions)). A consumer reads the evaluator every tick
(or every frame it cares) rather than subscribing to a callback.

### Execution model: local-only, not replicated

`UDMVTargetEvaluator::BeginPlay` disables its own tick unless the owning `PlayerController` is
`IsLocalController()`. This is deliberate - targeting here is a per-viewer cosmetic concern (what
*this* player's screen should highlight/aim-assist toward), not gameplay-authoritative state nothing
here replicates, and `CurrentTargetsMap` only ever exists client-side, one per local player. **Never
use this system's answer to decide something that must be server-authoritative** (e.g. don't trust
"the current target" to resolve hit/damage - the server must independently validate any hit).

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

## Filters

A Filter is a `UDMVTargetFilter_Base` subclass (native or Blueprint) that implements
`PerformFilter(PotentialTargets, PlayerController) -> TArray<UDMVTargetComponent*>`. A
`UTargetGroup`'s `Filters` array (`FFilterInformation`: a `Threshold` float + a
`TSubclassOf<UDMVTargetFilter_Base>`) is instantiated fresh via `NewObject` every tick in
`ApplyFiltersToCandidates` and run in array order, each filter narrowing/reordering the previous
filter's output.

**Footgun:** the base `PerformFilter_Implementation`/`SortCandidates_Implementation` both return
an **empty array**, not the input unmodified. A `Filter` subclass that forgets to override
`PerformFilter` doesn't act as a no-op/pass-through - it silently excludes every candidate for
that group. Always override `PerformFilter` in any new filter.

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
- `BP_TargetFilter_LineOfSight` (+ `BP_Scan_LineOfSight` as its `ScanClass`) - presumably a
  per-candidate visibility trace via the scan-actor pattern above.

`UDMVTargetFilter_Data` (a `UDataAsset` holding an `Instanced` array of filters) exists so
designers can author reusable filter presets without editing a `PlayerController` Blueprint
directly - but **nothing currently reads a `UDMVTargetFilter_Data` asset anywhere**; it's an
orphaned convenience type. Wire it into `AddTargetEvaluationContext`'s call site (or add an
overload that takes one) if/when a designer workflow wants that.

## Integrating it into a project

1. Add a `UDMVTargetEvaluator` component to your `PlayerController` Blueprint/class. It
   self-disables on every machine except the owning client, so it's safe to add unconditionally.
2. On anything that should be targetable, add a `UDMVTargetComponent` (or a Blueprint subclass of
   it) and set its `TargetContextIdentifiers` to the `ID.TargetGroup.*` tag(s) it should be
   findable under (see [Gameplay tags](#gameplay-tags) below - you'll need to declare your own).
3. Wherever you want a target (a weapon's aim-assist, an ability's targeting, an interact prompt),
   call `Evaluator->AddTargetEvaluationContext(GroupTag, Filters, ...)` once (e.g. on equip/
   activate) to register a `UTargetGroup`. Keep the returned `UTargetGroup*` if you need to
   change `Filters`/`NumberOfTargets` later.
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

## Known gaps / open design questions

These are real, currently-true limitations - not hypotheticals - worth resolving before building
a system that depends on them:

- **`OnValidTargetFound`/`OnTargetCleared` are declared but never broadcast.** `SetCurrentTarget`/
  `SetCurrentTargets`/`ClearCurrentTarget` update `CurrentTargetsMap` but don't fire either
  delegate - the only way to know the current target today is polling `GetCurrentTarget(s)` every
  tick. Wiring this up properly needs: (a) diffing the previous vs. new target set per group so
  "found" only fires for actors that are newly present (not every tick the group re-evaluates to
  the same answer), and (b) a decision on `MultiTarget` semantics - `OnValidTargetFound` is a
  single-`AActor*` delegate (fine to broadcast once per newly-found actor) but
  `OnTargetCleared`/`FPlayerAutoTargetsCleared` takes no params at all, so as currently typed it
  can only mean "the group has no target(s) left," not "this one target was cleared but others
  remain" - that'd need a new delegate type to express per-actor loss for `MultiTarget` groups.
- **No proximity/candidate-count culling.** `GetTargetsForContext` returns every
  `UDMVTargetComponent` ever registered under that tag - there's no spatial partitioning or range
  cap before candidates reach the Filters. Fine at small scale; worth revisiting (e.g. a spatial
  query before filtering) if a context ever accumulates a lot of simultaneously-registered
  targets.
- **`MultiTarget` has no built-in cap** (by design, see [Selection modes](#selection-modes-enumberoftargets)
  above) - if you need a bounded count, build it into a Filter.
- **`UDMVTargetFilter_Data` is unused** - see [Filters](#filters) above.
- **Filters are instantiated fresh via `NewObject` every tick**, and scan-based filters spawn+
  destroy an actor per candidate per call - both fine at today's scale (nothing uses this plugin
  yet), worth profiling once a real consumer with many concurrent groups/candidates exists.

## Recent history

This plugin had a few latent bugs and some dead code cleaned up alongside implementing
`MultiTarget` (previously an unimplemented stub):

- `AnalyseTargetGroups`'s no-candidates branch used `return` instead of `continue`, so one Target
  Group with zero candidates on a given tick would silently abort evaluation of every group after
  it in `ActiveTargetGroups` for that tick. Fixed.
- `RemoveTargetEvaluationContext` never actually removed anything from `ActiveTargetGroups` - it
  cleared the group's current target and stopped there, so a "removed" group kept being evaluated
  forever. Fixed.
- Dead code removed: the unused `FCandidate` struct, an unused static `LineOfSightSphereShape`,
  and an unused `CurrentTargetEvaluationRange` field whose doc comment described a "single sphere
  check sourcing every context's candidates" optimization that was never actually implemented
  (`GetTargetsForContext` has no spatial query at all today - see
  [Known gaps](#known-gaps--open-design-questions) above if that's worth reviving).
- `UTargetGroup`'s `UCLASS()` carried metadata copy-pasted from an `ActorComponent`
  (`ClassGroup=(Custom), meta=(BlueprintSpawnableComponent)`) despite being a plain `UObject`, and
  was missing `BlueprintType` despite being returned from a `BlueprintCallable` function with
  `BlueprintReadWrite` properties. Fixed to `UCLASS(BlueprintType)`.
- `FFilteringFinished`'s delegate param was named `Targets` (plural) for a singular
  `UDMVTargetComponent*` - renamed to `Target` to match how it's actually broadcast (once per
  surviving candidate, not once with a list).
