// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DMVTargetComponent.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DMVTargetSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPlayerTargetEval, Log, All);

/**
 * 
 */

USTRUCT()
struct FPlayerTargetList
{
	GENERATED_BODY()
public:
	/** Gets the list of targets. */
	const TArray<TWeakObjectPtr<UDMVTargetComponent>>& GetTargets() const { return TargetsArray; }

	/** Adds a target to the list, maintaining uniqueness. Returns false if it was already present. */
	bool AddTarget(UDMVTargetComponent* Target)
	{
		// We check the set first for fast confirmation that the target is unique. */
		if (!TargetsSet.Contains(Target))
		{
			TargetsArray.Add(Target);
			TargetsSet.Add(Target);
			return true;
		}
		return false;
	}

	/** Removes a target from the list. Returns false if it was not found. */
	bool RemoveTarget(UDMVTargetComponent* Target)
	{
		// We remove from the set first so that we can skip the O(n) removal from the array if the target didn't exist.
		if (TargetsSet.Remove(Target) > 0)
		{
			TargetsArray.Remove(Target);
			return true;
		}
		return false;
	}

private:
	UPROPERTY() /** The internal list of targets. */
	TArray<TWeakObjectPtr<UDMVTargetComponent>> TargetsArray;
	
	UPROPERTY() /** An internal store for the targets in a set so that we can do O(1) operations to maintain uniqueness. */
	TSet<TWeakObjectPtr<UDMVTargetComponent>> TargetsSet;
};

UCLASS()
class DMV_TARGETSYSTEM_API UDMVTargetSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Gets the currently registered targets for the specified target context. This is not available in Blueprint as
	 * Unreal does not support WeakObjectPtrs there. */
	const TArray<TWeakObjectPtr<UDMVTargetComponent>>& GetTargetsForContext(const FGameplayTag& TargetContextIdentifier);

	/** Registers a potential target for the specified target context. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void RegisterTargetForContext(UDMVTargetComponent* Target, const FGameplayTag& TargetContextIdentifier);

	/** Registers a potential target for the specified target contexts. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void RegisterTargetForContexts(UDMVTargetComponent* Target, const FGameplayTagContainer& TargetContextIdentifiers);

	/** Unregisters a target from the specified target context. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void UnregisterTargetForContext(UDMVTargetComponent* Target, const FGameplayTag& TargetContextIdentifier);

	/** Unregisters a target from the specified target contexts. */
	UFUNCTION(BlueprintCallable, Category="Targeting")
	void UnregisterTargetForContexts(UDMVTargetComponent* Target, const FGameplayTagContainer& TargetContextIdentifiers);

private:
	/** Map of the registered targets, grouped by targeting context. */
	UPROPERTY()
	TMap<FGameplayTag, FPlayerTargetList> PlayerTargetsByContext;
};
