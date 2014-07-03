

#include "Le_Project.h"
#include "Item.h"
#include "ParticleDefinitions.h"

AItem::AItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Trigger = PCIP.CreateDefaultSubobject<UBoxComponent>(this, "Trigger");
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnTouch);
	RootComponent = Trigger;

	Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, "Mesh");
	Mesh->AttachTo(RootComponent);

	Particle = PCIP.CreateDefaultSubobject<UParticleSystemComponent>(this, "Particle");
	Particle->AttachTo(RootComponent);
}

void AItem::OnTouch(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
