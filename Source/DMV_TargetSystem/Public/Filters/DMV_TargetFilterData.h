// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DMV_TargetFilter_Base.h"
#include "Engine/DataAsset.h"
#include "DMV_TargetFilterData.generated.h"

/**
 * This class is used so designers don't have to go into the main character controller to set new filters.
 * - Many developers can work at the same time.
 * - The different targeting types stay clearer to identify.
 *
 * Safe to reuse the same asset across multiple target evaluation contexts and controllers, since
 * nothing ever mutates FilterList's own instances at runtime.
 */
UCLASS(BlueprintType)
class DMV_TARGETSYSTEM_API UDMVTargetFilter_Data : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly, Category = "Filters List")
	TArray<UDMVTargetFilter_Base*> FilterList;
};
