// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/DMV_TargetEvaluator.h"
#include "../Public/Filters/DMV_TargetFilter_Base.h"
#include "../Public/Filters/DMV_TargetFilter_Data.h"
#include "Kismet/KismetMathLibrary.h"


UDMVTargetEvaluator::UDMVTargetEvaluator()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bHighPriority = true;
}


void UDMVTargetEvaluator::BeginPlay()
{
	Super::BeginPlay();

	CachedPlayerController = Cast<APlayerController>(GetOwner());

	// Targeting is a per-viewer, cosmetic-only concern (used to drive local UI/reticle feedback).
	// Only the owning client needs the result, so remote proxies of other players' controllers -
	// and the server, for a client-owned controller - must not run this every tick.
	if (!CachedPlayerController.IsValid() || !CachedPlayerController->IsLocalController())
	{
		SetComponentTickEnabled(false);
		return;
	}

	if (const UGameInstance* GameInstance = GetOwner()->GetGameInstance())
	{
		PlayerAutoTargetManagerSubsystem = GameInstance->GetSubsystem<UDMVTargetSubsystem>();
	}
}

void UDMVTargetEvaluator::UpdateInterest(
	TArray<UDMVTargetComponent*>& Finalists,
	FVector PlayerViewLocation,
	FVector PlayerViewDirection)
{
	// Update Interest - Cone Angle
	if (bUpdateInterestByConeAngle)
	{
		float ClosestAngle = MaxAngleToGainInterest;
		for (UDMVTargetComponent* Finalist : Finalists)
		{
			TObjectPtr<UDMVTargetComponent> Candidate_Target = Finalist;
			if (!IsValid(Candidate_Target)) continue;
			
			const FVector TargetLocation = Candidate_Target->GetComponentLocation();				
			const FVector DistanceToTarget = TargetLocation - PlayerViewLocation;
			const FVector DirectionToTarget = DistanceToTarget.GetSafeNormal();
			const float DotProduct = UKismetMathLibrary::Dot_VectorVector(PlayerViewDirection, DirectionToTarget);
			const float FinalistTargetAngle = UKismetMathLibrary::DegAcos(DotProduct);
				
			if (FinalistTargetAngle < MaxAngleToGainInterest && FinalistTargetAngle < ClosestAngle)
			{
				Candidate_Target->SetInterest(UKismetMathLibrary::Clamp(
					Candidate_Target->GetInterest() + InterestWinWhileInAngle, Candidate_Target->BaseInterest, 100));
				ClosestAngle = FinalistTargetAngle;
			} else
			{
				Candidate_Target->SetInterest(UKismetMathLibrary::Clamp(
					Candidate_Target->GetInterest() - InterestLostWhileOutAngle, Candidate_Target->BaseInterest, 100));
			}
		}
	}

	// Update Interest - Distance
	if (bUpdateInterestByDistance) {
		float ClosestDistance = MaxDistanceToGainInterest;
		for (UDMVTargetComponent* Finalist : Finalists)
		{
			TObjectPtr<UDMVTargetComponent> Candidate_Target = Finalist;
			if (!IsValid(Candidate_Target)) continue;
			
			const FVector TargetLocation = Candidate_Target->GetComponentLocation();				
			const FVector DistanceToTarget_vector = TargetLocation - PlayerViewLocation;
			const float DistanceToTarget = UKismetMathLibrary::Abs(DistanceToTarget_vector.Size());
				
			if (DistanceToTarget < MaxDistanceToGainInterest && DistanceToTarget < ClosestDistance)
			{
				Candidate_Target->SetInterest(UKismetMathLibrary::Clamp(
					Candidate_Target->GetInterest() + InterestWinInDistance, Candidate_Target->BaseInterest, 100));
				ClosestDistance = DistanceToTarget;
			} else
			{
				Candidate_Target->SetInterest(UKismetMathLibrary::Clamp(
					Candidate_Target->GetInterest() - InterestLoseOutDistance, Candidate_Target->BaseInterest, 100));
			}
		}
	}
}

void UDMVTargetEvaluator::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!CachedPlayerController.IsValid() || !CachedPlayerController->IsLocalController())
	{
		SetComponentTickEnabled(false);
		return;
	}

	AnalyseTargetGroups();
}

