// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SceneComponent.h"
#include "DMVTargetComponent.generated.h"

/**
 * Scene Component which registers as a potential target for player auto-targeting. Derived classes can be created with additional functionality.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class DMV_TARGETSYSTEM_API UDMVTargetComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UDMVTargetComponent();

// INTEREST //
	UPROPERTY(EditAnywhere)
	float BaseInterest = .0f;

	/** Current Interest score - see the per-usage Interest concept in the plugin README. */
	float GetInterest() const { return Interest; }

	/** Sets Interest to an already-clamped value (the evaluator computes the clamp itself against
	 *  BaseInterest/100). (Re)starts the decay timer if this raises Interest above BaseInterest and
	 *  it isn't already running - ResetInterest stops the timer again once decay brings Interest
	 *  back down to BaseInterest, so the timer only runs while there's actually something to decay
	 *  instead of unconditionally for this component's entire lifetime. */
	void SetInterest(float NewInterest);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void ResetInterest();

	/** Here you can add to which context the object belongs */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting",
		meta=(Categories="ID.TargetGroup"))
	FGameplayTagContainer TargetContextIdentifiers;

private:
	float Interest = .0f;
	FTimerHandle InterestTimer;
};
