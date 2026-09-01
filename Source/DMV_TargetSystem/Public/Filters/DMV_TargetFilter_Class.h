// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DMV_TargetFilter_Base.h"
#include "DMV_TargetFilter_Class.generated.h"

class UDMVTargetComponent;

/**
 * Keeps only candidates whose owning Actor is of TargetClass, or any subclass of it - everything
 * else is dropped. Useful for narrowing a broad target context down to one actor type (e.g.
 * pulling only ACustomLightSource actors out of a context that also registers other target types).
 */
UCLASS(meta = (DisplayName = "Target Filter - Class"))
class DMV_TARGETSYSTEM_API UDMVTargetFilter_Class : public UDMVTargetFilter_Base
{
	GENERATED_BODY()

public:
	/** Only candidates whose owning Actor IsA() this class (itself or any subclass) survive. */
	UPROPERTY(EditAnywhere, Category = "Filter")
	TSubclassOf<AActor> TargetClass;

	virtual void PerformFilter_Implementation(const TArray<UDMVTargetComponent*>& PotentialTargets,
		APlayerController* PlayerController, TArray<UDMVTargetComponent*>& OutFilteredTargets) override;
};
