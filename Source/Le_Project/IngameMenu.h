
#include "Slate.h"
#include "IngameHUD.h"
#include "SkillMenuUIWidget.h"

class IngameMenu
{
public:
	IngameMenu();
	void ToggleMenu();
	void Construct(TWeakObjectPtr<APlayerController> ownerPC);

private:
	bool isMenuActive;

	TWeakObjectPtr<APlayerController> ownerPC;
	TWeakObjectPtr<AIngameHUD> ownerHUD;
	TSharedPtr<class SSkillMenuUIWidget> uiWidget;
};