void UDMVTargetEvaluator::AnalyseTargetGroups()
{
	if (!PlayerAutoTargetManagerSubsystem.IsValid())
	{ClearAllCurrentTargets(); return;}
	if (!CachedPlayerController.IsValid())
	{ClearAllCurrentTargets(); return;}
	
	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;
	CachedPlayerController->GetPlayerViewPoint(PlayerViewLocation, PlayerViewRotation);
	const FVector PlayerViewDirection = PlayerViewRotation.Quaternion() * FVector::ForwardVector;

	if (ActiveTargetGroups.Num() <= 0) return;

	////////////////////////////////////////////////////////////////////////////////////////////////
	/** Loop TARGET GROUPS */
	for (const UTargetGroup* TargetGroupToEvaluate : ActiveTargetGroups)
	{
		FGameplayTag TargetGroupIdentifier = TargetGroupToEvaluate->TargetGroupID;
		
		// Create & fill list of candidates target components. A positive MaxCullDistance culls via
		// the subsystem's spatial grid before Filters ever run; <= 0 (the default) fetches every
		// target registered under this tag, same as before MaxCullDistance existed.
		TArray<UDMVTargetComponent*> CandidatesTargetComponents;
		for (const TWeakObjectPtr<UDMVTargetComponent>& TargetComponent :
			PlayerAutoTargetManagerSubsystem->GetTargetsForContext(
				TargetGroupToEvaluate->TargetGroupID, PlayerViewLocation, TargetGroupToEvaluate->MaxCullDistance))
		{
			CandidatesTargetComponents.Add(TargetComponent.Get());
		}
		
		ApplyFiltersToCandidates(TargetGroupToEvaluate, CandidatesTargetComponents);

		// Decide final target or targets
		if (CandidatesTargetComponents.Num() <= 0)
		{
			ClearCurrentTarget(TargetGroupIdentifier);
			continue;
		}

		if (TargetGroupToEvaluate->NumberOfTargets == ENumberOfTargets::MultiTarget)
		{
			// Every candidate that survived the Filters array becomes a target - no separate cap.
			SetCurrentTargets(TargetGroupIdentifier, CandidatesTargetComponents);
			continue;
		}

		float HighestInterest = 0.f;
		TObjectPtr<UDMVTargetComponent> SelectedTargetComponent = nullptr;
		switch (TargetGroupToEvaluate->NumberOfTargets)
		{
			case ENumberOfTargets::SingleTarget:
				SelectedTargetComponent = CandidatesTargetComponents[0];
				break;

			case ENumberOfTargets::SingleTargetUseInterest:
				UpdateInterest(CandidatesTargetComponents, PlayerViewLocation, PlayerViewDirection);
				for (UDMVTargetComponent* Candidate : CandidatesTargetComponents)
				{
					if (Candidate->GetInterest() >= HighestInterest)
					{
						HighestInterest = Candidate->GetInterest();
						SelectedTargetComponent = Candidate;
					}
				}
				break;

			default:
				break;
		}
		SetCurrentTarget(TargetGroupIdentifier, SelectedTargetComponent);
	}
}

void UDMVTargetEvaluator::ApplyFiltersToCandidates(const UTargetGroup* TargetGroupToEvaluate, TArray<UDMVTargetComponent*>& CandidatesTargetComponents)
{
	if (TargetGroupToEvaluate->Filters.IsEmpty()) return;

	// Each filter is already a pre-configured instance owned by this TargetGroup (see
	// AddTargetEvaluationContext) - no per-tick construction needed, just run them in order.
	for (UDMVTargetFilter_Base* Filter : TargetGroupToEvaluate->Filters)
	{
		if (!IsValid(Filter)) continue;

		// Fresh, empty every call - a filter's Blueprint override cannot carry stale results over
		// from a previous call the way a returned array could if it reused a persistent variable.
		TArray<UDMVTargetComponent*> FilteredResult;
		Filter->PerformFilter(CandidatesTargetComponents, CachedPlayerController.Get(), FilteredResult);
		CandidatesTargetComponents = MoveTemp(FilteredResult);
	}
	// After applying filters call the delegate
	for (auto& CandidateTargetComponent : CandidatesTargetComponents)
	{
		TargetGroupToEvaluate->OnFilteringFinished.ExecuteIfBound(CandidateTargetComponent);
	}
}

