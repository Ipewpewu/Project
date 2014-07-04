

#include "Le_Project.h"
#include "BasicAiController.h"
#include "AiCharacter.h"
#include "Le_ProjectCharacter.h"


ABasicAiController::ABasicAiController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	BlackboardComp = PCIP.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComp"));

	BehaviorComp = PCIP.CreateAbstractDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));

}

void ABasicAiController::Possess(APawn* pawn)
{
	Super::Possess(pawn);

	AAiCharacter* aiChar = Cast<AAiCharacter>(pawn);

	if (aiChar && aiChar->Behavior)
	{
		BlackboardComp->InitializeBlackboard(aiChar->Behavior->BlackboardAsset);

		TargetId = BlackboardComp->GetKeyID("Target");
		TargetLocationId = BlackboardComp->GetKeyID("Destination");

		BehaviorComp->StartTree(aiChar->Behavior);
	}
}

void ABasicAiController::SetTarget(APawn* target)
{
	BlackboardComp->SetValueAsObject(TargetId, target);
	BlackboardComp->SetValueAsVector(TargetLocationId, target->GetActorLocation());
}

void ABasicAiController::SearchForTarget()
{
	APawn* pawnOwner = GetPawn();
	
	if (!pawnOwner)
		return;

	const FVector currentLocation = pawnOwner->GetActorLocation();
	float closestDistSq = FLT_MAX;
	ALe_ProjectCharacter* targetPlayer= NULL;

	for (FConstPawnIterator x = GetWorld()->GetPawnIterator(); x; x++)
	{
		ALe_ProjectCharacter* testPlayer = Cast<ALe_ProjectCharacter>(*x);
		if (testPlayer)
		{
			const float testDistSq = FVector::Dist(testPlayer->GetActorLocation(), currentLocation);
			if (testDistSq < closestDistSq)
			{
				closestDistSq = testDistSq;
				targetPlayer = testPlayer;
			}
		}
	}

	if (targetPlayer)
		SetTarget(targetPlayer);
}



