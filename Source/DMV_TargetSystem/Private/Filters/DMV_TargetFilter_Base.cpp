// Fill out your copyright notice in the Description page of Project Settings.


#include "../../Public/Filters/DMV_TargetFilter_Base.h"

bool UDMVTargetFilter_Base::SpawnActorToScan(APlayerController* PlayerController, UDMVTargetComponent* Target)
{
	if (!IsValid(ScanClass)) return false;
	bool result = false;
	ADMVScanForActors* Scan = PlayerController->GetWorld()->SpawnActor<ADMVScanForActors>(ScanClass, FVector::ZeroVector, FRotator::ZeroRotator);
	result = Scan->PerformScan(PlayerController, Target);
	Scan->Destroy();
	return result;
}

TArray<UDMVTargetComponent*> UDMVTargetFilter_Base::SortCandidates_Implementation(
	const TArray<UDMVTargetComponent*>& PotentialTargets)
{
	// Basic empty implementation
	TArray<UDMVTargetComponent*> empty;
	return empty; 
}

TArray<UDMVTargetComponent*> UDMVTargetFilter_Base::PerformFilter_Implementation(
	const TArray<UDMVTargetComponent*>& PotentialTargets, APlayerController* PlayerController)
{
	// Basic empty implementation
	TArray<UDMVTargetComponent*> empty;
	return empty;
}
