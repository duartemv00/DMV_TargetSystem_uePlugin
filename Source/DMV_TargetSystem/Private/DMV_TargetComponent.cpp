// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/DMV_TargetComponent.h"
#include "../Public/DMV_TargetSubsystem.h"
#include "Kismet/KismetMathLibrary.h"


UDMVTargetComponent::UDMVTargetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UDMVTargetComponent::BeginPlay()
{
	Super::BeginPlay();

	Interest = BaseInterest;

	if (const UGameInstance* GameInstance = GetOwner()->GetGameInstance())
	{
		if (UDMVTargetSubsystem* TargetSubsystem
			= GameInstance->GetSubsystem<UDMVTargetSubsystem>())
		{
			TargetSubsystem->RegisterTargetForContexts(this, TargetContextIdentifiers);
		}
	}
}

void UDMVTargetComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(InterestTimer);

	if (const UGameInstance* GameInstance = GetOwner()->GetGameInstance())
	{
		if (UDMVTargetSubsystem* TargetSubsystem
			= GameInstance->GetSubsystem<UDMVTargetSubsystem>())
		{
			TargetSubsystem->UnregisterTargetForContexts(this, TargetContextIdentifiers);
		}
	}
}

void UDMVTargetComponent::SetInterest(float NewInterest)
{
	Interest = NewInterest;

	if (Interest > BaseInterest)
	{
		FTimerManager& TimerManager = GetWorld()->GetTimerManager();
		if (!TimerManager.IsTimerActive(InterestTimer))
		{
			TimerManager.SetTimer(InterestTimer, this, &UDMVTargetComponent::ResetInterest, .01f, true);
		}
	}
}

void UDMVTargetComponent::ResetInterest()
{
	Interest = UKismetMathLibrary::Clamp(Interest - 0.01f, BaseInterest, 100.f);

	if (Interest <= BaseInterest)
	{
		GetWorld()->GetTimerManager().ClearTimer(InterestTimer);
	}
}

