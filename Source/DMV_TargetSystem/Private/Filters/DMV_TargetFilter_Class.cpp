// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Filters/DMV_TargetFilter_Class.h"

#include "../../Public/DMV_TargetComponent.h"
#include "GameFramework/Actor.h"

void UDMVTargetFilter_Class::PerformFilter_Implementation(
	const TArray<UDMVTargetComponent*>& PotentialTargets, APlayerController* PlayerController,
	TArray<UDMVTargetComponent*>& OutFilteredTargets)
{
	if (!TargetClass) return;

	for (UDMVTargetComponent* Candidate : PotentialTargets)
	{
		if (!IsValid(Candidate)) continue;

		const AActor* CandidateOwner = Candidate->GetOwner();
		if (IsValid(CandidateOwner) && CandidateOwner->IsA(TargetClass))
		{
			OutFilteredTargets.Add(Candidate);
		}
	}
}
