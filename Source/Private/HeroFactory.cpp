#include "HeroFactory.h"

#include <random>
#include "Barbarian.h"
#include "Hero.h"
#include "Warrior.h"

std::unique_ptr<Hero> HeroFactory::CreateHero(Archetype HeroArchetype)
{
	switch (HeroArchetype)
	{
	case Archetype::Warrior:

		//TODO CHEKC THE ARGUMENT

		/*return CreateHeroTemplate<Warrior>(GetRandomInt(50, 120), GetRandomInt(6, 10), GetRandomInt(2, 5), 0,
		                           GetRandomInt(4, 7), GetRandomInt(0, 1),
		                           GetRandomInt(8, 11), GetRandomInt(0, 2));*/

		return CreateHeroTemplate<Warrior>();
		
	case Archetype::Mage:
		return CreateHeroTemplate<Barbarian>();
	case Archetype::Barbarian:
		/*return CreateHeroTemplate<Barbarian>(GetRandomInt(80, 200), GetRandomInt(3, 5), GetRandomInt(2, 3), 0,
		                             GetRandomInt(2, 4), GetRandomInt(0, 1),
		                             GetRandomInt(4, 9), GetRandomInt(0, 2));*/

		return CreateHeroTemplate<Barbarian>();
		
	case Archetype::Warlock:
		return CreateHeroTemplate<Barbarian>();
	}
	return CreateHeroTemplate<Barbarian>();
}

int32_t HeroFactory::GetRandomInt(const int32_t min, const int32_t max)
{
	static std::random_device RD;
	static std::mt19937 Engine(RD());
	std::uniform_int_distribution<int32_t> Dist(min, max);

	return Dist(Engine);
}

std::string HeroFactory::HeroClassToString(const Archetype Class)
{
	switch (Class)
	{
	case Archetype::Warrior:
		return "Warrior";
	case Archetype::Mage:
		return "Mage";
	case Archetype::Barbarian:
		return "Barbarian";
	case Archetype::Warlock:
		return "Warlock";

	default:
		return "None";
	}
}

std::vector<std::unique_ptr<Hero>> HeroFactory::CreateInitialRoster()
{
	std::vector<std::unique_ptr<Hero>> Roster;
	Roster.reserve(4);
	auto NewHero = CreateHero(Archetype::Warrior);
	auto NewHero2 = CreateHero(Archetype::Barbarian);
	//TODO Just testing creting Base Hero
	Roster.push_back(std::move(NewHero));
	Roster.push_back(std::move(NewHero2));
	

	return Roster;
}
