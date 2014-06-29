// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Le_Project.h"
#include "HumanPlayerController.h"
#include "IngameHUD.h"
#include "Le_ProjectGameMode.h"

ALe_ProjectGameMode::ALe_ProjectGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UClass> PlayerPawnBPClass(TEXT("Class'/Game/Blueprints/MyCharacter.MyCharacter_C'"));
	if (PlayerPawnBPClass.Object != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Object;
		PlayerControllerClass = AHumanPlayerController::StaticClass();
		HUDClass = AIngameHUD::StaticClass();

	}
}
