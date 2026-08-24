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

	/** */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<UDMVTargetComponent*> PerformFilter(const TArray<UDMVTargetComponent*>& PotentialTargets,
		APlayerController* PlayerController);
	// void PerformFilter(UPARAM(ref) TArray<UPlayerAutoTargetComponent*>& PotentialTargets);

	/** */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<UDMVTargetComponent*> SortCandidates(const TArray<UDMVTargetComponent*>& PotentialTargets);
};
