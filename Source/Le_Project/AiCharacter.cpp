

#include "Le_Project.h"
#include "AiCharacter.h"
#include "BasicAiController.h"


AAiCharacter::AAiCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	AIControllerClass = ABasicAiController::StaticClass();
}


