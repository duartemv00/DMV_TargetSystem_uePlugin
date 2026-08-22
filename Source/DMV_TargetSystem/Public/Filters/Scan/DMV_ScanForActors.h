// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMV_ScanForActors.generated.h"

UCLASS(Abstract)
class DMV_TARGETSYSTEM_API ADMVScanForActors : public AActor
{
	GENERATED_BODY()

public:
	ADMVScanForActors();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool PerformScan(APlayerController* PlayerController, UDMVTargetComponent* Target);
};
