// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DMV_TargetComponent.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DMV_TargetSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPlayerTargetEval, Log, All);

/**
 * 
 */
USTRUCT()
struct FPlayerTargetList
{
	GENERATED_BODY()
public:
	/** Gets the list of targets. */
	const TArray<TWeakObjectPtr<UDMVTargetComponent>>& GetTargets() const { return TargetsArray; }

	/** Adds a target to the list, maintaining uniqueness. Returns false if it was already present. */
	bool AddTarget(UDMVTargetComponent* Target)
	{
		// We check the set first for fast confirmation that the target is unique. */
		if (!TargetsSet.Contains(Target))
		{
			TargetsArray.Add(Target);
			TargetsSet.Add(Target);
			return true;
		}
		return false;
	}

	/** Removes a target from the list. Returns false if it was not found. */
	bool RemoveTarget(UDMVTargetComponent* Target)
	{
		// We remove from the set first so that we can skip the O(n) removal from the array if the target didn't exist.
		if (TargetsSet.Remove(Target) > 0)
		{
			TargetsArray.Remove(Target);
			return true;
		}
		return false;
	}

private:
	UPROPERTY() /** The internal list of targets. */
	TArray<TWeakObjectPtr<UDMVTargetComponent>> TargetsArray;
	
	UPROPERTY() /** An internal store for the targets in a set so that we can do O(1) operations to maintain uniqueness. */
	TSet<TWeakObjectPtr<UDMVTargetComponent>> TargetsSet;
};

/**
 * 
 */
UCLASS()
class DMV_TARGETSYSTEM_API UDMVTargetSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Gets the currently registered targets for the specified target context, 
	 * Optionally culled to those within QueryRadius of QueryOrigin. 
	 * -> QueryRadius <= 0 (the default), returns every target registered under the tag
	 * -> QueryRadius > 0, culls via a periodically rebuilt spatial hash grid instead of scanning every target registered under the tag.
	 * The grid is only built starting the first time any caller passes QueryRadius > 0. */
	TArray<TWeakObjectPtr<UDMVTargetComponent>> GetTargetsForContext(
		const FGameplayTag& TargetContextIdentifier,
		const FVector& QueryOrigin = FVector::ZeroVector,
		float QueryRadius = 0.f);

	/** Registers a potential target for the specified target context. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void RegisterTargetForContext(UDMVTargetComponent* Target, const FGameplayTag& TargetContextIdentifier);

	/** Registers a potential target for the specified target contexts. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void RegisterTargetForContexts(UDMVTargetComponent* Target, const FGameplayTagContainer& TargetContextIdentifiers);

	/** Unregisters a target from the specified target context. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void UnregisterTargetForContext(UDMVTargetComponent* Target, const FGameplayTag& TargetContextIdentifier);

	/** Unregisters a target from the specified target contexts. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void UnregisterTargetForContexts(UDMVTargetComponent* Target, const FGameplayTagContainer& TargetContextIdentifiers);

private:
	/** Re-organize every currently-registered target into an SpatialGrid by its current world location. 
	 * Works across all contexts and deletes duplicates. */
	void RebuildSpatialGrid();

	/** Converts a world location to the grid cell it falls in. */
	FIntVector WorldLocationToCell(const FVector& Location) const;

	/** Map of the registered targets, grouped by targeting context. */
	UPROPERTY()
	TMap<FGameplayTag, FPlayerTargetList> PlayerTargetsByContext;

	/** Cell size (cm) for the spatial hash grid */
	UPROPERTY(EditAnywhere, Category="Targeting|Performance")
	float SpatialGridCellSize = 500.f;

	/** How often (seconds) the spatial grid re-organizes every registered target by its current location. 
	 * Only runs once some caller has actually asked for a radius-bounded query. */
	UPROPERTY(EditAnywhere, Category="Targeting|Performance")
	float SpatialGridRebuildInterval = 0.1f;

	/** Spatial hash grid over every registered target regardless of context tag. Reorganized periodically.
	 * Only ever used by radius-bounded GetTargetsForContext queries
	 * You can then apply distance filters after the grid narrows down which cells to look at. */
	TMap<FIntVector, TArray<TWeakObjectPtr<UDMVTargetComponent>>> SpatialGrid;

	FTimerHandle SpatialGridRebuildTimer;
};
