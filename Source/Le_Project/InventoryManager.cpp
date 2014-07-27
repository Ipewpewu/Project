#include "Le_Project.h"
#include "InventoryManager.h"

InventoryManager::InventoryManager()
{

}

void InventoryManager::PickUpItem(AItem* item)
{
	if (item)
	{
		uint8 max = Inventory.Num();

		for (uint8 i = 0; i < max; i++)
		{
			if (Inventory[i].Item == item)
			{
				Inventory[i].Count++;
				item->Destroy();
				return;
			}
		}

		ItemStruct newItem =  ItemStruct();
		newItem.Item = item;

		Inventory.Add(newItem);

		item->Destroy();
		return;
	}
}
void InventoryManager::DropItem(AItem* item, FVector location, FRotator rotation)
{
	if (item)
	{
		UWorld * const world = item->GetWorld();
		if (world)
		{
			AItem * spawnedItem = world->SpawnActor<AItem>(item->GetClass(), location, rotation);
			DestroyItem(item);
		}				
	}
}
void InventoryManager::DestroyItem(AItem* item)
{
	if (item)
	{
		int const max = Inventory.Num();

		for (int i = 0; i < max; i++)
		{
			if (Inventory[i].Item == item)
			{
				Inventory[i].Count--;

				if (Inventory[i].Count == 0)
				{
					// May or may not work (removing index during iteration)
					Inventory.RemoveAt(i);
				}

				return;
			}
		}
	}
}
void InventoryManager::UseItem(AItem* item)
{

}