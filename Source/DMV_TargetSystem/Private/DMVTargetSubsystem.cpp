// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/DMVTargetSubsystem.h"

DEFINE_LOG_CATEGORY(LogPlayerTargetEval)

const TArray<TWeakObjectPtr<UDMVTargetComponent>>& UDMVTargetSubsystem::GetTargetsForContext(
	const FGameplayTag& TargetContextIdentifier)
{
	const FPlayerTargetList& TargetList = PlayerTargetsByContext.FindOrAdd(TargetContextIdentifier);
	return TargetList.GetTargets();
}

void UDMVTargetSubsystem::RegisterTargetForContext(UDMVTargetComponent* Target,
	const FGameplayTag& TargetContextIdentifier)
{
	if (!Target)
	{
		UE_LOG(LogPlayerTargetEval, Error, TEXT("Cannot register null player target."));
		return;
	}

	FPlayerTargetList& TargetList = PlayerTargetsByContext.FindOrAdd(TargetContextIdentifier);

	const bool bSuccess = TargetList.AddTarget(Target);
	if (!bSuccess)
	{
		UE_LOG(LogPlayerTargetEval, Warning, TEXT("Failed to add player target %s to context %s because it is "
											"already registered."), *Target->GetOwner()->GetName()
											, *TargetContextIdentifier.ToString());
	}
}

void UDMVTargetSubsystem::RegisterTargetForContexts(UDMVTargetComponent* Target,
	const FGameplayTagContainer& TargetContextIdentifiers)
{
	for (const FGameplayTag& TargetContextIdentifier : TargetContextIdentifiers.GetGameplayTagArray())
	{
		RegisterTargetForContext(Target, TargetContextIdentifier);
	}
}

void UDMVTargetSubsystem::UnregisterTargetForContext(UDMVTargetComponent* Target,
	const FGameplayTag& TargetContextIdentifier)
{
	if (!Target)
	{
		UE_LOG(LogPlayerTargetEval, Error, TEXT("Cannot unregister null player target."));
		return;
	}

	FPlayerTargetList& TargetList = PlayerTargetsByContext.FindOrAdd(TargetContextIdentifier);

	const bool bSuccess = TargetList.RemoveTarget(Target);
	if (!bSuccess)
	{
		UE_LOG(LogPlayerTargetEval, Warning, TEXT("Failed to remove player target %s from context %s because it "
											"was not registered."), *Target->GetOwner()->GetName()
											, *TargetContextIdentifier.ToString());
	}
}

void UDMVTargetSubsystem::UnregisterTargetForContexts(UDMVTargetComponent* Target,
	const FGameplayTagContainer& TargetContextIdentifiers)
{
	for (const FGameplayTag& TargetContextIdentifier : TargetContextIdentifiers.GetGameplayTagArray())
	{
		UnregisterTargetForContext(Target, TargetContextIdentifier);
	}
}
