// Copyright DuarteMV. All Rights Reserved.


#include "../../Public/Filters/DMV_TargetFilter_Base.h"

TArray<UDMVTargetComponent*> UDMVTargetFilter_Base::SortCandidates_Implementation(
	const TArray<UDMVTargetComponent*>& PotentialTargets)
{
	// Basic empty implementation
	TArray<UDMVTargetComponent*> empty;
	return empty; 
}

void UDMVTargetFilter_Base::PerformFilter_Implementation(
	const TArray<UDMVTargetComponent*>& PotentialTargets, APlayerController* PlayerController,
	TArray<UDMVTargetComponent*>& OutFilteredTargets)
{
	// Basic empty implementation - OutFilteredTargets is left as the caller provided it (empty).
}
