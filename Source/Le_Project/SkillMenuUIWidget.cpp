#include "Le_Project.h"
#include "SkillMenuUIWidget.h"
#include "HumanPlayerController.h"

void SSkillMenuUIWidget::Construct(const FArguments& InArgs)
{
	ownerHUD = InArgs._ownerHUD;
	ownerPC = InArgs._ownerPC;

	ChildSlot
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Left)
		[
			SNew(SBorder)
			.Content()
			[
				SNew(SBox)
				.HeightOverride(700)
				.WidthOverride(1000)
				[
					SNew(SHorizontalBox) + SHorizontalBox::Slot().HAlign(HAlign_Left)
					[
						SNew(SBox).WidthOverride(500)
						[
							MyMenu()
						]
					]
					/*+ SHorizontalBox::Slot().HAlign(HAlign_Center) todo: uncomment this to add new menu section
						[
							SNew(SBox).WidthOverride(350)
							[
								MyMenu()
							]
						]*/
				]
			]

		];
}


TSharedRef<SWidget> SSkillMenuUIWidget::MyMenu()
{
	FMenuBuilder MenuBuilder(true, NULL, TSharedPtr<FExtender>(), false, &FCoreStyle::Get());
	{
		MenuBuilder.AddWidget(SNew(SButton)
			.Text(FText::FromString("Teleport Skill"))
			.OnClicked(this, &SSkillMenuUIWidget::OnTeleportClick)
			, FText::GetEmpty());

		MenuBuilder.AddWidget(SNew(SButton)
			.Text(FText::FromString("Skill 2"))
			, FText::GetEmpty());

		MenuBuilder.AddWidget(SNew(SButton)
			.Text(FText::FromString("Skill 2"))
			, FText::GetEmpty());

		MenuBuilder.AddMenuSeparator(FName("Test"));
		MenuBuilder.AddWidget(SNew(SButton)
			.Text(FText::FromString("Skill 3"))
			, FText::GetEmpty());
	}


	return  MenuBuilder.MakeWidget();

}

FReply SSkillMenuUIWidget::OnTeleportClick() const
{
	FReply Result = FReply::Unhandled();
	AHumanPlayerController* temp = Cast<AHumanPlayerController>(ownerPC->CastToPlayerController());
	temp->BuySkill();
	Result = FReply::Handled();
	return Result;
}

void SSkillMenuUIWidget::HideMenu()
{
	this->SetVisibility(EVisibility::Collapsed);
}
