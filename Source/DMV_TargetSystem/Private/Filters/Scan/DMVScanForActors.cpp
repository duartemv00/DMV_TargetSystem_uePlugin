// Fill out your copyright notice in the Description page of Project Settings.


#include "../../../Public/Filters/Scan/DMVScanForActors.h"


ADMVScanForActors::ADMVScanForActors()
{
	PrimaryActorTick.bCanEverTick = true;
}

bool ADMVScanForActors::PerformScan_Implementation(APlayerController* PlayerController, UDMVTargetComponent* Target)
{
	return true;
}


