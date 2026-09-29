# DMV_TargetSystem

## Design intent
**Gather actors in the world and categorize them by the use they will have in the game**. To categorize them, the system uses **filters**: "Find nearby candidates, filter them, pick one (or many)." The system's aim is not to have an specific functionality, but to **provide to other systems**. The system is centralized instead of shared, so the responsibility is easy to access and we don't need to re-implement the logic multiple times. It answers to **"Who is the current target for context X on this local player."** continuously, **every tick.**

## Selection modes 
### `ENumberOfTargets`
| Concept | Description |
|---|---|
| SingleTarget | Takes the first candidate that survives the Filters array, in whatever order the subsystem/filters left it. No tie-breaking logic. |
| SingleTargetUseInterest | Runs `UpdateInterest()` (angle- and/or distance-based scoring, toggled independently via `bUpdateInterestByConeAngle`/`bUpdateInterestByDistance`) over the candidates, then takes whichever has the highest `Interest`. Interest persists on the `UDMVTargetComponent` itself and decays continuously (a `0.01f` timer on the component, see `ResetInterest`), so a target that was recently "hot" stays slightly favored for a moment even if it briefly leaves the cone/range - a basic sticky-target behavior. |
| MultiTarget | Every candidate that survives the Filters array becomes a target. **No cap** - if you need to bound how many targets a group can have, do it in a Filter (e.g. a filter that sorts by distance/interest and truncates), not by expecting the evaluator to cap it. |

### Functions
| Functions | Use Case |
|---|---|
| GetCurrentTarget() / GetCurrentTargetComponent() | Always return the *first* current target for a group (works unmodified for `SingleTarget`/`SingleTargetUseInterest`, since they only ever store one).|
| GetCurrentTargets() / GetCurrentTargetComponents() | Return the full list, and are the ones to use with `MultiTarget` consumers.|

## Core concepts

| Concept | Class | Role |
|---|---|---|
| Target Component | `UDMVTargetComponent` | Attached to anything that should be targetable. Registers itself with the subsystem under one or more context tags. |
| Target Subsystem | `UDMVTargetSubsystem` | `UGameInstanceSubsystem`. The single global registry: context tag &rarr; currently-registered `UDMVTargetComponent`s. |
| Target Evaluator | `UDMVTargetEvaluator` | An `ActorComponent`, meant to live on a `PlayerController`. Every tick, re-evaluates every active Target Group and decides its current target(s). |
| Target Group | `UTargetGroup` | One "thing I want targeted": a context tag, a list of Filters, and a selection mode (`ENumberOfTargets`). Created by calling `AddTargetEvaluationContext`. |
| Filter | `UDMVTargetFilter_Base` (+ subclasses) | A candidate-list transform - narrows/reorders the raw candidate list for one Target Group. |
| Interest | `UDMVTargetComponent::Interest` | A per-target "hotness" score that rises while it's the closest candidate by angle/distance and decays otherwise. Only consulted by the `SingleTargetUseInterest` selection mode. |

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

## Local-only, not replicated
`UDMVTargetEvaluator` disables its own tick unless the owning `PlayerController` is `IsLocalController()`. 

Targeting is a per-viewer cosmetic concern, so what *this* player's screen should highlight/aim-assist toward. `CurrentTargetsMap` only ever exists client-side, one per local player. 

**Never use this system's answer to decide something that must be server-authoritative** (e.g. don't trust "the current target" to resolve hit/damage - the server must independently validate any hit).

## Target contexts
Target contexts are `FGameplayTag`s under the `ID.TargetGroup` category (enforced via `meta=(Categories="ID.TargetGroup")` on every tag-typed parameter/property in this plugin). 

The plugin itself only declares one placeholder, `ID.TargetGroup.Example` (`DMV_TargetingGameplayTags.h`), meant purely as an illustration for the tag picker, so consuming projects are expected to declare their own.

## Target Component - Visibility
`UDMVTargetComponent` exposes multi-point visibility sampling, meant for any line-of-sight-style
filter to use instead of tracing to a single point (see `BP_TargetFilter_LineOfSight` below).

