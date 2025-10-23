// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DMVTargetSubsystem.h"
#include "Components/ActorComponent.h"
#include "Filters/DMVTargetFilter_Base.h"
#include "DMVTargetEvaluator.generated.h"

USTRUCT(BlueprintType)
struct FTargetInputContext
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	class UDMVTargetComponent* TargetComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	class AActor* TargetActor = nullptr;
};

// DECLARE_DYNAMIC_DELEGATE(FPlayerAutoTargetEvaluationStarted);
// DECLARE_DYNAMIC_DELEGATE_OneParam(FValidateContextAutoTarget, bool&, bContextEnabled);
// DECLARE_DYNAMIC_DELEGATE_TwoParams(FValidatePlayerAutoTarget, FTargetInputContext, InputContext, bool&, OutValid);
// DECLARE_DYNAMIC_DELEGATE_OneParam(FPlayerAutoTargetEvaluationFinished, UDMVTargetComponent*, NewTarget);
// DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerAutoTargetsUpdated, const FGameplayTag&, ContextIdentifier, UDMVTargetComponent*, NewTarget);

/** When the filters are done */
DECLARE_DYNAMIC_DELEGATE_OneParam(FFilteringFinished, UDMVTargetComponent*, Targets);
/** When a valid target is selected */
DECLARE_DYNAMIC_DELEGATE_OneParam(FValidPlayerAutoTargetFound, AActor*, Actor);
/** When all saved targets are deleted */
DECLARE_DYNAMIC_DELEGATE(FPlayerAutoTargetsCleared);


/** Object representing a targeting context,
 * which allows individual systems to register different requirements for target evaluation. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DMV_TARGETSYSTEM_API UXM_TargetEvaluationContext : public UObject
{
	GENERATED_BODY()

public:
	/** Id for the context. Must be unique from other contexts added to the same evaluator component. */
	UPROPERTY(EditAnywhere, meta=(Categories="ID.TargetEvaluationContext"))
	FGameplayTag ContextIdentifier = FGameplayTag::EmptyTag;

	/** Id of the functional group of which the context is part
	 * Can be shared between differnt contexts */
	UPROPERTY(EditAnywhere, meta=(Categories="ID.TargetEvaluationContext"))
	FGameplayTag ParentContextIdentifier = FGameplayTag::EmptyTag;
	
	UPROPERTY()
	FValidPlayerAutoTargetFound OnValidTargetFound;
	UPROPERTY()
	FPlayerAutoTargetsCleared OnTargetCleared;
	UPROPERTY()
	FFilteringFinished OnFilteringFinished;
};




USTRUCT(BlueprintType)
struct FEvaluationContexts
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, UXM_TargetEvaluationContext*> TargetEvaluationContexts;
};

USTRUCT(BlueprintType)
struct FFilterInformation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Threshold = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OutputNumber = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TSubclassOf<UDMVTargetFilter_Base> FilterClass;

	// Override Operators
	bool operator==(const FFilterInformation& Other) const
	{
		return FilterClass == Other.FilterClass;
	}
};

USTRUCT(BlueprintType)
struct FEvaluationFilters
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(Categories="ID.TargetEvaluationContext"))
	// FGameplayTagContainer SubContextId;
	FGameplayTagContainer SubContextId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FFilterInformation> FiltersForSubcontext;
};




UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DMV_TARGETSYSTEM_API UDMVTargetEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UDMVTargetEvaluator();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	void UpdateInterset(TMap<TObjectPtr<UDMVTargetComponent>, UXM_TargetEvaluationContext*>& FinalistsPerSubcontext,
		FVector PlayerViewLocation,
		FVector PlayerViewDirection);

	/** Adds a new target evaluation context to be evaluated. */
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ContextIdentifier, ParentContext"))
	UXM_TargetEvaluationContext* AddTargetEvaluationContext(
		UPARAM(meta=(Categories="ID.TargetEvaluationContext")) const FGameplayTag& ParentContext,
		UPARAM(meta=(Categories="ID.TargetEvaluationContext")) const FGameplayTag& ContextIdentifier,
		TArray<FFilterInformation> FiltersForTheContext,
		FValidPlayerAutoTargetFound OnValidTargetFound,
		FPlayerAutoTargetsCleared OnTargetCleared,
		FFilteringFinished OnFilteringFinished);
	/** Removes a target evaluation context so that it will no longer be evaluated. */
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ContextIdentifier"))
	void RemoveTargetEvaluationContext(
		UPARAM(meta=(Categories="ID.TargetEvaluationContext")) const FGameplayTag& ContextIdentifier);

	/** Gets the current target actor for the given evaluation context. */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="ContextIdentifier"))
	AActor* GetCurrentTarget(UPARAM(meta=(Categories="ID.TargetEvaluationContext")) const FGameplayTag& ContextIdentifier) const;
	/** Gets the current target for the given evaluation context. */
	UFUNCTION(BlueprintPure, meta=(AutoCreateRefTerm="ContextIdentifier"))
	UDMVTargetComponent* GetCurrentTargetComponent(UPARAM(meta=(Categories="ID.TargetEvaluationContext")) const FGameplayTag& ContextIdentifier) const;
	
	/** Delegate that fires when the target of any context is changed. Note that this is a single delegate which
	 * encompasses all of the contexts, which means that that any bound objects are responsible for checking the
	 * context that was updated themselves. Unfortunately, this seems to be the only way to handle this in a manner
	 * that allows Blueprints to hook up to the delegate, since Unreal does not allow us to return individual context-
	 * specific delegates with a function. */
	// UPROPERTY(BlueprintAssignable)
	// FPlayerAutoTargetsUpdated OnPlayerTargetsUpdated;

	/** List of the filters that can be applied to a certain context identified by the id. */
	UPROPERTY(EditAnywhere)
	TArray<FEvaluationFilters> Filters;
	
// INTEREST
	// By ANGLE
	UPROPERTY(EditAnywhere)
	bool bUpdateInterestByConeAngle = true;
	UPROPERTY(EditAnywhere)
	float MaxAngleToGainInterest = 15.f;
	UPROPERTY(EditAnywhere)
	float InterestWinInAngle = 5;
	UPROPERTY(EditAnywhere)
	float InterestLoseOutAngle = 10;
	// By DISTANCE
	UPROPERTY(EditAnywhere)
	bool bUpdateInterestByDistance = true;
	UPROPERTY(EditAnywhere)
	float MaxDistanceToGainInterest = 250.f;
	UPROPERTY(EditAnywhere)
	float InterestWinInDistance = 5;
	UPROPERTY(EditAnywhere)
	float InterestLoseOutDistance = 10;

protected:

	/** Target evaluation contexts that are activated in BeginPlay. Provides a centralized place for defining targeting
	 * parameters that don't need to be dynamically added or removed. */
	UPROPERTY(Instanced, EditDefaultsOnly, BlueprintReadOnly)
	TArray<UXM_TargetEvaluationContext*> InitialTargetEvaluationContexts;

private:

	/** Helper method to add/set a current target for a context, complete with broadcasting delegate updates if
	 * necessary. */
	void SetCurrentTarget(const FGameplayTag& ContextIdentifier, UDMVTargetComponent* Target);

	/** Helper method to clear a current target for a context, complete with broadcasting delegate updates if
	 * necessary. */
	void ClearCurrentTarget(const FGameplayTag& ContextIdentifier);

	/** Helper method to clear the list of current targets, complete with broadcasting delegate updates if
	 * necessary. */
	void ClearAllCurrentTargets();

	/** Internal method to handle adding a target evaluation context to the active set. */
	bool AddTargetEvaluationContext_Internal(UXM_TargetEvaluationContext* TargetEvaluationContext);

	/** Reference to the subsystem which manages the list of targets. */
	TWeakObjectPtr<UDMVTargetSubsystem> PlayerAutoTargetManagerSubsystem;

	/** Reference to the Player Controller in order to get the player's view. The component is expected to be attached
	 * to the Player Controller, so this should never be null after initialization. */
	TWeakObjectPtr<APlayerController> CachedPlayerController = nullptr;
	
	/** Map containing the active target evaluation contexts, keyed by their context identifier for quick lookup. */
	UPROPERTY(VisibleAnywhere)
	TMap<FGameplayTag, FEvaluationContexts> ActiveTargetEvaluationContextsMap;

	/** Map containing the current target for target evaluation contexts. */
	UPROPERTY(VisibleAnywhere)
	TMap<FGameplayTag, TWeakObjectPtr<UDMVTargetComponent>> CurrentTargetsMap;

	/** Max range of all active target evaluations contexts. This is cached anytime the contexts are updated.
	 *
	 * This is one of the main motivations of having this class; we only need to do a single sphere check for actors,
	 * and then evaluate each of those targets against each context (as opposed to doing a sphere check for each type
	 * of targeting. */
	float CurrentTargetEvaluationRange = 0.f;

	/* Static sphere shape used for line-of-sight checking. */
	inline static FCollisionShape LineOfSightSphereShape = FCollisionShape::MakeSphere(10.f);
	
};


