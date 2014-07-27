

#pragma once
#include "Item.h"
#include "Armor.generated.h"


/**
 * 
 */

UENUM(BlueprintType)
namespace ESlotEnum
{
	enum Slot
	{
		Back UMETA(DisplayName = "Back"),
		Chest UMETA(DisplayName = "Chest"),
		Ear UMETA(DisplayName = "Ear"),
		Face UMETA(DisplayName = "Face"),
		Feet UMETA(DisplayName = "Feet"),
		Finger UMETA(DisplayName = "Finger"),
		Hands UMETA(DisplayName = "Hands"),
		Head UMETA(DisplayName = "Head"),
		Legs UMETA(DisplayName = "Legs"),
		Neck UMETA(DisplayName = "Neck"),
		Waist UMETA(DisplayName = "Waist"),
		Wrist UMETA(DisplayName = "Wrist"),
	};
}

UCLASS()
class AArmor : public AItem
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	TEnumAsByte<ESlotEnum::Slot> SlotEnum;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		TSubclassOf<AEffect> Stats;
};
