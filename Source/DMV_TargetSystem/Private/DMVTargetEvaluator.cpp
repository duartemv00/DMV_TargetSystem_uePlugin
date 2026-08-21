// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/DMVTargetEvaluator.h"
#include "../Public/Filters/DMVTargetFilter_Base.h"
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
				Candidate_Target->Interest = UKismetMathLibrary::Clamp(
					Candidate_Target->Interest + InterestWinWhileInAngle, Candidate_Target->BaseInterest, 100);
				ClosestAngle = FinalistTargetAngle;
			} else
			{
				Candidate_Target->Interest = UKismetMathLibrary::Clamp(
					Candidate_Target->Interest - InterestLostWhileOutAngle, Candidate_Target->BaseInterest, 100);
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
				Candidate_Target->Interest = UKismetMathLibrary::Clamp(
					Candidate_Target->Interest + InterestWinInDistance, Candidate_Target->BaseInterest, 100);
				ClosestDistance = DistanceToTarget;
			} else
			{
				Candidate_Target->Interest = UKismetMathLibrary::Clamp(
					Candidate_Target->Interest - InterestLoseOutDistance, Candidate_Target->BaseInterest, 100);
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
		
		// Create & fill list of candidates target components
		TArray<UDMVTargetComponent*> CandidatesTargetComponents; CandidatesTargetComponents.Empty();
		for (const TWeakObjectPtr<UDMVTargetComponent> TargetComponent :
			PlayerAutoTargetManagerSubsystem->GetTargetsForContext(TargetGroupToEvaluate->TargetGroupID))
		{
			CandidatesTargetComponents.AddUnique(TargetComponent.Get());
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
					if (Candidate->Interest >= HighestInterest)
					{
						HighestInterest = Candidate->Interest;
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
	
	// Gather filters (create them from the class reference)
	TArray<UDMVTargetFilter_Base*> FiltersForThisTargetGroup;
	for (auto& Filter : TargetGroupToEvaluate->Filters)
	{
		UDMVTargetFilter_Base* NewFilter = 
			NewObject<UDMVTargetFilter_Base>(GetTransientPackage(), Filter.FilterClass);
		NewFilter->Initialize(Filter.Value);
		FiltersForThisTargetGroup.AddUnique(NewFilter);
	}
	// Apply filters
	for (auto& Filter : FiltersForThisTargetGroup)
	{
		CandidatesTargetComponents = Filter->PerformFilter(CandidatesTargetComponents,
			CachedPlayerController.Get());
	}
	// After applying filters call the delegate
	for (auto& CandidateTargetComponent : CandidatesTargetComponents)
	{
		TargetGroupToEvaluate->OnFilteringFinished.ExecuteIfBound(CandidateTargetComponent);
	}
}

UTargetGroup* UDMVTargetEvaluator::AddTargetEvaluationContext(
	const FGameplayTag& TargetGroupID,
	TArray<FFilterInformation> FiltersForTheContext,
	FValidPlayerAutoTargetFound OnValidTargetFound,
	FPlayerAutoTargetsCleared OnTargetCleared,
	FFilteringFinished OnFilteringFinished
	)
{
	UTargetGroup* NewTargetEvaluationContext = NewObject<UTargetGroup>(this);
	// ID
	NewTargetEvaluationContext->TargetGroupID = TargetGroupID;
	// Delegates
	NewTargetEvaluationContext->OnValidTargetFound = OnValidTargetFound;
	NewTargetEvaluationContext->OnTargetCleared = OnTargetCleared;
	NewTargetEvaluationContext->OnFilteringFinished = OnFilteringFinished;
	// Filters
	NewTargetEvaluationContext->Filters = FiltersForTheContext;
	
	const bool bSuccess = AddTargetEvaluationContext_Internal(NewTargetEvaluationContext);
	return bSuccess ? NewTargetEvaluationContext : nullptr;
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

	CurrentTargetsMap.Add(ContextIdentifier, MoveTemp(WeakTargets));

	UE_LOG(LogTemp, Warning, TEXT("New target(s) of %s: %d"), *ContextIdentifier.ToString(), Targets.Num());
}

void UDMVTargetEvaluator::ClearCurrentTarget(const FGameplayTag& ContextIdentifier)
{
	CurrentTargetsMap.Remove(ContextIdentifier);
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

