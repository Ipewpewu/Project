#pragma once

#include "Armor.h"
#include "Le_ProjectCharacter.h"

class EquipmentManager
{
	AArmor* Back;
	AArmor* Chest;
	AArmor* EarLeft;
	AArmor* EarRight;
	AArmor* Face;
	AArmor* Feet;
	AArmor* FingerLeft1;
	AArmor* FingerLeft2;
	AArmor* FingerRight1;
	AArmor* FingerRight2;
	AArmor* Hands;
	AArmor* Head;
	AArmor* Legs;
	AArmor* Neck;
	AArmor* Waist;
	AArmor* WristLeft;
	AArmor* WristRight;

	class ALe_ProjectCharacter* Character;

public:
	EquipmentManager(AActor* actor);
	void EquipArmor(AArmor* currentArmor, AArmor* newArmor);
	void UnEquipArmor(AArmor* armor);

	//TODO: add method to attach/detach from sockets
};