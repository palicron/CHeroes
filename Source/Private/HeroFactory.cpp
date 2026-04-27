#include "HeroFactory.h"

#include <random>
#include "Barbarian.h"
#include "Hero.h"
#include "Mage.h"
#include "Warlock.h"
#include "Warrior.h"

const std::array<HeroArchetypeData, Archetype::Archetype_Max> HeroFactory::StatsDB = {{
	{ {80, 120}, {10, 15}, {2, 5}, {0, 100},{5, 7},{0, 1},{2, 5},{2, 5}}, // Warrior
	{ {40, 100}, {5, 10}, {10, 20}, {100, 200},{2, 5},{2, 5},{2, 5},{2, 5}}, // Mage
	{ {120, 200}, {12, 20}, {2, 4}, {0, 150},{0, 1},{0, 1},{2, 5},{2, 5}}, // Barbarian
	{ {35, 120}, {3, 9}, {9, 18}, {100, 150},{2, 5},{2, 5},{2, 5},{2, 5}}, // Warlock
	
}};
std::unique_ptr<Hero> HeroFactory::CreateHero(Archetype HeroArchetype)
{
	switch (HeroArchetype)
	{
	case Archetype::Archetype_Warrior:
		return CreateHeroTemplate<Warrior>(GetRandomStats(Archetype_Warrior));
	case Archetype::Archetype_Mage:
		return CreateHeroTemplate<Mage>(GetRandomStats(Archetype_Mage));
	case Archetype::Archetype_Barbarian:
		return CreateHeroTemplate<Barbarian>(GetRandomStats(Archetype_Barbarian));
	case Archetype::Archetype_Warlock:
		return CreateHeroTemplate<Warlock>(GetRandomStats(Archetype_Warlock));
	default: 
		return CreateHeroTemplate<Barbarian>(GetRandomStats(Archetype_Barbarian));
	}

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
	case Archetype::Archetype_Warrior:
		return "Warrior";
	case Archetype::Archetype_Mage:
		return "Mage";
	case Archetype::Archetype_Barbarian:
		return "Barbarian";
	case Archetype::Archetype_Warlock:
		return "Warlock";
	default:
		return "None";
	}
}

std::vector<std::unique_ptr<Hero>> HeroFactory::CreateInitialRoster()
{
	std::vector<std::unique_ptr<Hero>> Roster;
	Roster.reserve(4);

	//TODO Just testing creting Base Hero
	Roster.push_back(std::move(CreateHero(Archetype::Archetype_Warrior)));
	Roster.push_back(std::move(CreateHero(Archetype::Archetype_Barbarian)));
	Roster.push_back(std::move(CreateHero(Archetype::Archetype_Mage)));
	Roster.push_back(std::move(CreateHero(Archetype::Archetype_Warlock)));
	return Roster;
}

AttributeSet HeroFactory::GetRandomStats(Archetype HeroClass)
{
	if (HeroClass > StatsDB.size())
	{
		return {};
	}

	return {

		.Health = GetRandomInt(StatsDB[HeroClass].Health.first, StatsDB[HeroClass].Health.second),
		.Str = GetRandomInt(StatsDB[HeroClass].Strength.first, StatsDB[HeroClass].Strength.second),
		.Int = GetRandomInt(StatsDB[HeroClass].Intelligence.first, StatsDB[HeroClass].Intelligence.second),
		.Resource = GetRandomInt(StatsDB[HeroClass].Resource.first, StatsDB[HeroClass].Resource.second),
		.armor = GetRandomInt(StatsDB[HeroClass].Armor.first, StatsDB[HeroClass].Armor.second),
		.MgArmor = GetRandomInt(StatsDB[HeroClass].MagicArmor.first, StatsDB[HeroClass].MagicArmor.second),
		.AttackPower = GetRandomInt(StatsDB[HeroClass].AttackPower.first, StatsDB[HeroClass].AttackPower.second),
		.MagicPower = GetRandomInt(StatsDB[HeroClass].MagicPower.first, StatsDB[HeroClass].MagicPower.second)
	};
	
}
