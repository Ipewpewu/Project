#include "Item.h"
#include "Le_ProjectCharacter.h"
#include "Array.h"

USTRUCT()
struct ItemStruct
{
	UPROPERTY()
	AItem* Item;
	
	UPROPERTY()
	int Count;

	ItemStruct()
	{
		Item = NULL;
		Count = 0;
	}
};
class InventoryManager
{
	private:
		InventoryManager();
		TArray<ItemStruct> Inventory;

	public:

};