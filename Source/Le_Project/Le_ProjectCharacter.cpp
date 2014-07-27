// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Le_Project.h"
#include "Le_ProjectCharacter.h"

//////////////////////////////////////////////////////////////////////////
// ALe_ProjectCharacter

ALe_ProjectCharacter::ALe_ProjectCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Set size for collision capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	CharacterMovement->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	CharacterMovement->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	CharacterMovement->JumpZVelocity = 600.f;
	CharacterMovement->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUseControllerViewRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FollowCamera"));
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUseControllerViewRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	HitPoints = 200.f;
	Stamina = 100.f;
	Strength = 100.f;
	Dexterity = 100.f;
	Agility = 100.f;
	Intelligence = 100.f;
	Wisdom = 100.f;
	Mana = 100.f;
	Luck = 10.f;
	Charisma = 100.f;
	ArmorClass = 100.f;
	ResistMagic = 100.f;
	ResistHeat = 100.f;
	ResistCold = 100.f;
	ResistCorruption = 100.f;
	ResistBleed = 100.f;
	ResistPoison = 100.f;
	RegenHealth = 1.f;
	RegenMana = 1.f;
	MovementSpeed = 100.f;

	Effects = new EffectsManager(this);
	//Inventory = new InventoryManager();
}

void ALe_ProjectCharacter::Tick(float DeltaTime)
{
	if (!doubleJump && CharacterMovement->IsMovingOnGround())
		doubleJump = true;

	Effects->UpdateEffects();
}
//////////////////////////////////////////////////////////////////////////
// Input

void ALe_ProjectCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	InputComponent->BindAxis("MoveForward", this, &ALe_ProjectCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ALe_ProjectCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ALe_ProjectCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ALe_ProjectCharacter::LookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ALe_ProjectCharacter::TouchStarted);
}

bool ALe_ProjectCharacter::DoJump(bool bReplayingMoves)
{
	if (Super::CanJump())
	{
		return true && CharacterMovement->DoJump();
	}
	if (CanDoubleJump && doubleJump && !bIsCrouched && CharacterMovement && CharacterMovement->CanEverJump() && !CharacterMovement->bWantsToCrouch)
	{
		doubleJump = false;
		return true && CharacterMovement->DoJump();
	}

	return false;
}

void ALe_ProjectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void ALe_ProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ALe_ProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ALe_ProjectCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ALe_ProjectCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
