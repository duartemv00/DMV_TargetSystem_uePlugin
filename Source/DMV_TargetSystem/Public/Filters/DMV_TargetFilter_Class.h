// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DMV_TargetFilter_Base.h"
#include "DMV_TargetFilter_Class.generated.h"

class UDMVTargetComponent;

/**
 * Keeps only candidates whose owning Actor is of TargetClass or any subclass of it.
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
