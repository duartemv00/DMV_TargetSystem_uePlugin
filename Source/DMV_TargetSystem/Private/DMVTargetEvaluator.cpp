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

	if (const UGameInstance* GameInstance = GetOwner()->GetGameInstance())
	{
		PlayerAutoTargetManagerSubsystem = GameInstance->GetSubsystem<UDMVTargetSubsystem>();
	}

	CachedPlayerController = Cast<APlayerController>(GetOwner());

	// Add initial evaluation contexts
	for (UXM_TargetEvaluationContext* TargetEvaluationContext : InitialTargetEvaluationContexts)
	{
		AddTargetEvaluationContext_Internal(TargetEvaluationContext);
	}
	
}

void UDMVTargetEvaluator::UpdateInterset(
	TMap<TObjectPtr<UDMVTargetComponent>, UXM_TargetEvaluationContext*>& FinalistsPerSubcontext,
	FVector PlayerViewLocation,
	FVector PlayerViewDirection)
{
	// Update Interest - Cone Angle
	if (bUpdateInterestByConeAngle)
	{
		float ClosestAngle = MaxAngleToGainInterest;
		for (TPair Finalist : FinalistsPerSubcontext)
		{
			TObjectPtr<UDMVTargetComponent> Candidate_Target = Finalist.Key;
			if (!IsValid(Candidate_Target)) continue;
			
			const FVector TargetLocation = Candidate_Target->GetComponentLocation();				
			const FVector DistanceToTarget = TargetLocation - PlayerViewLocation;
			const FVector DirectionToTarget = DistanceToTarget.GetSafeNormal();
			const float DotProduct = UKismetMathLibrary::Dot_VectorVector(PlayerViewDirection, DirectionToTarget);
			const float FinalistTargetAngle = UKismetMathLibrary::DegAcos(DotProduct);
				
			if (FinalistTargetAngle < MaxAngleToGainInterest && FinalistTargetAngle < ClosestAngle)
			{
				Candidate_Target->Interest = UKismetMathLibrary::Clamp(
					Candidate_Target->Interest + InterestWinInAngle, Candidate_Target->BaseInterest, 100);
				ClosestAngle = FinalistTargetAngle;
			} else
			{
				Candidate_Target->Interest = UKismetMathLibrary::Clamp(
					Candidate_Target->Interest - InterestLoseOutAngle, Candidate_Target->BaseInterest, 100);
			}
		}
	}

	if (bUpdateInterestByDistance) {
		float ClosestDistance = MaxDistanceToGainInterest;
		for (TPair Finalist : FinalistsPerSubcontext)
		{
			TObjectPtr<UDMVTargetComponent> Candidate_Target = Finalist.Key;
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

	// Check if the TargetManagerSubsystem exist
	if (!PlayerAutoTargetManagerSubsystem.IsValid())
	{
		ClearAllCurrentTargets();
		return;
	}

	// Check if the Player Controller exists
	if (!CachedPlayerController.IsValid())
	{
		ClearAllCurrentTargets();
		return;
	}

	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;
	CachedPlayerController->GetPlayerViewPoint(PlayerViewLocation, PlayerViewRotation);
	const FVector PlayerViewDirection = PlayerViewRotation.Quaternion() * FVector::ForwardVector;

	if (ActiveTargetEvaluationContextsMap.Num() <= 0) return;

	/** LOOP CONTEXT */
	for (const TPair<FGameplayTag, FEvaluationContexts>& Context : ActiveTargetEvaluationContextsMap)
	{
		FGameplayTag ContextIdentifier = Context.Key;
		const auto& Subcontexts = Context.Value.TargetEvaluationContexts;
		
		TMap<TObjectPtr<UDMVTargetComponent>, UXM_TargetEvaluationContext*> FinalistsPerSubcontext;
		FinalistsPerSubcontext.Empty();
		
		// Look at all subcategories and decide which is the best target for each of them.
		for (const auto& Subcontext : Subcontexts)
		{
			UXM_TargetEvaluationContext* TargetEvaluationContext = Subcontext.Value;
			FGameplayTagContainer SubcontextIndentifier;
			SubcontextIndentifier.AddTag(Subcontext.Key);
			
			TArray<UDMVTargetComponent*> SubcontextTargetCandidates;
			for (const TWeakObjectPtr<UDMVTargetComponent> Target :
				PlayerAutoTargetManagerSubsystem->GetTargetsForContext(TargetEvaluationContext->ContextIdentifier))
			{
				SubcontextTargetCandidates.AddUnique(Target.Get());
			}

			/** FILTERS */
			TArray<UDMVTargetFilter_Base*> FiltersForThisSubContext;
			FiltersForThisSubContext.Empty();
			// Get the correct filters for the subcontext
			for (auto& SubcontextFilterList : Filters)
			{
				if (SubcontextIndentifier.HasAnyExact(SubcontextFilterList.SubContextId))
				{
					for (auto& [Threshold, OutputNumber, FilterClass] : SubcontextFilterList.FiltersForSubcontext)
					{
						UDMVTargetFilter_Base* NewFilter = NewObject<UDMVTargetFilter_Base>(GetTransientPackage(), FilterClass);
						NewFilter->Initialize(Threshold);
						FiltersForThisSubContext.AddUnique(NewFilter);
					}
				}
			}
			// Apply filters
			for (auto& Filter : FiltersForThisSubContext)
			{
				SubcontextTargetCandidates = Filter->PerformFilter(SubcontextTargetCandidates, CachedPlayerController.Get());
			}
			for (auto& Candidate : SubcontextTargetCandidates)
			{
				TargetEvaluationContext->OnFilteringFinished.ExecuteIfBound(Candidate);
			}
			
			/** Is there some candidate for the current subcontext? */
			if (SubcontextTargetCandidates.Num() > 0)
			{
				// Only store the number one
				FinalistsPerSubcontext.FindOrAdd(SubcontextTargetCandidates[0]);
				FinalistsPerSubcontext[SubcontextTargetCandidates[0]] = TargetEvaluationContext;
			}
		}

		/** INTEREST */
		UpdateInterset(FinalistsPerSubcontext, PlayerViewLocation, PlayerViewDirection);
		/** Find subcontext finalist with the biggest interest value */
		TObjectPtr<UDMVTargetComponent> FinalTarget = nullptr;
		UXM_TargetEvaluationContext* FinalSubContext = nullptr;
		float HighestInterest = 0.f;
		for (TPair Finalist : FinalistsPerSubcontext)
		{
			TObjectPtr<UDMVTargetComponent> Candidate_Target = Finalist.Key;
			UXM_TargetEvaluationContext* Candidate_SubContext = Finalist.Value;
			if (!IsValid(Candidate_Target)) continue;

			if (Candidate_Target->Interest >= HighestInterest)
			{
				HighestInterest = Candidate_Target->Interest;
				FinalTarget = Candidate_Target;
				FinalSubContext = Candidate_SubContext;
			}
		}

		/** */
		if (FinalTarget != nullptr)
		{
			FTargetInputContext InputContext;
			InputContext.TargetComponent = FinalTarget;
			InputContext.TargetActor = FinalTarget->GetOwner();
			
			SetCurrentTarget(ContextIdentifier, FinalTarget);
			FinalSubContext->OnValidTargetFound.ExecuteIfBound(FinalTarget->GetOwner());
		} else
		{
			ClearCurrentTarget(ContextIdentifier);
			for (TPair aakjfbahf : FinalistsPerSubcontext){
				aakjfbahf.Value->OnTargetCleared.ExecuteIfBound();
			}
		}
		
	}
}

UXM_TargetEvaluationContext* UDMVTargetEvaluator::AddTargetEvaluationContext(
	const FGameplayTag& ParentContext,
	const FGameplayTag& ContextIdentifier,
	TArray<FFilterInformation> FiltersForTheContext,
	FValidPlayerAutoTargetFound OnValidTargetFound,
	FPlayerAutoTargetsCleared OnTargetCleared,
	FFilteringFinished OnFilteringFinished
	)
{
	UXM_TargetEvaluationContext* NewTargetEvaluationContext = NewObject<UXM_TargetEvaluationContext>(this);
	// Configure the Evaluation Context
	NewTargetEvaluationContext->ContextIdentifier = ContextIdentifier;
	NewTargetEvaluationContext->ParentContextIdentifier = ParentContext;
	NewTargetEvaluationContext->OnValidTargetFound = OnValidTargetFound;
	NewTargetEvaluationContext->OnTargetCleared = OnTargetCleared;
	NewTargetEvaluationContext->OnFilteringFinished = OnFilteringFinished;

	// Add filters related with the context
	bool bContextAlreadyHasFilters = false;	
	for (auto& FilterGroup : Filters)
	{
		if (FilterGroup.SubContextId.HasTag(ContextIdentifier))
		{
			bContextAlreadyHasFilters = true;
			// If the filter exists somewhere we add the filters
			for (auto& NewFilter : FiltersForTheContext)
			{
				FilterGroup.FiltersForSubcontext.AddUnique(NewFilter);
			}
		}
	}
	if (!bContextAlreadyHasFilters)
	{
		FEvaluationFilters NewEvaluationFilters;
		NewEvaluationFilters.SubContextId.AddTag(ContextIdentifier);
		NewEvaluationFilters.FiltersForSubcontext = FiltersForTheContext;
		Filters.Add(NewEvaluationFilters);
	}
	
	const bool bSuccess = AddTargetEvaluationContext_Internal(NewTargetEvaluationContext);
	return bSuccess ? NewTargetEvaluationContext : nullptr;
}

void UDMVTargetEvaluator::RemoveTargetEvaluationContext(const FGameplayTag& ContextIdentifier)
{
	for (TPair ParentContext : ActiveTargetEvaluationContextsMap) // TMap<FGameplayTag, FEvaluationContexts> 
	{
		if (ParentContext.Value.TargetEvaluationContexts.Contains(ContextIdentifier))
		{
			const UXM_TargetEvaluationContext* RemovedContext =
				ParentContext.Value.TargetEvaluationContexts.FindAndRemoveChecked(ContextIdentifier);
			
			// Remove the current target storage for the context just to keep the map clean.
			ClearCurrentTarget(ContextIdentifier); //!!!!!!!!!!!
		}
		else
		{
			UE_LOG(LogPlayerTargetEval, Warning, TEXT("No target evaluation context with identifier %s found to remove."),
				*ContextIdentifier.ToString());
		}
	}
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
	const TWeakObjectPtr<UDMVTargetComponent>* CurrentTarget;
	CurrentTarget =	CurrentTargetsMap.Find(ContextIdentifier);

	return CurrentTarget != nullptr ? CurrentTarget->Get() : nullptr;
}

void UDMVTargetEvaluator::SetCurrentTarget(const FGameplayTag& ContextIdentifier, UDMVTargetComponent* Target)
{
	if (Target == nullptr)
	{
		UE_LOG(LogPlayerTargetEval, Warning, TEXT("Tried to pass a null target into SetCurrentTarget;"
										  " use ClearCurrentTarget instead if you want to remove the current target."));
		ClearCurrentTarget(ContextIdentifier);
		return;
	}

	const TWeakObjectPtr<UDMVTargetComponent>* PrevTargetPtrPtr = CurrentTargetsMap.Find(ContextIdentifier);
	const UDMVTargetComponent* PrevTarget = PrevTargetPtrPtr != nullptr ? PrevTargetPtrPtr->Get() : nullptr;
	
	CurrentTargetsMap.Add(ContextIdentifier, TWeakObjectPtr(Target));
	
	UE_LOG(LogTemp, Warning, TEXT("New target of %s: %s"), *ContextIdentifier.ToString(), *Target->GetOwner()->GetName());
}

void UDMVTargetEvaluator::ClearCurrentTarget(const FGameplayTag& ContextIdentifier)
{

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

bool UDMVTargetEvaluator::AddTargetEvaluationContext_Internal(UXM_TargetEvaluationContext* TargetEvaluationContext)
{
	if (ActiveTargetEvaluationContextsMap.Find(TargetEvaluationContext->ParentContextIdentifier))
	{
		FEvaluationContexts* ListOfSubcontextInsideTheContext = ActiveTargetEvaluationContextsMap.Find(TargetEvaluationContext->ParentContextIdentifier);
		ListOfSubcontextInsideTheContext->TargetEvaluationContexts.Add(TargetEvaluationContext->ContextIdentifier, TargetEvaluationContext);
		if (ListOfSubcontextInsideTheContext->TargetEvaluationContexts.Find(TargetEvaluationContext->ContextIdentifier))
		{
			return false;
		}
		return true;
	}
	FEvaluationContexts NewEvaluationContextsEntry;
	NewEvaluationContextsEntry.TargetEvaluationContexts.Add(TargetEvaluationContext->ContextIdentifier, TargetEvaluationContext);
	ActiveTargetEvaluationContextsMap.Add(TargetEvaluationContext->ParentContextIdentifier, NewEvaluationContextsEntry);
	
	return true;
}

