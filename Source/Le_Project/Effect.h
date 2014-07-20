

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
	
};
