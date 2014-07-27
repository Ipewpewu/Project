

#pragma once

#include "GameFramework/Actor.h"
#include "Effect.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
namespace EEffectDuration
{
	enum Type
	{
		Timer UMETA(DisplayName = "Timer"),
		ItemEquip UMETA(DisplayName = "Item Equip"),
		Permanent UMETA(DisplayName = "Permanent"),
		Event UMETA(DisplayName = "Event"),
		Random UMETA(DisplayName = "Random"),
	};
}

UCLASS()
class AEffect : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Particle)
		TSubobjectPtr<UParticleSystemComponent> Particle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Target)
		TEnumAsByte<EEffectDuration::Type> DurationEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Duration)
		float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float HitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Stamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Agility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Intelligence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Wisdom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Luck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float Charisma;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float ArmorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float ResistMagic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float ResistHeat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float ResistCold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float ResistCorruption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float ResistPoison;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float ResistBleed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float RegenHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float RegenMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effect)
		float MovementSpeed;
	
};
