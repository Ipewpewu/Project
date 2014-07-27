#pragma once

#include "Le_Project.h"
#include "Effect.h"
#include "Array.h"
#include "Le_ProjectCharacter.h"

class EffectsManager
{
public:
	EffectsManager(AActor* actor);
	TArray<AEffect*> ActiveEffects;

	void AddEffect(AEffect* effect);	
	void RemoveEffect(AEffect* effect);
	void UpdateEffects();

	void ApplyEffect(AEffect* effect);
	void EndEffect(AEffect* effect);

private:
	class ALe_ProjectCharacter* Character;
	float worldTime;
};