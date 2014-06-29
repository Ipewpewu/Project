

#pragma once

#include "GameFramework/PlayerController.h"
#include "IngameMenu.h"
#include "HumanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AHumanPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()
public:
	virtual void SetupInputComponent() OVERRIDE;
	void OnToggleInGameMenu();
	void OnDashSkill();
	void BuySkill();

	TSharedPtr<class IngameMenu> ingameMenu;

protected:
	virtual void PostInitializeComponents() OVERRIDE;

private:
	bool bTeleportSkill;
};
