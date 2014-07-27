#include "Le_Project.h"
#include "EquipmentManager.h"

EquipmentManager::EquipmentManager(AActor* actor)
{
	if (actor->IsA(ALe_ProjectCharacter::StaticClass()))
	{
		Character = Cast<ALe_ProjectCharacter>(actor);
	}
}

void EquipmentManager::EquipArmor(AArmor* currentArmor, AArmor* newArmor)
{
	if (!Character || !currentArmor)
		return;

	switch (newArmor->SlotEnum)
	{
	case ESlotEnum::Back:
		UnEquipArmor(Back);
		Back = newArmor;
		break;
	case ESlotEnum::Chest:
		UnEquipArmor(Chest);
		Chest = newArmor;
		break;
	case ESlotEnum::Ear:
		if (currentArmor && currentArmor->SlotEnum != ESlotEnum::Ear)
			return;
		UnEquipArmor(currentArmor);
		if (currentArmor == EarLeft)
			EarLeft = newArmor;
		else if (currentArmor == EarRight)
			EarRight = newArmor;
		else if (!EarLeft)
			EarLeft = newArmor;
		else
			EarRight = newArmor;
		break;
	case ESlotEnum::Face:
		UnEquipArmor(Face);
		Face = newArmor;
		break;
	case ESlotEnum::Feet:
		UnEquipArmor(Feet);
		Feet = newArmor;
		break;
	case ESlotEnum::Finger:
		if (currentArmor && currentArmor->SlotEnum != ESlotEnum::Finger)
			return;
		UnEquipArmor(currentArmor);
		if (currentArmor == FingerLeft1)
			FingerLeft1 = newArmor;
		else if (currentArmor == FingerLeft2)
			FingerLeft2 = newArmor;
		else if (currentArmor == FingerRight1)
			FingerRight1 = newArmor;
		else if (currentArmor == FingerRight2)
			FingerRight2 = newArmor;
		else if (!FingerLeft1)
			FingerLeft1 = newArmor;
		else if (!FingerLeft2)
			FingerLeft2 = newArmor;
		else if (!FingerRight1)
			FingerRight1 = newArmor;
		else
			FingerRight2 = newArmor;
		break;
	case ESlotEnum::Hands:
		UnEquipArmor(Hands);
		Hands = newArmor;
		break;
	case ESlotEnum::Head:
		UnEquipArmor(Head);
		Head = newArmor;
		break;
	case ESlotEnum::Legs:
		UnEquipArmor(Legs);
		Legs = newArmor;
		break;
	case ESlotEnum::Neck:
		UnEquipArmor(Neck);
		Neck = newArmor;
		break;
	case ESlotEnum::Waist:
		UnEquipArmor(Waist);
		Waist = newArmor;
		break;
	case ESlotEnum::Wrist:
		if (currentArmor && currentArmor->SlotEnum != ESlotEnum::Wrist)
			return;
		UnEquipArmor(currentArmor);
		if (currentArmor == WristLeft)
			WristLeft = newArmor;
		else if (currentArmor == WristRight)
			WristRight = newArmor;
		else if (!WristLeft)
			WristLeft = newArmor;
		else
			WristRight = newArmor;
		break;
	default:
		return;
	};

	Character->Effects->ApplyEffect(Cast<AEffect>(newArmor->Stats));
}
void EquipmentManager::UnEquipArmor(AArmor* armor)
{
	if (!Character || !armor)
		return;

	if (armor == Back)
		Back = nullptr;
	else if (armor == Chest)
		Chest = nullptr;
	else if (armor == EarLeft)
		EarLeft = nullptr;
	else if (armor == EarRight)
		EarRight = nullptr;
	else if (armor == Face)
		Face = nullptr;
	else if (armor == Feet)
		Feet = nullptr;
	else if (armor == FingerLeft1)
		FingerLeft1 = nullptr;
	else if (armor == FingerLeft2)
		FingerLeft2 = nullptr;
	else if (armor == FingerRight1)
		FingerRight1 = nullptr;
	else if (armor == FingerRight2)
		FingerRight2 = nullptr;
	else if (armor == Hands)
		Hands = nullptr;
	else if (armor == Head)
		Head = nullptr;
	else if (armor == Legs)
		Legs = nullptr;
	else if (armor == Neck)
		Neck = nullptr;
	else if (armor == Waist)
		Waist = nullptr;
	else if (armor == WristLeft)
		WristLeft = nullptr;
	else if (armor == WristRight)
		WristRight = nullptr;
	else
		return;

	Character->Effects->EndEffect(Cast<AEffect>(armor->Stats));
}