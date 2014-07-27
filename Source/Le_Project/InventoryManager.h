#pragma once

#include "Item.h"
#include "Array.h"

USTRUCT()
struct ItemStruct
{
	UPROPERTY()
	AItem* Item;
	
	UPROPERTY()
	uint8 Count;

	ItemStruct()
	{
		Item = NULL;
		Count = 1;
	}
};
class InventoryManager
{
	public:
		InventoryManager();
		TArray<ItemStruct> Inventory;
		void PickUpItem(AItem* item);
		void DropItem(AItem* item, FVector Location, FRotator rotation);
		void DestroyItem(AItem* item);
		void UseItem(AItem* item);		
};