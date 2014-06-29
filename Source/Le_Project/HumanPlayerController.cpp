

#include "Le_Project.h"
#include "HumanPlayerController.h"


AHumanPlayerController::AHumanPlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bTeleportSkill = false;
}

void AHumanPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SkillMenu", IE_Pressed, this, &AHumanPlayerController::OnToggleInGameMenu);
	InputComponent->BindAction("DashSkill", IE_Pressed, this, &AHumanPlayerController::OnDashSkill);
}


void AHumanPlayerController::OnToggleInGameMenu()
{
	if (ingameMenu.IsValid())
		ingameMenu->ToggleMenu();

	//the below line is how to log text to the output window
	//UE_LOG(LogClass, Log, TEXT("This is a testing statement. The menu should now be showing"));
}

void AHumanPlayerController::OnDashSkill()
{
	if (bTeleportSkill)
	{
		FVector teleportLocation, normalPawnVelocity, traceHitLocation, traceHitNormal, traceStart, cameraLocation;
		FRotator cameraRotation;
		int32 teleportDistance = 500;

		normalPawnVelocity = this->GetPawn()->GetVelocity();
		normalPawnVelocity.Normalize();

		teleportLocation = this->GetPawn()->GetActorLocation();
		traceStart = teleportLocation;

		//calculate teleport location
		if (normalPawnVelocity.X >= 0.5)
			teleportLocation.X += teleportDistance;
		else if (normalPawnVelocity.X <= -0.5)
			teleportLocation.X -= teleportDistance;

		if (normalPawnVelocity.Y >= 0.5)
			teleportLocation.Y += teleportDistance;
		else if (normalPawnVelocity.Y <= -0.5)
			teleportLocation.Y -= teleportDistance;

		//if player isn't moving, teleport where camera is facing
		if (normalPawnVelocity == FVector(0, 0, 0))
		{
			GetPlayerViewPoint(cameraLocation, cameraRotation);
			teleportLocation.X += cameraRotation.Vector().X * 500;
			teleportLocation.Y += cameraRotation.Vector().Y * 500;
		}

		//teleport player
		this->GetPawn()->SetActorLocation(teleportLocation, true);
	}
}

void AHumanPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	ingameMenu = MakeShareable(new IngameMenu());
	ingameMenu->Construct(this);
}

void AHumanPlayerController::BuySkill()
{
	bTeleportSkill = true;
}
