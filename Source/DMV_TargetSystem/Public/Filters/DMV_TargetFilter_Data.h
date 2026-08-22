// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DMV_TargetFilter_Base.h"
#include "Engine/DataAsset.h"
#include "DMV_TargetFilter_Data.generated.h"

/**
 * This class is used so designers don't have to use the main character controller to set new filters
 * This allows for many developers to work on different targetings at the same time.
 *
 * Consumed via UDMVTargetEvaluator::AddTargetEvaluationContextFromData, which duplicates each
 * entry into the resulting UTargetGroup's own ownership - safe to reuse the same
 * UDMVTargetFilter_Data asset across multiple target evaluation contexts/controllers, since
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
