#include "HeroFactory.h"

#include <random>

#include "Ability.h"
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

const std::array<WeaponDamage,EWeaponClass::EWeaponClass_Max> HeroFactory::WeaponDB = {{
	{"unarmed",1,10}, //Unarm
	{"Sword",3,15}, //Sword 
	{"Axe",8,12}, //Axe
	{"Staff",4,10}, //Staff
	{"Wand",1,5}, //Wand
}};

std::array<std::array<std::shared_ptr<Ability>, 4>, Archetype::Archetype_Max> HeroFactory::AbilitiesDB = {
	{
		{
			std::make_shared<Ability>("Slash", 2, 10, 25, EDamageAttribute::Slashing, DamageType::Physical),
			std::make_shared<Ability>("Bash", 4, 20, 15, EDamageAttribute::bludgeoning, DamageType::Physical),
			std::make_shared<Ability>("Cleave", 3, 15, 30, EDamageAttribute::Slashing, DamageType::Physical),
			std::make_shared<Ability>("Berserk", 6, 50, 0, EDamageAttribute::Slashing, DamageType::Physical)
		},

		{
			std::make_shared<Ability>("Fireball", 15, 25, 40, EDamageAttribute::Fire, DamageType::Magic),
			std::make_shared<Ability>("Ice Lance", 10, 18, 35, EDamageAttribute::Ice, DamageType::Magic),
			std::make_shared<Ability>("Arcane Burst", 20, 35, 25, EDamageAttribute::None, DamageType::Magic),
			std::make_shared<Ability>("Healing Light", 18, 30, 0, EDamageAttribute::None, DamageType::Healing)
		},
		{
			std::make_shared<Ability>("Axe Chop", 3, 18, 25, EDamageAttribute::Slashing, DamageType::Physical),
			std::make_shared<Ability>("Skull Bash", 5, 25, 15, EDamageAttribute::bludgeoning, DamageType::Physical),
			std::make_shared<Ability>("Rage Strike", 8, 40, 10, EDamageAttribute::Slashing, DamageType::Physical),
			std::make_shared<Ability>("Whirlwind", 10, 55, 5, EDamageAttribute::Slashing, DamageType::Physical)
		},
		{
			std::make_shared<Ability>("Shadow Bolt", 12, 22, 35, EDamageAttribute::Poison, DamageType::Magic),
			std::make_shared<Ability>("Soul Drain", 18, 28, 25, EDamageAttribute::Poison, DamageType::Magic),
			std::make_shared<Ability>("Dark Pact", 10, 20, 0, EDamageAttribute::None, DamageType::Healing),
			std::make_shared<Ability>("Hellfire", 25, 45, 15, EDamageAttribute::Fire, DamageType::Magic)
		}
	}

};

std::unique_ptr<Hero> HeroFactory::CreateHero(Archetype HeroArchetype)
{
	
	std::unique_ptr<Hero> Hero = nullptr;
	switch (HeroArchetype)
	{
	case Archetype::Archetype_Warrior:
		Hero = CreateHeroTemplate<Warrior>(GetRandomStats(Archetype_Warrior));
		break;
	case Archetype::Archetype_Mage:
		Hero = CreateHeroTemplate<Mage>(GetRandomStats(Archetype_Mage));
		break;
	case Archetype::Archetype_Barbarian:
		Hero = CreateHeroTemplate<Barbarian>(GetRandomStats(Archetype_Barbarian));
		break;
	case Archetype::Archetype_Warlock:
		Hero = CreateHeroTemplate<Warlock>(GetRandomStats(Archetype_Warlock));
		break;
	default:
		Hero = CreateHeroTemplate<Barbarian>(GetRandomStats(Archetype_Barbarian));
		
	}
	Hero->EquipAWeapon();
	Hero->SetAbility(AbilitiesDB[HeroArchetype]);
	return Hero;
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

	AttributeSet NewAttribute = {

		.Health = GetRandomInt(StatsDB[HeroClass].Health.first, StatsDB[HeroClass].Health.second),
		.Str = GetRandomInt(StatsDB[HeroClass].Strength.first, StatsDB[HeroClass].Strength.second),
		.Int = GetRandomInt(StatsDB[HeroClass].Intelligence.first, StatsDB[HeroClass].Intelligence.second),
		.Resource = GetRandomInt(StatsDB[HeroClass].Resource.first, StatsDB[HeroClass].Resource.second),
		.armor = GetRandomInt(StatsDB[HeroClass].Armor.first, StatsDB[HeroClass].Armor.second),
		.MgArmor = GetRandomInt(StatsDB[HeroClass].MagicArmor.first, StatsDB[HeroClass].MagicArmor.second),
		.AttackPower = GetRandomInt(StatsDB[HeroClass].AttackPower.first, StatsDB[HeroClass].AttackPower.second),
		.MagicPower = GetRandomInt(StatsDB[HeroClass].MagicPower.first, StatsDB[HeroClass].MagicPower.second)
	};

	switch (HeroClass) {
	case Archetype_Warrior:
		NewAttribute.weapon_class = EWeaponClass_Sword;
		break;
	case Archetype_Mage:
		NewAttribute.weapon_class = EWeaponClass_Staff;
		break;
	case Archetype_Barbarian:
		NewAttribute.weapon_class = EWeaponClass_Axe;
		break;
	case Archetype_Warlock:
		NewAttribute.weapon_class = EWeaponClass_Wand;
		break;
	case Archetype_Max:
		break;
	}
	
	return NewAttribute;
	
}

WeaponDamage HeroFactory::GetDamageByType(EWeaponClass WeaponClass)
{
	if (WeaponClass < 0 || WeaponClass > WeaponDB.size())
	{
		//If invalid Don equip a weapon
		return WeaponDB[0];
	}

	return WeaponDB[WeaponClass];
}


