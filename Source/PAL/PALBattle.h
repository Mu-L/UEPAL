#pragma once

#include "CoreMinimal.h"

constexpr float BATTLE_FRAME_TIME = 0.04f;

static int16
CalculateBaseDamage(uint16 Strength, uint16 Defense)
{
	int16 Damage;

	// Formula courtesy of palxex and shenyanduxing
	if (Strength > Defense)
	{
		Damage = (int16)(Strength * 2 - Defense * 1.6 + 0.5);
	}
	else if (Strength > Defense * 0.6)
	{
		Damage = (int16)(Strength - Defense * 0.6 + 0.5);
	}
	else
	{
		Damage = 0;
	}

	return Damage;
}

static int16
CalculatePhysicalAttackDamage(uint16 AttackStrength, uint16 Defense, uint16 AttackResistance)
{
	int16 Damage = CalculateBaseDamage(AttackStrength, Defense);
	if (AttackResistance != 0)
	{
		Damage /= AttackResistance;
	}
	return Damage;
}
