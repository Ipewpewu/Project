

#pragma once

#include "GameFramework/Actor.h"
#include "Effect.h"
#include "Item.generated.h"


/**
 * 
 */

UENUM(BlueprintType)
namespace ETargetEnum
{
	enum Type
	{
		Self UMETA(DisplayName = "Self"),
		Target UMETA(DisplayName = "Target"),
		NoTarget UMETA(DisplayName = "No Target"),
		Enemy UMETA(DisplayName = "Enemy"),
		Friend UMETA(DisplayName = "Friend"),
		FriendAndSelf UMETA(DisplayName = "Friend and/or Self"),
	};
}

UCLASS()
class AItem : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Target)
		TEnumAsByte<ETargetEnum::Type> TargetEnum;

	UPROPERTY(Category = Trigger, VisibleAnywhere, BlueprintReadOnly)
		TSubobjectPtr<class UBoxComponent> Trigger;
	
	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly)
		TSubobjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Particle)
		TSubobjectPtr<UParticleSystemComponent> Particle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Texture)
		TAssetPtr<UTexture2D> Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = IsStackable)
		bool IsStackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		TSubclassOf<AEffect> Effects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CoolDown)
		float CoolDown;

	UFUNCTION()
		void OnTouch(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void Activate(AActor* OtherActor);
};
