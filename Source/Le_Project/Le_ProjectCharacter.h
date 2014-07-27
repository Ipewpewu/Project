// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/SpringArmComponent.h"
#include "InventoryManager.h"
#include "EffectsManager.h"

#include "Le_ProjectCharacter.generated.h"

UCLASS(config=Game)
class ALe_ProjectCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	virtual void Tick(float DeltaTime);

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	TSubobjectPtr<class USpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	TSubobjectPtr<class UCameraComponent> FollowCamera;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float HitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Stamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Agility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Intelligence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Wisdom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Luck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Charisma;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float ArmorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float ResistMagic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float ResistHeat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float ResistCold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float ResistCorruption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float ResistPoison;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float ResistBleed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float RegenHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float RegenMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float MovementSpeed;

public:
	InventoryManager Inventory;
 	class EffectsManager* Effects;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) OVERRIDE;
	// End of APawn interface
};

