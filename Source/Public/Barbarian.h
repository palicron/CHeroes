#pragma once
#include "MeleeHero.h"
class Hero;
class Barbarian :public MeleeHero
{

public:
	
	Barbarian() : MeleeHero(){}
	Barbarian(const AttributeSet& Set) : MeleeHero(Set){}
	
	virtual Archetype GetHeroArchetype() const override
	{
		return CurrentType;
	}

private:

	Archetype CurrentType = Archetype::Archetype_Barbarian;
};

