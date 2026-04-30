#pragma once
#include "Hero.h"
class MeleeHero :public Hero
{
public:

	MeleeHero():Hero(){}

	MeleeHero(int32_t InHealth, int32_t InStrength, int32_t InIntelligence, int32_t InResource, int32_t InArmor, int32_t InMagicArmor, int32_t InAttackPwr, int32_t InMagicPwr) :
		Hero(InHealth, InStrength, InIntelligence, InResource, InArmor, InMagicArmor, InAttackPwr, InMagicPwr){}
	
	MeleeHero(const AttributeSet& Set) : Hero(Set){}
	
	virtual void EndTurn() override;
};

