// Copyright DuarteMV. All Rights Reserved.

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
