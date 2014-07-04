

#pragma once

#include "GameFramework/AIController.h"


#include "BasicAiController.generated.h"


/**
 * 
 */
UCLASS()
class ABasicAiController : public AAIController
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(transient)
	TSubobjectPtr<UBlackboardComponent> BlackboardComp;

	UPROPERTY(transient)
	TSubobjectPtr<UBehaviorTreeComponent> BehaviorComp;

	virtual void Possess(APawn* pawn);

	void SetTarget(APawn* target);

	UFUNCTION(BlueprintCallable, Category = Behavior)
		void SearchForTarget();

protected:
	uint8 TargetId;
	uint8 TargetLocationId;
	
};
