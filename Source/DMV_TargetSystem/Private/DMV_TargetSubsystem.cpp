// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/DMV_TargetSubsystem.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY(LogPlayerTargetEval)

TArray<TWeakObjectPtr<UDMVTargetComponent>> UDMVTargetSubsystem::GetTargetsForContext(
	const FGameplayTag& TargetContextIdentifier, const FVector& QueryOrigin, float QueryRadius)
{
	const FPlayerTargetList& TargetList = PlayerTargetsByContext.FindOrAdd(TargetContextIdentifier);

	if (QueryRadius <= 0.f)
	{
		return TargetList.GetTargets();
	}

	// Lazily start rebuilding the spatial grid the first time anyone asks for a radius-bounded
	// query - nothing pays for it otherwise.
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	if (!TimerManager.IsTimerActive(SpatialGridRebuildTimer))
	{
		RebuildSpatialGrid();
		TimerManager.SetTimer(
			SpatialGridRebuildTimer, this, &UDMVTargetSubsystem::RebuildSpatialGrid,
			SpatialGridRebuildInterval, true);
	}

	const float QueryRadiusSquared = FMath::Square(QueryRadius);
	const FIntVector MinCell = WorldLocationToCell(QueryOrigin - FVector(QueryRadius));
	const FIntVector MaxCell = WorldLocationToCell(QueryOrigin + FVector(QueryRadius));

	TArray<TWeakObjectPtr<UDMVTargetComponent>> Result;
	for (int32 CellX = MinCell.X; CellX <= MaxCell.X; ++CellX)
	{
		for (int32 CellY = MinCell.Y; CellY <= MaxCell.Y; ++CellY)
		{
			for (int32 CellZ = MinCell.Z; CellZ <= MaxCell.Z; ++CellZ)
			{
				const TArray<TWeakObjectPtr<UDMVTargetComponent>>* CellTargets =
					SpatialGrid.Find(FIntVector(CellX, CellY, CellZ));
				if (!CellTargets)
				{
					continue;
				}

				for (const TWeakObjectPtr<UDMVTargetComponent>& WeakTarget : *CellTargets)
				{
					// The grid is a coarse cube around the query sphere and only rebuilt
					// periodically, so both tag membership and exact distance still need
					// re-checking against the target's current state.
					UDMVTargetComponent* Target = WeakTarget.Get();
					if (!Target || !Target->GetTargetContextIdentifiers().HasTag(TargetContextIdentifier))
					{
						continue;
					}

					if (FVector::DistSquared(Target->GetComponentLocation(), QueryOrigin) <= QueryRadiusSquared)
					{
						Result.Add(WeakTarget);
					}
				}
			}
		}
	}
	return Result;
}

void UDMVTargetSubsystem::RebuildSpatialGrid()
{
	SpatialGrid.Reset();

	// Union every context's target list first - a target registered under more than one tag
	// should only occupy one grid cell, not be bucketed once per tag.
	TSet<TWeakObjectPtr<UDMVTargetComponent>> UniqueTargets;
	for (const TPair<FGameplayTag, FPlayerTargetList>& Pair : PlayerTargetsByContext)
	{
		UniqueTargets.Append(Pair.Value.GetTargets());
	}

	for (const TWeakObjectPtr<UDMVTargetComponent>& WeakTarget : UniqueTargets)
	{
		if (UDMVTargetComponent* Target = WeakTarget.Get())
		{
			SpatialGrid.FindOrAdd(WorldLocationToCell(Target->GetComponentLocation())).Add(WeakTarget);
		}
	}
}

FIntVector UDMVTargetSubsystem::WorldLocationToCell(const FVector& Location) const
{
	const float CellSize = FMath::Max(SpatialGridCellSize, 1.f);
	return FIntVector(
		FMath::FloorToInt(Location.X / CellSize),
		FMath::FloorToInt(Location.Y / CellSize),
		FMath::FloorToInt(Location.Z / CellSize));
}

void UDMVTargetSubsystem::RegisterTargetForContext(UDMVTargetComponent* Target,
	const FGameplayTag& TargetContextIdentifier)
{
	if (!Target)
	{
		UE_LOG(LogPlayerTargetEval, Error, TEXT("Cannot register null player target."));
		return;
	}

	FPlayerTargetList& TargetList = PlayerTargetsByContext.FindOrAdd(TargetContextIdentifier);

	const bool bSuccess = TargetList.AddTarget(Target);
	if (!bSuccess)
	{
		UE_LOG(LogPlayerTargetEval, Warning, TEXT("Failed to add player target %s to context %s because it is "
											"already registered."), *Target->GetOwner()->GetName()
											, *TargetContextIdentifier.ToString());
	}
}

void UDMVTargetSubsystem::RegisterTargetForContexts(UDMVTargetComponent* Target,
	const FGameplayTagContainer& TargetContextIdentifiers)
{
	for (const FGameplayTag& TargetContextIdentifier : TargetContextIdentifiers.GetGameplayTagArray())
	{
		RegisterTargetForContext(Target, TargetContextIdentifier);
	}
}

void UDMVTargetSubsystem::UnregisterTargetForContext(UDMVTargetComponent* Target,
	const FGameplayTag& TargetContextIdentifier)
{
	if (!Target)
	{
		UE_LOG(LogPlayerTargetEval, Error, TEXT("Cannot unregister null player target."));
		return;
	}

	FPlayerTargetList& TargetList = PlayerTargetsByContext.FindOrAdd(TargetContextIdentifier);

	const bool bSuccess = TargetList.RemoveTarget(Target);
	if (!bSuccess)
	{
		UE_LOG(LogPlayerTargetEval, Warning, TEXT("Failed to remove player target %s from context %s because it "
											"was not registered."), *Target->GetOwner()->GetName()
											, *TargetContextIdentifier.ToString());
	}
}

void UDMVTargetSubsystem::UnregisterTargetForContexts(UDMVTargetComponent* Target,
	const FGameplayTagContainer& TargetContextIdentifiers)
{
	for (const FGameplayTag& TargetContextIdentifier : TargetContextIdentifiers.GetGameplayTagArray())
	{
		UnregisterTargetForContext(Target, TargetContextIdentifier);
	}
}
