// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DMVTargetFilter_Base.h"
#include "Engine/DataAsset.h"
#include "DMVTargetFilter_Data.generated.h"

/**
 * This class is used so designers don't have to use the main character controller to set new filters
 * This allows for many developers to work on different targetings at the same time.
 */
UCLASS()
class DMV_TARGETSYSTEM_API UDMVTargetFilter_Data : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category = "Filters List")
	TArray<UDMVTargetFilter_Base*> FilterList;
};
