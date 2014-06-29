#pragma once

#include "Slate.h"
#include "IngameHUD.h"

class SSkillMenuUIWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SSkillMenuUIWidget) : _ownerPC()
	{}
		SLATE_ARGUMENT(TWeakObjectPtr<AIngameHUD>, ownerHUD)

		SLATE_ARGUMENT(TWeakObjectPtr<APlayerController>, ownerPC)

		SLATE_EVENT(FOnClicked, OnClicked)

	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

	/** the delegate to execute when the button is clicked */
	FOnClicked OnClicked;

	//Event to call whenever teleport button is clicked
	FReply OnTeleportClick() const;

	void HideMenu();

private:
	TSharedRef<SWidget> MyMenu();
	TWeakObjectPtr<class AIngameHUD> ownerHUD;
	TWeakObjectPtr<class APlayerController> ownerPC;
};