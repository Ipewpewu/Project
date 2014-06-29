#include "Le_Project.h"
#include "IngameMenu.h"


IngameMenu::IngameMenu()
{

}

void IngameMenu::Construct(TWeakObjectPtr<APlayerController> ownerPC)
{
	this->ownerPC = ownerPC;
	this->ownerHUD = (AIngameHUD*)ownerPC->GetHUD();
	isMenuActive = false;
}

void IngameMenu::ToggleMenu()
{
	if (!isMenuActive)
	{
		isMenuActive = true;
		SAssignNew(uiWidget, SSkillMenuUIWidget).ownerHUD(ownerHUD).ownerPC(ownerPC).Cursor(EMouseCursor::Default);

		if (GEngine->IsValidLowLevel())
			GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(uiWidget.ToSharedRef()));

		if (uiWidget.IsValid())
			uiWidget->SetVisibility(EVisibility::Visible);

		ownerPC->SetCinematicMode(isMenuActive, false, false, true, true);
		//pcOwner->SetPause(isMenuActive);
		ownerPC->bShowMouseCursor = isMenuActive;
		//FSlateApplication::Get().SetFocusToGameViewport();
	}
	else
	{
		isMenuActive = false;
		ownerPC->SetCinematicMode(isMenuActive, false, false, true, true);
		ownerPC->bShowMouseCursor = isMenuActive;
		uiWidget->HideMenu();
	}
}