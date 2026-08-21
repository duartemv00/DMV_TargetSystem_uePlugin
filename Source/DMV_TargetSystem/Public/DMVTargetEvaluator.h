// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DMVTargetSubsystem.h"
#include "Components/ActorComponent.h"
#include "Filters/DMVTargetFilter_Base.h"
#include "DMVTargetEvaluator.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FFilteringFinished, UDMVTargetComponent*, Target);
DECLARE_DYNAMIC_DELEGATE_OneParam(FValidPlayerAutoTargetFound, AActor*, Actor);
DECLARE_DYNAMIC_DELEGATE(FPlayerAutoTargetsCleared);

UENUM(BlueprintType)
enum class ENumberOfTargets : uint8
{
	SingleTarget,
	SingleTargetUseInterest,
	MultiTarget
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FFilterInformation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TSubclassOf<UDMVTargetFilter_Base> FilterClass;
	
	bool operator==(const FFilterInformation& Other) const
	{
		return FilterClass == Other.FilterClass;
	}
};

/**
 * Object representing a TARGET GROUP
 */
UCLASS(BlueprintType)
class DMV_TARGETSYSTEM_API UTargetGroup : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta=(Categories="ID.TargetGroup"))
	FGameplayTag TargetGroupID = FGameplayTag::EmptyTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FFilterInformation> Filters;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ENumberOfTargets NumberOfTargets = ENumberOfTargets::SingleTarget;
	
	UPROPERTY()
	FValidPlayerAutoTargetFound OnValidTargetFound;
	UPROPERTY()
	FPlayerAutoTargetsCleared OnTargetCleared;
	UPROPERTY()
	FFilteringFinished OnFilteringFinished;
	
	bool operator==(const UTargetGroup& Other) const
	{
		return TargetGroupID == Other.TargetGroupID;
	}
};

/**
 * ActorComponent
 * Evaluates different TARGET GROUPS to decide which CANDIDATE is the preferred for each one.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DMV_TARGETSYSTEM_API UDMVTargetEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UDMVTargetEvaluator();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	
	void AnalyseTargetGroups();
	void ApplyFiltersToCandidates(const UTargetGroup* TargetGroupToEvaluate, TArray<UDMVTargetComponent*>& CandidatesTargetComponents);
	void UpdateInterest(
		TArray<UDMVTargetComponent*>& FinalistsPerSubcontext,
		FVector PlayerViewLocation,
		FVector PlayerViewDirection);

	/** ADD a TARGET GROUP to be evaluated by this component. */
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ContextIdentifier, ParentContext"))
	UTargetGroup* AddTargetEvaluationContext(
		UPARAM(meta=(Categories="ID.TargetGroup")) const FGameplayTag& TargetGroupID,
		TArray<FFilterInformation> FiltersForTheContext,
		ENumberOfTargets NumberOfTargets,
		FValidPlayerAutoTargetFound OnValidTargetFound,
		FPlayerAutoTargetsCleared OnTargetCleared,
		FFilteringFinished OnFilteringFinished);
	
	/** REMOVE a TARGET GROUP so that it will no longer be evaluated by this component. */
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ContextIdentifier"))
	void RemoveTargetEvaluationContext(
		UPARAM(meta=(Categories="ID.TargetGroup")) const FGameplayTag& TargetGroupID);

	/** Returns the current target actor for the given TARGET GROUP - the first of its current
	 *  targets, for TARGET GROUPS with more than one (MultiTarget). */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="ContextIdentifier"))
	AActor* GetCurrentTarget(UPARAM(meta=(Categories="ID.TargetGroup"))
		const FGameplayTag& TargetGroupID) const;

	/** Returns the current target component for the given TARGET GROUP - the first of its current
	 *  targets, for TARGET GROUPS with more than one (MultiTarget). */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="ContextIdentifier"))
	UDMVTargetComponent* GetCurrentTargetComponent(UPARAM(meta=(Categories="ID.TargetGroup"))
		const FGameplayTag& TargetGroupID) const;

	/** Returns every current target actor for the given TARGET GROUP. For SingleTarget/
	 *  SingleTargetUseInterest groups this is either empty or a single-element array; MultiTarget
	 *  groups may return more than one. */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="ContextIdentifier"))
	TArray<AActor*> GetCurrentTargets(UPARAM(meta=(Categories="ID.TargetGroup"))
		const FGameplayTag& TargetGroupID) const;

	/** Returns every current target component for the given TARGET GROUP - see GetCurrentTargets. */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="ContextIdentifier"))
	TArray<UDMVTargetComponent*> GetCurrentTargetComponents(UPARAM(meta=(Categories="ID.TargetGroup"))
		const FGameplayTag& TargetGroupID) const;
	
	// INTEREST PROPERTIES
		// By ANGLE
	UPROPERTY(EditAnywhere)
	bool bUpdateInterestByConeAngle = true;
	UPROPERTY(EditAnywhere)
	float MaxAngleToGainInterest = 15.f;
	UPROPERTY(EditAnywhere)
	float InterestWinWhileInAngle = 5;
	UPROPERTY(EditAnywhere)
	float InterestLostWhileOutAngle = 10;
		// By DISTANCE
	UPROPERTY(EditAnywhere)
	bool bUpdateInterestByDistance = true;
	UPROPERTY(EditAnywhere)
	float MaxDistanceToGainInterest = 250.f;
	UPROPERTY(EditAnywhere)
	float InterestWinInDistance = 5;
	UPROPERTY(EditAnywhere)
	float InterestLoseOutDistance = 10;

