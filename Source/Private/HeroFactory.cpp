#include "HeroFactory.h"
#include "Hero.h"
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
