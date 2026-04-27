#pragma once
#include "MeleeHero.h"

class Hero;

class Warrior : public MeleeHero
{
public:

	virtual void MeleeAttack(Hero& Target) override;

	virtual Archetype GetHeroArchetype() const override
	{
		return CurrentType;
	}

private:

	Archetype CurrentType = Archetype::Warrior;
};