private:

	/** Helper method to add/set the single current target for a context (SingleTarget/
	 * SingleTargetUseInterest), complete with broadcasting delegate updates if necessary. A thin
	 * wrapper over SetCurrentTargets for the single-target case. */
	void SetCurrentTarget(const FGameplayTag& ContextIdentifier, UDMVTargetComponent* Target);

	/** Helper method to set the full list of current targets for a context (MultiTarget), complete
	 * with broadcasting delegate updates if necessary. Invalid/null entries are dropped; an empty
	 * resulting list clears the context instead of storing an empty array. */
	void SetCurrentTargets(const FGameplayTag& ContextIdentifier, const TArray<UDMVTargetComponent*>& Targets);

	/** Helper method to clear a current target for a context, complete with broadcasting delegate updates if
	 * necessary. */
	void ClearCurrentTarget(const FGameplayTag& ContextIdentifier);

	/** Helper method to clear the list of current targets, complete with broadcasting delegate updates if
	 * necessary. */
	void ClearAllCurrentTargets();

	/** Internal method to handle adding a target evaluation context to the active set. */
	bool AddTargetEvaluationContext_Internal(UTargetGroup* TargetEvaluationContext);

	/** Reference to the subsystem which manages the list of targets. */
	TWeakObjectPtr<UDMVTargetSubsystem> PlayerAutoTargetManagerSubsystem;

	/** Reference to the Player Controller in order to get the player's view. The component is expected to be attached
	 * to the Player Controller, so this should never be null after initialization. */
	TWeakObjectPtr<APlayerController> CachedPlayerController = nullptr;
	
	/** Map containing the active target evaluation contexts, keyed by their context identifier for quick lookup. */
	UPROPERTY(VisibleAnywhere)
	// TMap<FGameplayTag, FTargetGroupList> ActiveTargetGroupsMap;
	TArray<UTargetGroup*> ActiveTargetGroups;

	/** Map containing the current target(s) for target evaluation contexts. SingleTarget/
	 * SingleTargetUseInterest contexts always store a single-element array; MultiTarget contexts
	 * may store more than one. Not a UPROPERTY - UHT doesn't support a TArray value inside a TMap -
	 * but TWeakObjectPtr entries don't need GC tracking either way. */
	TMap<FGameplayTag, TArray<TWeakObjectPtr<UDMVTargetComponent>>> CurrentTargetsMap;

};