UTargetGroup* UDMVTargetEvaluator::AddTargetEvaluationContext(
	const FGameplayTag& TargetGroupID,
	const TArray<UDMVTargetFilter_Base*>& FiltersForTheContext,
	ENumberOfTargets NumberOfTargets,
	FValidPlayerAutoTargetFound OnValidTargetFound,
	FPlayerAutoTargetsCleared OnTargetCleared,
	FFilteringFinished OnFilteringFinished,
	float MaxCullDistance
	)
{
	UTargetGroup* NewTargetEvaluationContext = NewObject<UTargetGroup>(this);
	// ID
	NewTargetEvaluationContext->TargetGroupID = TargetGroupID;
	// Selection mode
	NewTargetEvaluationContext->NumberOfTargets = NumberOfTargets;
	// Proximity cull
	NewTargetEvaluationContext->MaxCullDistance = MaxCullDistance;
	// Delegates
	NewTargetEvaluationContext->OnValidTargetFound = OnValidTargetFound;
	NewTargetEvaluationContext->OnTargetCleared = OnTargetCleared;
	NewTargetEvaluationContext->OnFilteringFinished = OnFilteringFinished;

	// Duplicate each filter into a private, independently-owned copy so the caller's source
	// instances (e.g. from a shared UDMVTargetFilter_Data asset) are never mutated or shared
	// across TargetGroups - each usage gets its own per-instance-tunable properties.
	NewTargetEvaluationContext->Filters.Reserve(FiltersForTheContext.Num());
	for (UDMVTargetFilter_Base* SourceFilter : FiltersForTheContext)
	{
		if (IsValid(SourceFilter))
		{
			NewTargetEvaluationContext->Filters.Add(
				DuplicateObject<UDMVTargetFilter_Base>(SourceFilter, NewTargetEvaluationContext));
		}
	}

	const bool bSuccess = AddTargetEvaluationContext_Internal(NewTargetEvaluationContext);
	return bSuccess ? NewTargetEvaluationContext : nullptr;
}

UTargetGroup* UDMVTargetEvaluator::AddTargetEvaluationContextFromData(
	const FGameplayTag& TargetGroupID,
	UDMVTargetFilter_Data* FilterData,
	ENumberOfTargets NumberOfTargets,
	FValidPlayerAutoTargetFound OnValidTargetFound,
	FPlayerAutoTargetsCleared OnTargetCleared,
	FFilteringFinished OnFilteringFinished,
	float MaxCullDistance
	)
{
	return AddTargetEvaluationContext(
		TargetGroupID,
		IsValid(FilterData) ? FilterData->FilterList : TArray<UDMVTargetFilter_Base*>(),
		NumberOfTargets,
		OnValidTargetFound,
		OnTargetCleared,
		OnFilteringFinished,
		MaxCullDistance);
}

void UDMVTargetEvaluator::RemoveTargetEvaluationContext(const FGameplayTag& ContextIdentifier)
{
	ClearCurrentTarget(ContextIdentifier);

	ActiveTargetGroups.RemoveAll([&ContextIdentifier](const UTargetGroup* TargetGroup)
	{
		return TargetGroup->TargetGroupID == ContextIdentifier;
	});
}

AActor* UDMVTargetEvaluator::GetCurrentTarget(const FGameplayTag& ContextIdentifier) const
{
	if (const UDMVTargetComponent* CurrentTarget = GetCurrentTargetComponent(ContextIdentifier))
	{
		return CurrentTarget->GetOwner();
	}
	return nullptr;
}

UDMVTargetComponent* UDMVTargetEvaluator::GetCurrentTargetComponent(const FGameplayTag& ContextIdentifier) const
{
	const TArray<TWeakObjectPtr<UDMVTargetComponent>>* CurrentTargets = CurrentTargetsMap.Find(ContextIdentifier);
	return (CurrentTargets != nullptr && CurrentTargets->Num() > 0) ? (*CurrentTargets)[0].Get() : nullptr;
}

TArray<AActor*> UDMVTargetEvaluator::GetCurrentTargets(const FGameplayTag& ContextIdentifier) const
{
	TArray<AActor*> Result;
	for (UDMVTargetComponent* Target : GetCurrentTargetComponents(ContextIdentifier))
	{
		Result.Add(Target->GetOwner());
	}
	return Result;
}

TArray<UDMVTargetComponent*> UDMVTargetEvaluator::GetCurrentTargetComponents(const FGameplayTag& ContextIdentifier) const
{
	TArray<UDMVTargetComponent*> Result;
	if (const TArray<TWeakObjectPtr<UDMVTargetComponent>>* CurrentTargets = CurrentTargetsMap.Find(ContextIdentifier))
	{
		Result.Reserve(CurrentTargets->Num());
		for (const TWeakObjectPtr<UDMVTargetComponent>& WeakTarget : *CurrentTargets)
		{
			if (UDMVTargetComponent* Target = WeakTarget.Get())
			{
				Result.Add(Target);
			}
		}
	}
	return Result;
}

