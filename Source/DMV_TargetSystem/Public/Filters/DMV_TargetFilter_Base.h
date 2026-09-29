// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DMV_TargetFilter_Base.generated.h"

class APlayerController;
class UDMVTargetComponent;

/**
 * Base class for all filters that can be applied to target candidates.
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew, Abstract)
class DMV_TARGETSYSTEM_API UDMVTargetFilter_Base : public UObject
{
	GENERATED_BODY()

public:
	/** 
	 * Override in subclasses to hold the logic of filtering the candidates.
	 * The function ensures that an empty array of OutFilteredTargets is construct new every call.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformFilter(const TArray<UDMVTargetComponent*>& PotentialTargets,
		APlayerController* PlayerController, UPARAM(ref) 
		TArray<UDMVTargetComponent*>& OutFilteredTargets);

	/** 
	 * Optional separate function in case sorting is needed for the candidates. 
	 * Also override in subclasses.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<UDMVTargetComponent*> SortCandidates(const TArray<UDMVTargetComponent*>& PotentialTargets);
};
