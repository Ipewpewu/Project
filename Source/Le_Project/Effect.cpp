

#include "Le_Project.h"
#include "ParticleDefinitions.h"
#include "Effect.h"


AEffect::AEffect(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Particle = PCIP.CreateDefaultSubobject<UParticleSystemComponent>(this, "Particle");
	Particle->AttachTo(RootComponent);

	Duration = 0.f;
}


