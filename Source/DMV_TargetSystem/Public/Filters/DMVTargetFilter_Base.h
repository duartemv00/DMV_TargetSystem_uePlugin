// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Scan/DMVScanForActors.h"
#include "UObject/Object.h"
#include "DMVTargetFilter_Base.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew) //Abstract, Blueprintable, DefaultToInstanced
class DMV_TARGETSYSTEM_API UDMVTargetFilter_Base : public UObject
{
	GENERATED_BODY()

public:
	/** Compare value that can be distance, angle, health amount, etc. Per-usage tunable - each
	 *  UTargetGroup owns its own duplicated instance of this filter (see
	 *  UDMVTargetEvaluator::AddTargetEvaluationContext), so this (and any properties a Blueprint
	 *  subclass adds) is set directly on that instance rather than passed in separately. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Threshold = 0;

	/** */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ADMVScanForActors> ScanClass;

public:
	/** */
	UFUNCTION(BlueprintCallable)
	bool SpawnActorToScan(APlayerController* PlayerController, UDMVTargetComponent* Target);

	/** */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<UDMVTargetComponent*> PerformFilter(const TArray<UDMVTargetComponent*>& PotentialTargets,
		APlayerController* PlayerController);
	// void PerformFilter(UPARAM(ref) TArray<UPlayerAutoTargetComponent*>& PotentialTargets);

	/** */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<UDMVTargetComponent*> SortCandidates(const TArray<UDMVTargetComponent*>& PotentialTargets);
};
