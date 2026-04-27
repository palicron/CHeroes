#pragma once
#include "MeleeHero.h"
class Hero;
class Barbarian :public MeleeHero
{

public:
	virtual Archetype GetHeroArchetype() const override
	{
		return CurrentType;
	}

private:

	Archetype CurrentType = Archetype::Barbarian;
};

