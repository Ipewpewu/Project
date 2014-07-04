

#pragma once

#include "GameFramework/Character.h"


#include "AiCharacter.generated.h"


/**
 * 
 */
UCLASS()
class AAiCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category = Behavior)
	UBehaviorTree* Behavior;
	
};
