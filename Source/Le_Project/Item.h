

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class AItem : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(Category = Trigger, VisibleAnywhere, BlueprintReadOnly)
	TSubobjectPtr<class UBoxComponent> Trigger;
	
	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly)
		TSubobjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Particle)
		TSubobjectPtr<UParticleSystemComponent> Particle;

	UFUNCTION()
		void OnTouch(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
