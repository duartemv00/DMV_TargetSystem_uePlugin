// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DMV_TargetSubsystem.h"
#include "Components/ActorComponent.h"
#include "Filters/DMV_TargetFilter_Base.h"
#include "DMV_TargetEvaluator.generated.h"

class UDMVTargetFilter_Data;

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
 * Object representing a TARGET GROUP
 */
UCLASS(BlueprintType)
class DMV_TARGETSYSTEM_API UTargetGroup : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta=(Categories="ID.TargetGroup"))
	FGameplayTag TargetGroupID = FGameplayTag::EmptyTag;

	/** This group's filters, each a fully independent, individually-configured instance (see
	 *  UDMVTargetEvaluator::AddTargetEvaluationContext) - editing one doesn't affect any other
	 *  UTargetGroup's copy of the same filter class, even if they were built from the same source
	 *  instance or UDMVTargetFilter_Data asset. */
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
	TArray<UDMVTargetFilter_Base*> Filters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ENumberOfTargets NumberOfTargets = ENumberOfTargets::SingleTarget;

	/** Optional proximity cull, applied before candidates reach Filters: a candidate farther than
	 *  this from the player's view location is dropped without ever running this group's Filters
	 *  on it. <= 0 (the default) means no culling - every target registered under TargetGroupID is
	 *  passed to Filters, same as before this property existed. Culling is done via
	 *  UDMVTargetSubsystem's spatial grid rather than a plain distance check over every registered
	 *  target - see GetTargetsForContext. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxCullDistance = 0.f;

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

	/** ADD a TARGET GROUP to be evaluated by this component. Each filter in FiltersForTheContext is
	 *  duplicated into the resulting UTargetGroup's own ownership - the caller's source instances
	 *  (e.g. pulled from a UDMVTargetFilter_Data asset shared across multiple contexts) are never
	 *  mutated or shared, and each usage of a filter class gets its own independently-configured
	 *  copy of that class's properties (Threshold, ScanClass, and anything a Blueprint subclass
	 *  adds).
	 *
	 *  Not Blueprint-exposed - AddTargetEvaluationContextFromData is the Blueprint entry point, so
	 *  every Blueprint caller goes through one workflow (a UDMVTargetFilter_Data preset asset)
	 *  instead of choosing between two. C++ callers that already have configured filter instances
	 *  in hand can still call this directly. */
	UTargetGroup* AddTargetEvaluationContext(
		UPARAM(meta=(Categories="ID.TargetGroup")) const FGameplayTag& TargetGroupID,
		const TArray<UDMVTargetFilter_Base*>& FiltersForTheContext,
		ENumberOfTargets NumberOfTargets,
		FValidPlayerAutoTargetFound OnValidTargetFound,
		FPlayerAutoTargetsCleared OnTargetCleared,
		FFilteringFinished OnFilteringFinished,
		float MaxCullDistance = 0.f);

	/** Convenience wrapper over AddTargetEvaluationContext that takes a UDMVTargetFilter_Data
	 *  asset's FilterList instead of a raw filter array - lets a designer author a reusable filter
	 *  preset once and reuse it across multiple contexts/controllers. */
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="TargetGroupID"))
	UTargetGroup* AddTargetEvaluationContextFromData(
		UPARAM(meta=(Categories="ID.TargetGroup")) const FGameplayTag& TargetGroupID,
		UDMVTargetFilter_Data* FilterData,
		ENumberOfTargets NumberOfTargets,
		FValidPlayerAutoTargetFound OnValidTargetFound,
		FPlayerAutoTargetsCleared OnTargetCleared,
		FFilteringFinished OnFilteringFinished,
		float MaxCullDistance = 0.f);

	/** REMOVE a TARGET GROUP so that it will no longer be evaluated by this component. */
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="TargetGroupID"))
	void RemoveTargetEvaluationContext(
		UPARAM(meta=(Categories="ID.TargetGroup")) const FGameplayTag& TargetGroupID);

	/** Returns the current target actor for the given TARGET GROUP - the first of its current
	 *  targets, for TARGET GROUPS with more than one (MultiTarget). */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="TargetGroupID"))
	AActor* GetCurrentTarget(UPARAM(meta=(Categories="ID.TargetGroup"))
		const FGameplayTag& TargetGroupID) const;

	/** Returns the current target component for the given TARGET GROUP - the first of its current
	 *  targets, for TARGET GROUPS with more than one (MultiTarget). */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="TargetGroupID"))
	UDMVTargetComponent* GetCurrentTargetComponent(UPARAM(meta=(Categories="ID.TargetGroup"))
		const FGameplayTag& TargetGroupID) const;

	/** Returns every current target actor for the given TARGET GROUP. For SingleTarget/
	 *  SingleTargetUseInterest groups this is either empty or a single-element array; MultiTarget
	 *  groups may return more than one. */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="TargetGroupID"))
	TArray<AActor*> GetCurrentTargets(UPARAM(meta=(Categories="ID.TargetGroup"))
		const FGameplayTag& TargetGroupID) const;

	/** Returns every current target component for the given TARGET GROUP - see GetCurrentTargets. */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="TargetGroupID"))
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

	/** Finds the active TARGET GROUP for a context, or nullptr if none is registered under that
	 * identifier. Used to reach a group's delegates from the ContextIdentifier-only Set/Clear
	 * helpers below. */
	UTargetGroup* FindActiveTargetGroup(const FGameplayTag& ContextIdentifier) const;

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


