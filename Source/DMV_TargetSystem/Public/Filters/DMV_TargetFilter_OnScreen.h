// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DMV_TargetFilter_Base.h"
#include "DMV_TargetFilter_OnScreen.generated.h"

class UDMVTargetComponent;

/**
 * Keeps candidates with at least 1 of their sample points projecting inside the player's current viewport rectangle 
 * Independent of whether anything is actually occluding it.
 */
UCLASS(meta = (DisplayName = "Target Filter - On Screen"))
class DMV_TARGETSYSTEM_API UDMVTargetFilter_OnScreen : public UDMVTargetFilter_Base
{
	GENERATED_BODY()

public:
	virtual void PerformFilter_Implementation(const TArray<UDMVTargetComponent*>& PotentialTargets,
		APlayerController* PlayerController, TArray<UDMVTargetComponent*>& OutFilteredTargets) override;
};