**Why not just trace to `GetComponentLocation()`?** A single point is a coin flip against partial cover: if a wall happens to cover exactly where that point sits (e.g. a target's chest) but not the rest of the target, a single-point trace reports "not visible" even though the target is visible by an arm or head sticking out past the wall. 

Sampling several points spread across the target's actual extent and treating it as visible if **any** of them has a clear line of sight fixes that.

### `EDMVTargetVisibilityMode`
| Mode | Use Case |
|---|---|
| `Point` (default) | Unchanged behavior: a single point at `GetComponentLocation()`. No extra setup. |
| `ProxyCollision` | An explicit collision shape the actor author places and configures on the actor (e.g. a capsule roughly matching the body), referenced via `VisibilityProxy` (an `FComponentReference` - `UDMVTargetComponent` only points at it, doesn't spawn or own it). Best when the mesh's own collision is a poor fit for what "visible" should mean (way too tight/loose, or nonexistent). |
| `OwnerMeshCollision` | Reuses the actor's existing mesh collision automatically (`FindComponentByClass<UMeshComponent>()`), no extra shape needed. Set `VisibilityMeshOverride` only if the actor has more than one mesh component and auto-resolving would be ambiguous. |

### `GetVisibilityTracePoints()`
Returns the world-space points of the shape that is going to used to calculate visibility outside the owner:
- `Point` mode, or no visibility component resolves: just `{ GetComponentLocation() }` - a single element, so a filter written for the multi-point case needs no special-casing for this fallback.
- Otherwise: 7 points spread across the resolved component's bounds - center, top, bottom, left, right, front, back:

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

### Using visibility in a filter
1. Inside the Target Component, set the target's `VisibilityMode`.
2. In the filter's trace logic, call `GetVisibilityTracePoints()` on the candidate's `UDMVTargetComponent` instead of tracing to a single location.
3. Loop over the returned points, running a line trace from the viewer to each.

## Target Component - Interest
The interest works as a 'buffer' for what objects are being targeted, when there are multiple of them targeted at the same time. It is useful in fast paced games, when accidental changes of aim can easily happen, making the game frustrating. Increases the importance when multiple actions over multiple objects share a common input.

Interest is just a value that increase when the object is stored as valid target by the Target Evaluator. The value automatically decreases when the object is cleared from the evaluator component. Instead of just selecting the first element in the array of targets, the interest allows to compare all resulting targets and guess which of them is the one that really has the player's attention. 

IMPORTANT: The time that the interest takes to fall to the base value, should be smaller that the time a human hand moves and an input is pressed. If not, we fall into the opposite issue. 

## Target Evaluator - Filters
Filters are used to decided what candidates are really targets. Some examples of filters are: Line-of-sight (so if there is a wall in the middle is not a valid target), Distance, Class (so only objects of a certain class can be targets), etc.

Every filter is a `UDMVTargetFilter_Base` subclass (C++ or Blueprint) that implements `PerformFilter(PotentialTargets, PlayerController, OutFilteredTargets)` and (optionally) 

`OutFilteredTargets` is a fresh array that `ApplyFiltersToCandidates` constructs every call. Add surviving candidates to it instead of building and returning a separate array. The separate array can accidentally store stale data from previous executions, as the filter is an instance stored inside the context.

A `Filters` array holds the actual filter **instances**. Filters run in array order, so we can decide which is more important to do first. Each filter narrows or reorders the previous filter's output.

### Per-usage configuration
Filter instances are individually configured. Because `UDMVTargetFilter_Base` is `EditInlineNew`/`Blueprintable`, a Blueprint child can add its own properties, so each filter defines whatever comparison value(s) it actually needs.

`AddTargetEvaluationContext` takes `const TArray<UDMVTargetFilter_Base*>&`, pre-configured instances with whatever custom properties you set on it. Then **duplicates each one** (`DuplicateObject`) into the new `UTargetGroup`'s own ownership. That means:
- The same filter class can be used with different values on their properties in different Contexts and inside the same or different Controllers.
- The source instance you pass in is never mutated, as `AddTargetEvaluationContext` always works on a duplicate. So the same source instance or shared preset can safely be reused across multiple contexts/controllers without them stepping on each other.
- Filters don't need per-tick construction. `ApplyFiltersToCandidates` just runs the `UTargetGroup`'s already-owned instances.




### Convention: which properties should be per-usage tunable
When a filter instance is edited inline, the engine already only shows properties that aren't `EditDefaultsOnly`.
- **`EditAnywhere` (or `EditInstanceOnly`)** - Shows up on every per-usage instance, so use it for anything that's meant to vary per context. Use `EditInstanceOnly` only if the property should never have a class-level
  default at all.
- **`EditDefaultsOnly`** - Only editable on the filter *class*'s own Class Defaults, hidden from every per-usage instance.

**From a Blueprint filter subclass**, these C++ specifiers aren't directly on the variable creation UI, but they map onto standard Blueprint variable flags. For a new variable in the Blueprint's My
Blueprint panel:
1. Expose it at all - Make it **Editable**. An unexposed variable doesn't show in any Details panel, Class Defaults or per-instance
2. Once exposed, its Details tab has an **Instance Editable** checkbox:
   - **Checked** - per-usage tuneable. Use this for anything that a specific context should be able to retune.
   - **Unchecked** - Class Defaults only. Use this for anything fixed per filter class.
There's no Blueprint-variable equivalent of the narrower `EditInstanceOnly` (hidden from Class Defaults, visible only per-instance)

#### Footguns
- The base `PerformFilter_Implementation` leaves `OutFilteredTargets` empty. The base `SortCandidates_Implementation` returns an **empty array**. A `Filter` subclass that forgets to override `PerformFilter` doesn't act as a no-op/pass-through, but it silently excludes every candidate for that group.
- `SortCandidates` is declared (also `BlueprintNativeEvent`) but **the evaluator never calls it**, if a filter needs to sort, do it inside its own `PerformFilter`.

### Reusable presets: `UDMVTargetFilter_Data`
`UDMVTargetFilter_Data` (a `UDataAsset` holding an `Instanced` array of filters, `FilterList`) lets a designer author a reusable, individually-configured set of filters once as an asset, not buried in a `PlayerController` Blueprint graph, and reuse it across multiple contexts. Call `Evaluator->AddTargetEvaluationContextFromData()` instead of `Evaluator->AddTargetEvaluationContext()` to consume one directly. It duplicates `FilterData->FilterList` the same way the base function duplicates any other filter array

### Proximity culling
By default, every target registered under a context tag reaches that `UTargetGroup`'s Filters, every tick. This is fine at small scale, but every registered target then pays whatever cost the Filters chain has, even ones nowhere near the player. 

`AddTargetEvaluationContext`/`AddTargetEvaluationContextFromData`'s optional trailing `MaxCullDistance` parameter (default `0.f` that means no culling), drops a candidate before it ever reaches Filters if it's farther than that from the player's view location.

Culling isn't a plain per-candidate distance check, because that would still mean touching every registered target under the tag once per query. Instead `UDMVTargetSubsystem::GetTargetsForContext` maintains a spatial hash grid (`SpatialGridCellSize` default 500cm cells) over every registered target regardless of tag. 

A radius query only walks the grid cells overlapping the query sphere, then filters that set down by tag and exact distance, so the cost scales with how many targets are actually near the query point, not with how many are registered under the tag in total. 

Neither the grid nor its rebuild timer exist until the first caller actually passes `MaxCullDistance > 0.f`.

#### Tradeoff
Grid is regenerated periodically (`SpatialGridRebuildInterval` default `0.1f` seconds) rather than every tick. Since rebuilding it requires touching every registered target's current location, a moving target can be positionally stale by up to that interval before a query reflects its new cell.

#### Possible future option: physics-overlap-based proximity instead of a polling grid.** 
The grid still touches every registered target once per rebuild interval to find out where it currently is (no way to skip that within a polling design), since you can't know something is far away without ever checking its position. 

An alternative that avoids polling entirely: attach a large `USphereComponent` proximity trigger to each local player and let Unreal's physics broadphase (which already maintains its own optimized spatial structure) push `OnComponentBeginOverlap`/`OnComponentEndOverlap` events when a targetable actor's collision enters/exits range, instead of us scanning for it. 

The subsystem would maintain a per-player "currently nearby" set purely from those events, so zero cost for anything outside the sphere between crossings and no periodic scan at all.

Tradeoff: it requires every targetable actor to carry a collision component on a dedicated trace channel plus a sphere trigger per local player. And overlap events are binary, not a distance, so a `MaxCullDistance` style radius would still need a secondary distance check over the now much smaller overlapping set. Not worth building without evidence the polling grid is an actual bottleneck

## [TODO] Target Evaluator - Memory
Memory works as a buffer. Instead of clearing the current targeted actors immediately, it adds an small delay so the player can interact with some object even when that object is already outside of what the filters allow.

IMPORTANT: The window should take less time that what the eye takes to communicate the movement to the brain. If not, it can feel rigged.

## Integrating Targeting into a project
1. Add a `UDMVTargetEvaluator` component to your `PlayerController` Blueprint/class. It self-disables on every machine except the owning client, so it's safe to add unconditionally.
2. On anything that should be targetable, add a `UDMVTargetComponent` and set its `TargetContextIdentifiers` to the `ID.TargetGroup.*` tag(s) it should be findable under.
3. Wherever you want a target call `Evaluator->AddTargetEvaluationContext()` or `AddTargetEvaluationContextFromData()` once (e.g. on equip/activate) to register a `UTargetGroup`
   - Explicitly choosing Target Amount
   - Passing already-configured filter instances
   
   Keep the returned `UTargetGroup*` if you need to change `Filters` or `NumberOfTargets` later.
4. Poll `Evaluator->GetCurrentTarget()` or `GetCurrentTargets()` wherever you need the answer.
5. Call `Evaluator->RemoveTargetEvaluationContext()` when you're done with it (e.g. on unequip or ability end) so the evaluator stops evaluating a group nobody's reading anymore.

### Real use example
**Basic interaction**: Two separate contexts, registered independently, doing two different jobs off the same underlying actors:
- `ID.TargetGroup.CanInteract`, mode `MultiTarget` - Every interactable actor within range/filter criteria, all at once. This is what UI reads to decide *which actors currently show an interact prompt*. There can legitimately be several at once (e.g. two pickups near each other).
- `ID.TargetGroup.Interact`, mode `SingleTarget` or `SingleTargetUseInterest` - The *one* actor that would actually be interacted with if the player pressed the input right now. This is what the interact action itself resolves against.

Both contexts can watch the same `UDMVTargetComponent`s (an interactable actor would carry both `ID.TargetGroup.CanInteract` and `ID.TargetGroup.Interact` in its `TargetContextIdentifiers`). They are independent `UTargetGroup`s evaluated separately, each with its own selection mode and its own Filters. The same pattern generalizes beyond interaction.

A lock-on reticle context (MultiTarget, feeds which enemies show a lock-on icon) alongside an active-lock context (SingleTargetUseInterest, feeds which one enemy a homing ability actually fires at.
