// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/DMVTargetComponent.h"
#include "../Public/DMVTargetSubsystem.h"
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

			GetWorld()->GetTimerManager().SetTimer(InterestTimer, this, &UDMVTargetComponent::ResetInterest, .01f, true);
		}
	}
}

void UDMVTargetComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (const UGameInstance* GameInstance = GetOwner()->GetGameInstance())
	{
		if (UDMVTargetSubsystem* TargetSubsystem
			= GameInstance->GetSubsystem<UDMVTargetSubsystem>())
		{
			TargetSubsystem->UnregisterTargetForContexts(this, TargetContextIdentifiers);
		}
	}
}

void UDMVTargetComponent::ResetInterest()
{
	Interest = UKismetMathLibrary::Clamp(Interest - 0.01f, BaseInterest, 100.f);	
}

