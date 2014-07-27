

#include "Le_Project.h"
#include "IngameHUD.h"
#include "Item.h"
#include "Le_ProjectCharacter.h"

AIngameHUD::AIngameHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	inventoryBackgroundTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(inventoryBackgroundTexturePath)));
	drawInventory = false;
}
void AIngameHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* pc = GetOwningPlayerController();
	if (pc != nullptr)
	{
		inventoryManager = Cast<ALe_ProjectCharacter>(pc->GetCharacter())->Inventory;
		BuildInventoryArray();
	}
}

void AIngameHUD::DrawHUD()
{
	Super::DrawHUD();

	int screenX = Canvas->SizeX;
	int screenY = Canvas->SizeY;
	DrawRect(FColor::White, (screenX / 2), (screenY / 2), 3, 3);

	if (drawInventory)
		DrawInventory();
}
void AIngameHUD::ReceiveHitBoxClick(const FName BoxName)
{
	Super::ReceiveHitBoxClick(BoxName);

	UE_LOG(LogClass, Log, TEXT("Box name from ReceiveHitBoxClick: %s"), *BoxName.ToString());
}
void AIngameHUD::ReceiveHitBoxBeginCursorOver(const FName BoxName)
{
	Super::ReceiveHitBoxBeginCursorOver(BoxName);

	mouseOverIndex = FCString::Atoi(*BoxName.ToString());
	/*APlayerController* pc = GetOwningPlayerController();
	float mouseX = 0.0f;
	float mouseY = 0.0f;
	int textureDimenions = 64;
	int buttonSpacing = textureDimenions + 2;
	pc->GetMousePosition(mouseX, mouseY);
	
	int drawX = floor(mouseX / buttonSpacing);
	int drawY = floor(mouseY / buttonSpacing);
	FString texturePath = "/Game/Textures/HotBarButtonPressed.HotBarButtonPressed";
	UTexture* buttonPressedTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(texturePath)));
	DrawTextureSimple(buttonPressedTexture, (drawX * buttonSpacing), (drawY * buttonSpacing), 1.0f);
*/
	UE_LOG(LogClass, Log, TEXT("Box name from ReceiveHitBoxBeginCursorOver: %s"), *BoxName.ToString());
}
void AIngameHUD::DrawInventory()
{
	int textureDimensions = 64;
	int buttonSpacing = textureDimensions + 2; //(64 will textures Dimensions and should be able to change from editor)
	
	APlayerController* pc = GetOwningPlayerController();
	if (pc != nullptr)
	{
		inventoryManager = Cast<ALe_ProjectCharacter>(pc->GetCharacter())->Inventory;
		BuildInventoryArray();
	}

	DrawTextureSimple(inventoryBackgroundTexture, 1, 1, 1.0f);

	int drawX = 0, drawY = 0;
	for (int i = 0; i < 50; i++)
	{
		if (i != 0)
			drawX++;
		if (i >= 10 && i % 10 == 0)
		{
			drawX = 0;
			drawY++;
		}
		UTexture* drawTexture = items[i].emptyTextureButton;
		if (i == mouseOverIndex)
			drawTexture = items[i].mouseOverTextureButton;
		
		FVector2D hitBoxPosition = FVector2D(drawX * buttonSpacing, drawY * buttonSpacing);
		FVector2D hitBoxSize = FVector2D(textureDimensions, textureDimensions);
		DrawTextureSimple(drawTexture, (drawX * buttonSpacing), (drawY * buttonSpacing), 1.0f);
		AddHitBox(hitBoxPosition, hitBoxSize, FName(*(FString::FromInt(i))), true, 0);
	}
}
void AIngameHUD::BuildInventoryArray()
{
	int textureDimenions = 64;
	int inventoryCount = inventoryManager.Inventory.Num();
	for (int i = 0; i < inventoryCount; i++)
	{
		AItem* item = inventoryManager.Inventory[i].Item;
		/*UTexture2D* asdf = item->Texture.Get();
		FStringAssetReference name2 = item->Texture.ToStringReference();
		*/
		//TODO: find out why the texture has to be opened up first in order to display properly
		items[i].emptyTextureButton = item->Texture.Get();
	}
		
}