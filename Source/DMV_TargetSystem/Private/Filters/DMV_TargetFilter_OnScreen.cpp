// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Filters/DMV_TargetFilter_OnScreen.h"

#include "../../Public/DMV_TargetComponent.h"
#include "GameFramework/PlayerController.h"

void UDMVTargetFilter_OnScreen::PerformFilter_Implementation(
	const TArray<UDMVTargetComponent*>& PotentialTargets, APlayerController* PlayerController,
	TArray<UDMVTargetComponent*>& OutFilteredTargets)
{
	if (!IsValid(PlayerController)) return;

	int32 ViewportSizeX = 0;
	int32 ViewportSizeY = 0;
	PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);
	if (ViewportSizeX <= 0 || ViewportSizeY <= 0) return;

	for (UDMVTargetComponent* Candidate : PotentialTargets)
	{
		if (!IsValid(Candidate)) continue;

		// Any sample point landing on screen counts - mirrors the same "any point clear counts as
		// visible" reasoning GetVisibilityTracePoints() exists for on the line-of-sight side: a
		// large target whose origin happens to sit just off-screen can still have an edge on it.
		for (const FVector& SamplePoint : Candidate->GetVisibilityTracePoints())
		{
			FVector2D ScreenPosition;
			if (!PlayerController->ProjectWorldLocationToScreen(SamplePoint, ScreenPosition)) continue;

			if (ScreenPosition.X >= 0.f && ScreenPosition.X <= static_cast<float>(ViewportSizeX)
				&& ScreenPosition.Y >= 0.f && ScreenPosition.Y <= static_cast<float>(ViewportSizeY))
			{
				OutFilteredTargets.Add(Candidate);
				break;
			}
		}
	}
}
