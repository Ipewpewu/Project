

#include "Le_Project.h"
#include "Item.h"
#include "ParticleDefinitions.h"
#include "Le_ProjectCharacter.h"

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

void AItem::OnTouch(AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor->IsA(ALe_ProjectCharacter::StaticClass()))
	{
		ALe_ProjectCharacter* player = Cast<ALe_ProjectCharacter>(otherActor);
		if (player)
		{

		}
	}
}
