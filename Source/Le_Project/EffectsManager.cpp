#include "Le_Project.h"
#include "EffectsManager.h"

EffectsManager::EffectsManager(AActor* actor)
{
	if (actor->IsA(ALe_ProjectCharacter::StaticClass()))
	{
		Character = Cast<ALe_ProjectCharacter>(actor);
	}
	worldTime = 0.f;	
}

void EffectsManager::ApplyEffect(AEffect* effect)
{
	Character->Stamina += effect->Stamina;
	Character->HitPoints += effect->HitPoints;
	Character->Strength += effect->Strength;
	Character->Agility += effect->Agility;
	Character->Dexterity += effect->Dexterity;
	Character->Intelligence += effect->Intelligence;
	Character->Wisdom += effect->Wisdom;
	Character->Mana += effect->Mana;
	Character->Luck += effect->Luck;
	Character->Charisma += effect->Charisma;
	Character->RegenHealth += effect->RegenHealth;
	Character->RegenMana += effect->RegenMana;
	Character->MovementSpeed += effect->MovementSpeed;
	Character->ArmorClass += effect->ArmorClass;
	Character->ResistBleed += effect->ResistBleed;
	Character->ResistCold += effect->ResistCold;
	Character->ResistCorruption += effect->ResistCorruption;
	Character->ResistHeat += effect->ResistHeat;
	Character->ResistMagic += effect->ResistMagic;
	Character->ResistPoison += effect->ResistPoison;
}
void EffectsManager::EndEffect(AEffect* effect)
{
	Character->Stamina -= effect->Stamina;
	Character->HitPoints -= effect->HitPoints;
	Character->Strength -= effect->Strength;
	Character->Agility -= effect->Agility;
	Character->Dexterity -= effect->Dexterity;
	Character->Intelligence -= effect->Intelligence;
	Character->Wisdom -= effect->Wisdom;
	Character->Mana -= effect->Mana;
	Character->Luck -= effect->Luck;
	Character->Charisma -= effect->Charisma;
	Character->RegenHealth -= effect->RegenHealth;
	Character->RegenMana -= effect->RegenMana;
	Character->MovementSpeed -= effect->MovementSpeed;
	Character->ArmorClass -= effect->ArmorClass;
	Character->ResistBleed -= effect->ResistBleed;
	Character->ResistCold -= effect->ResistCold;
	Character->ResistCorruption -= effect->ResistCorruption;
	Character->ResistHeat -= effect->ResistHeat;
	Character->ResistMagic -= effect->ResistMagic;
	Character->ResistPoison -= effect->ResistPoison;
}
void EffectsManager::AddEffect(AEffect* effect)
{
	if (Character)
	{
		if (effect->DurationEnum == EEffectDuration::Permanent)
			ApplyEffect(effect);
		else if (!ActiveEffects.Contains(effect))
		{
			ActiveEffects.Add(effect);
			ApplyEffect(effect);
		}
	}
}
void EffectsManager::RemoveEffect(AEffect* effect)
{
	ActiveEffects.Remove(effect);
	EndEffect(effect);
}

void EffectsManager::UpdateEffects()
{
	if (Character)
	{
		if (worldTime == Character->GetWorld()->TimeSeconds)
			return;

		worldTime = Character->GetWorld()->TimeSeconds;

		uint8 const max = ActiveEffects.Num();

		for (uint8 i = 0; i < max; i++)
		{
			ActiveEffects[i]->Duration -= 1.f;

			if (ActiveEffects[i]->Duration < 0)
				RemoveEffect(ActiveEffects[i]);
		}
	}
}