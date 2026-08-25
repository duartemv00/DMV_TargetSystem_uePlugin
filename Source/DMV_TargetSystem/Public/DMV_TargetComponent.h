// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/MeshComponent.h"
#include "Engine/EngineTypes.h"
#include "DMV_TargetComponent.generated.h"

/** Where a target's visibility/line-of-sight checks should sample from, instead of always
 *  using this component's own single-point transform. See the plugin README's Visibility
 *  section for the rationale. */
UENUM(BlueprintType)
enum class EDMVTargetVisibilitySource : uint8
{
	/** Default, unchanged behavior: a single point at GetComponentLocation(). */
	Point,
	/** An explicit shape the actor author placed and configured (see VisibilityProxy). */
	ProxyCollision,
	/** Reuse the owning actor's existing mesh collision - no extra shape needed. */
	OwnerMeshCollision
};

/**
 * Scene Component which registers as a potential target for player auto-targeting. Derived classes can be created with additional functionality.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class DMV_TARGETSYSTEM_API UDMVTargetComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UDMVTargetComponent();

// VISIBILITY //
	/** How PerformScan-style visibility/line-of-sight checks should sample this target.
	 *  Defaults to Point, which is exactly today's behavior. */
	UPROPERTY(EditAnywhere, Category="Targeting|Visibility")
	EDMVTargetVisibilitySource VisibilitySource = EDMVTargetVisibilitySource::Point;

	/** Only used when VisibilitySource is ProxyCollision. Points at a component already placed
	 *  on this actor (e.g. in the Blueprint's Components panel) - the actor author configures
	 *  it themselves (QueryOnly, ignoring every channel except whichever trace channel the
	 *  line-of-sight scan uses). This component only references it by name via
	 *  FComponentReference, it does not spawn or own it. */
	UPROPERTY(EditAnywhere, Category="Targeting|Visibility",
		meta=(EditCondition="VisibilitySource==EDMVTargetVisibilitySource::ProxyCollision", AllowedClasses="/Script/Engine.PrimitiveComponent"))
	FComponentReference VisibilityProxy;

	/** Only used when VisibilitySource is OwnerMeshCollision, and only needed for actors with
	 *  more than one mesh component where auto-resolving would be ambiguous. Leave null to
	 *  auto-resolve via GetOwner()->FindComponentByClass<UMeshComponent>(). */
	UPROPERTY(EditAnywhere, Category="Targeting|Visibility",
		meta=(EditCondition="VisibilitySource==EDMVTargetVisibilitySource::OwnerMeshCollision"))
	TObjectPtr<UMeshComponent> VisibilityMeshOverride;

	/** Resolves the shape driving visibility checks per VisibilitySource, or nullptr in Point
	 *  mode (or if OwnerMeshCollision can't find a mesh to use). */
	UFUNCTION(BlueprintCallable, Category="Targeting|Visibility")
	UPrimitiveComponent* ResolveVisibilityComponent() const;

	/** World-space sample points a line-of-sight scan should trace against: just
	 *  GetComponentLocation() in Point mode (or if no visibility component resolves), or the
	 *  center/top/bottom/left/right/front/back of the resolved component's bounds otherwise.
	 *  Visible if ANY returned point is unobstructed. */
	UFUNCTION(BlueprintCallable, Category="Targeting|Visibility")
	TArray<FVector> GetVisibilityTracePoints() const;

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

	/** This component's registered target-context tags. Used by UDMVTargetSubsystem's spatial grid
	 *  query to confirm a spatially-nearby candidate actually belongs to the tag being queried. */
	const FGameplayTagContainer& GetTargetContextIdentifiers() const { return TargetContextIdentifiers; }

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
