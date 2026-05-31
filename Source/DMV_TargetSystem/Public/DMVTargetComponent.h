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
	UPROPERTY()
	float Interest = .0f;
	FTimerHandle InterestTimer;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void ResetInterest();
	
	/** Here you can add to which context the object belongs */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting", 
		meta=(Categories="ID.TargetGroup"))
	FGameplayTagContainer TargetContextIdentifiers;
};
