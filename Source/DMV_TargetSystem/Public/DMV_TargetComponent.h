// Copyright DuarteMV. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/MeshComponent.h"
#include "Engine/EngineTypes.h"
#include "DMV_TargetComponent.generated.h"

/** How the visibility of the owner will be handled. */
UENUM(BlueprintType)
enum class EDMVTargetVisibilityMode : uint8
{
	Point, /** Default. Single point at GetComponentLocation(). */
	ProxyCollision, /** Explicit shape the actor author placed and configured. */
	OwnerMeshCollision /** Reuse the owning actor's existing mesh collision. */
};

/** Scene Component which registers the owner as a potential target. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class DMV_TARGETSYSTEM_API UDMVTargetComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UDMVTargetComponent();

	
	
	
////////// VISIBILITY //////////
/// Used by filters that involve visibility. Expresses how the owner will be perceived by the system. 
	UPROPERTY(EditAnywhere, Category="Targeting|Visibility")
	EDMVTargetVisibilityMode VisibilityMode = EDMVTargetVisibilityMode::Point;

	/** 
	 * VisibilityMode == ProxyCollision. 
	 * References a component already placed, not spawn or own it.
	 * - USER COLLISION CONFIG: QueryOnly, ignoring every channel except whichever trace a filter will use.
	 */ 
	UPROPERTY(EditAnywhere, Category="Targeting|Visibility",
		meta=(EditCondition="VisibilityMode==EDMVTargetVisibilityMode::ProxyCollision", AllowedClasses="/Script/Engine.PrimitiveComponent"))
	FComponentReference VisibilityProxy;

	/** 
	 * VisibilityMode == OwnerMeshCollision.
	 * Needed for actors with more than one mesh component (ambiguity). 
	 * Leave null to auto-resolve via GetOwner()->FindComponentByClass<UMeshComponent>(). 
	 */
	UPROPERTY(EditAnywhere, Category="Targeting|Visibility",
		meta=(EditCondition="VisibilityMode==EDMVTargetVisibilityMode::OwnerMeshCollision"))
	TObjectPtr<UMeshComponent> VisibilityMeshOverride;

	/** 
	 * Resolves the shape driving visibility checks (ProxyCollision and OwnedMesh)
	 * nullptr in Point or if OwnerMeshCollision can't find a mesh to use.
	 */
	UFUNCTION(BlueprintCallable, Category="Targeting|Visibility")
	UPrimitiveComponent* ResolveVisibilityComponent() const;

	/** World-space sample points for filters to check against. */
	UFUNCTION(BlueprintCallable, Category="Targeting|Visibility")
	TArray<FVector> GetVisibilityTracePoints() const;
	
	
	
	
////////// INTEREST //////////
/// Buffers intention of the player. Useful, for example, when the action happens to fast to perfectly aim, so accidental changes of aim can happen.
	UPROPERTY(EditAnywhere)
	float BaseInterest = .0f;

	/** Seconds between passive Interest-decay ticks. */
	UPROPERTY(EditAnywhere, Category="Interest", meta=(ClampMin="0.02"))
	float InterestDecayInterval = 0.1f;

	/** Interest points bled off per second while a target is no longer being actively evaluated. */
	UPROPERTY(EditAnywhere, Category="Interest", meta=(ClampMin="0.0"))
	float InterestDecayPerSecond = 1.f;

	/** GET current Interest score */
	float GetInterest() const { return Interest; }

	/** Sets Interest to an already-clamped value. The timer only runs while there's something to decay. */
	void SetInterest(float NewInterest);

	/** GET this component's registered target-context tags. */
	const FGameplayTagContainer& GetTargetContextIdentifiers() const { return TargetContextIdentifiers; }

	
	
	
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void ResetInterest();

	/** To which context the owner belongs */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting",
		meta=(Categories="ID.TargetGroup"))
	FGameplayTagContainer TargetContextIdentifiers;

private:
	float Interest = .0f;
	FTimerHandle InterestTimer;
};
