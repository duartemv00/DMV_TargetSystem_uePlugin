// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Scan/DMV_ScanForActors.h"
#include "UObject/Object.h"
#include "DMV_TargetFilter_Base.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew) //Abstract, Blueprintable, DefaultToInstanced
class DMV_TARGETSYSTEM_API UDMVTargetFilter_Base : public UObject
{
	GENERATED_BODY()

public:
	/** */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ADMVScanForActors> ScanClass;

public:
	/** */
	UFUNCTION(BlueprintCallable)
	bool SpawnActorToScan(APlayerController* PlayerController, UDMVTargetComponent* Target);

	/** OutFilteredTargets is a fresh, already-empty array the caller (ApplyFiltersToCandidates)
	 *  constructs new every call - it cannot carry stale values over from a previous call the way
	 *  a returned array could if a Blueprint override accidentally reused a persistent instance
	 *  variable as its result. Add surviving candidates to OutFilteredTargets; don't build/return
	 *  a separate array of your own. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformFilter(const TArray<UDMVTargetComponent*>& PotentialTargets,
		APlayerController* PlayerController, UPARAM(ref) TArray<UDMVTargetComponent*>& OutFilteredTargets);

	/** */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<UDMVTargetComponent*> SortCandidates(const TArray<UDMVTargetComponent*>& PotentialTargets);
};
