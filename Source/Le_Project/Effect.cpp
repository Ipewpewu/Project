

#include "Le_Project.h"
#include "ParticleDefinitions.h"
#include "Effect.h"


AEffect::AEffect(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Particle = PCIP.CreateDefaultSubobject<UParticleSystemComponent>(this, "Particle");
	Particle->AttachTo(RootComponent);

	HitPoints = 0.f;
	Mana = 0.f;
	Stamina = 0.f;
	Strength = 0.f;
	Agility = 0.f;
	Dexterity = 0.f;
	Intelligence = 0.f;
	Wisdom = 0.f;
	Luck = 0.f;
	Charisma = 0.f;
	ArmorClass = 0.f;
	ResistBleed = 0.f;
	ResistCold = 0.f;
	ResistCorruption = 0.f;
	ResistHeat = 0.f;
	ResistMagic = 0.f;
	ResistPoison = 0.f;
	MovementSpeed = 0.f;
	RegenHealth = 0.f;
	RegenMana = 0.f;

	Duration = 0.f;
}


