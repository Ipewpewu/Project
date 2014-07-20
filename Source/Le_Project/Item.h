

#pragma once

#include "GameFramework/Actor.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	TEnumAsByte<ETargetEnum::Type> TargetEnum;

	UPROPERTY(Category = Trigger, VisibleAnywhere, BlueprintReadOnly)
	TSubobjectPtr<class UBoxComponent> Trigger;
	
	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly)
		TSubobjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Particle)
		TSubobjectPtr<UParticleSystemComponent> Particle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = IsStackable)
		bool IsStackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool HitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Stamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Agility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Intelligence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Wisdom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Luck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool Charisma;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool ArmorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool ResistMagic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool ResistHeat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool ResistCold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool ResistCorruption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool ResistPoison;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool ResistBleed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool RegenHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool RegenMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		bool MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float HitPointsAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float StaminaAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float StrengthAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float DexterityAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float AgilityAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float IntelligenceAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float WisdomAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ManaAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float LuckAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float CharismaAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ArmorClassAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ResistMagicAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ResistHeatAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ResistColdAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ResistCorruptionAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ResistPoisonAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float ResistBleedAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float RegenHealthAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float RegenManaAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EffectAmount)
		float MovementSpeedAmount;

	UFUNCTION()
		void OnTouch(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void Activate(AActor* OtherActor);
};
