#include "Item.h"
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
		Count = 1;
	}
};
class InventoryManager
{
	private:		
		TArray<ItemStruct*> Inventory;

	public:
		InventoryManager();
		void PickUpItem(AItem* item);
		void DropItem(AItem* item, FVector Location, FRotator rotation);
		void DestroyItem(AItem* item);
		void UseItem(AItem* item);		
};