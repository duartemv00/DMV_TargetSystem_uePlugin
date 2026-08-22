// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DMVTargetComponent.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DMVTargetSubsystem.generated.h"

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

UCLASS()
class DMV_TARGETSYSTEM_API UDMVTargetSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Gets the currently registered targets for the specified target context, optionally culled to
	 * those within QueryRadius of QueryOrigin. Not available in Blueprint - Unreal does not support
	 * WeakObjectPtrs there.
	 *
	 * With QueryRadius <= 0 (the default), returns every target registered under the tag - no
	 * culling, a straight copy of the per-tag list (see FPlayerTargetList).
	 *
	 * With QueryRadius > 0, culls via a periodically-rebuilt spatial hash grid (see
	 * RebuildSpatialGrid) instead of scanning every target registered under the tag - trading a
	 * small window of positional staleness (up to SpatialGridRebuildInterval seconds) for turning
	 * an O(targets registered under this tag) scan into one bounded by how many targets are
	 * actually near QueryOrigin. The grid itself is only built starting the first time any caller
	 * passes QueryRadius > 0 - nothing pays for it otherwise. */
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
	/** Re-buckets every currently-registered target (across all contexts, deduplicated) into
	 * SpatialGrid by its current world location. Started lazily by the first radius-bounded
	 * GetTargetsForContext call, then keeps re-triggering itself on SpatialGridRebuildTimer. */
	void RebuildSpatialGrid();

	/** Converts a world location to the grid cell it falls in, per SpatialGridCellSize. */
	FIntVector WorldLocationToCell(const FVector& Location) const;

	/** Map of the registered targets, grouped by targeting context. */
	UPROPERTY()
	TMap<FGameplayTag, FPlayerTargetList> PlayerTargetsByContext;

	/** Bucket size (cm) for the spatial hash grid used to accelerate radius-bounded
	 * GetTargetsForContext queries. */
	UPROPERTY(EditAnywhere, Category="Targeting|Performance")
	float SpatialGridCellSize = 500.f;

	/** How often (seconds) the spatial grid re-buckets every registered target by its current
	 * location. Only runs once some caller has actually asked for a radius-bounded query. */
	UPROPERTY(EditAnywhere, Category="Targeting|Performance")
	float SpatialGridRebuildInterval = 0.1f;

	/** Spatial hash grid over every registered target (regardless of context tag), rebucketed
	 * periodically - see RebuildSpatialGrid. Not kept in sync with PlayerTargetsByContext in
	 * real time; only ever used by radius-bounded GetTargetsForContext queries, which re-filter
	 * by tag and exact distance after the grid narrows down which cells to look at. */
	TMap<FIntVector, TArray<TWeakObjectPtr<UDMVTargetComponent>>> SpatialGrid;

	FTimerHandle SpatialGridRebuildTimer;
};
