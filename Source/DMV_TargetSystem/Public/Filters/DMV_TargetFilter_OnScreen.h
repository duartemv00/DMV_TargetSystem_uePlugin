// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DMV_TargetFilter_Base.h"
#include "DMV_TargetFilter_OnScreen.generated.h"

class UDMVTargetComponent;

/**
 * Keeps only candidates with at least one of their GetVisibilityTracePoints() sample points
 * projecting inside the player's current viewport rectangle - a screen-space bounds check for
 * "is this on screen at all," independent of whether anything is actually occluding it (that's
 * the separate concern the LineOfSight filter covers).
 */
UCLASS(meta = (DisplayName = "Target Filter - On Screen"))
class DMV_TARGETSYSTEM_API UDMVTargetFilter_OnScreen : public UDMVTargetFilter_Base
{
	GENERATED_BODY()

public:
	virtual void PerformFilter_Implementation(const TArray<UDMVTargetComponent*>& PotentialTargets,
		APlayerController* PlayerController, TArray<UDMVTargetComponent*>& OutFilteredTargets) override;
};
