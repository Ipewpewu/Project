

#pragma once

#include "GameFramework/HUD.h"
#include "InventoryManager.h"
#include "IngameHUD.generated.h"

/**
*
*/

UCLASS()
class AIngameHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	void BeginPlay() OVERRIDE;
	void DrawHUD() OVERRIDE;
	void ReceiveHitBoxClick(const FName BoxName) OVERRIDE;
	void ReceiveHitBoxBeginCursorOver(const FName BoxName) OVERRIDE;
	void DrawInventory();
	void BuildInventoryArray();

private:
	struct SItem
	{
		FString emptyTexturePath = "/Game/Textures/HotBarButton.HotBarButton";
		UTexture* emptyTextureButton = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(emptyTexturePath)));

		FString mouseOverTexturePath = "/Game/Textures/HotBarButtonPressed.HotBarButtonPressed";
		UTexture* mouseOverTextureButton = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(mouseOverTexturePath)));
	};
	InventoryManager inventoryManager;

	/** This is the index the mouse is over when Inventory is open*/
	int mouseOverIndex = -1;

	/** This is the index the mouse clicked on when Inventory is open*/
	int mouseSelectedIndex = -1;

	SItem items[50];
	/*FString emptyTexturePath = "/Game/Textures/HotBarButton.HotBarButton";
	UTexture* emptyTextureButton;

	FString mouseOverTexturePath = "/Game/Textures/HotBarButtonPressed.HotBarButtonPressed";
	UTexture* mouseOverTextureButton;*/

	//Texture2D'/Game/Textures/InventoryBackground.InventoryBackground'
	FString inventoryBackgroundTexturePath = "/Game/Textures/InventoryBackground.InventoryBackground";
	UTexture* inventoryBackgroundTexture;
public:
	bool drawInventory;
};
