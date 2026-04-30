#pragma once
#include "MeleeHero.h"
class Hero;
class Barbarian :public MeleeHero
{

public:
	
	Barbarian() : MeleeHero(){}
	Barbarian(const AttributeSet& Set) : MeleeHero(Set)
	{
		Resource = 0;
	}
	
	virtual Archetype GetHeroArchetype() const override
	{
		return CurrentType;
	}
	
	virtual void TakeDamage(const DamageInfo& DamageInfo) override;

private:

	Archetype CurrentType = Archetype::Archetype_Barbarian;
};

