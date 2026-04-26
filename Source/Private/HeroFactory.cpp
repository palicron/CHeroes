#include "HeroFactory.h"
#include "Hero.h"

std::unique_ptr<Hero> HeroFactory::CreateHero(Archetype HeroArchetype)
{
	switch (HeroArchetype) {
	case Archetype::Warrior:
		//return CreateHero<>
		break;
	case Archetype::Mage:
		break;
	case Archetype::Ranger:
		break;
	case Archetype::Warlock:
		break;
	}
	return CreateHero<Hero>();
}

std::vector<std::unique_ptr<Hero>> HeroFactory::CreateInitialRoster()
{
	std::vector<std::unique_ptr<Hero>> Roster;
	Roster.reserve(4);

	//TODO Just testing creting Base Hero
	Roster.push_back(CreateHero<Hero>());
	Roster.push_back(CreateHero<Hero>());
	Roster.push_back(CreateHero<Hero>());
	Roster.push_back(CreateHero<Hero>());

	return Roster;
}