void UDMVTargetEvaluator::SetCurrentTarget(const FGameplayTag& ContextIdentifier, UDMVTargetComponent* Target)
{
	if (Target == nullptr)
	{
		ClearCurrentTarget(ContextIdentifier);
		return;
	}

	SetCurrentTargets(ContextIdentifier, TArray<UDMVTargetComponent*>{Target});
}

void UDMVTargetEvaluator::SetCurrentTargets(const FGameplayTag& ContextIdentifier, const TArray<UDMVTargetComponent*>& Targets)
{
	TArray<TWeakObjectPtr<UDMVTargetComponent>> WeakTargets;
	WeakTargets.Reserve(Targets.Num());
	for (UDMVTargetComponent* Target : Targets)
	{
		if (IsValid(Target))
		{
			WeakTargets.Add(Target);
		}
	}

	if (WeakTargets.IsEmpty())
	{
		ClearCurrentTarget(ContextIdentifier);
		return;
	}

	// Only broadcast OnValidTargetFound for actors that weren't already this context's target -
	// otherwise it'd fire every tick a group simply re-confirms the same target(s).
	if (const UTargetGroup* TargetGroup = FindActiveTargetGroup(ContextIdentifier))
	{
		const TArray<TWeakObjectPtr<UDMVTargetComponent>>* PreviousTargets = CurrentTargetsMap.Find(ContextIdentifier);
		for (const TWeakObjectPtr<UDMVTargetComponent>& WeakTarget : WeakTargets)
		{
			if (PreviousTargets && PreviousTargets->Contains(WeakTarget))
			{
				continue;
			}
			if (UDMVTargetComponent* Target = WeakTarget.Get())
			{
				TargetGroup->OnValidTargetFound.ExecuteIfBound(Target->GetOwner());
			}
		}
	}

	CurrentTargetsMap.Add(ContextIdentifier, MoveTemp(WeakTargets));

	// Verbose: this fires on every target change - potentially several times a second as the
	// highest-interest target flickers between candidates - so it can't be a Warning.
	UE_LOG(LogTemp, Verbose, TEXT("New target(s) of %s: %d"), *ContextIdentifier.ToString(), Targets.Num());
}

void UDMVTargetEvaluator::ClearCurrentTarget(const FGameplayTag& ContextIdentifier)
{
	// RemoveAndCopyValue only succeeds on the non-empty-to-empty transition, not every tick an
	// already-empty group gets cleared again - the map never stores an empty array (see
	// SetCurrentTargets), so a successful removal always means there's at least one actor to report.
	TArray<TWeakObjectPtr<UDMVTargetComponent>> RemovedTargets;
	if (!CurrentTargetsMap.RemoveAndCopyValue(ContextIdentifier, RemovedTargets))
	{
		return;
	}

	const UTargetGroup* TargetGroup = FindActiveTargetGroup(ContextIdentifier);
	if (!TargetGroup)
	{
		return;
	}

	// One broadcast per actor that was targeted, mirroring how OnValidTargetFound fires - a
	// listener reacting per-actor (e.g. clearing that actor's highlight) needs the reference.
	for (const TWeakObjectPtr<UDMVTargetComponent>& WeakTarget : RemovedTargets)
	{
		if (UDMVTargetComponent* Target = WeakTarget.Get())
		{
			TargetGroup->OnTargetCleared.ExecuteIfBound(Target->GetOwner());
		}
	}
}

void UDMVTargetEvaluator::ClearAllCurrentTargets()
{
	TArray<FGameplayTag> ActiveContextsWithTargets;
	CurrentTargetsMap.GetKeys(ActiveContextsWithTargets);
	for (const FGameplayTag& ContextIdentifier : ActiveContextsWithTargets)
	{
		ClearCurrentTarget(ContextIdentifier);
	}
}

bool UDMVTargetEvaluator::AddTargetEvaluationContext_Internal(UTargetGroup* TargetEvaluationContext)
{
	for (UTargetGroup* TargetGroup : ActiveTargetGroups)
	{
		if (TargetGroup->TargetGroupID == TargetEvaluationContext->TargetGroupID)
		{
			return false;
		}
	}
	ActiveTargetGroups.Add(TargetEvaluationContext);
	return true;
}

UTargetGroup* UDMVTargetEvaluator::FindActiveTargetGroup(const FGameplayTag& ContextIdentifier) const
{
	for (UTargetGroup* TargetGroup : ActiveTargetGroups)
	{
		if (IsValid(TargetGroup) && TargetGroup->TargetGroupID == ContextIdentifier)
		{
			return TargetGroup;
		}
	}
	return nullptr;
}

