#pragma once
#include "Ability.h"
#include "Types.h"
#include <concepts>
#include <memory>
#include <string>
#include <vector>
#include <array>



class Hero;

class HeroFactory
{
public:

	static std::vector<std::unique_ptr<Hero>> CreateInitialRoster();

	template <typename T, typename... TArgs>
		requires std::derived_from<T, Hero>
	static std::unique_ptr<T> CreateHeroTemplate(const AttributeSet& Set);

	static std::unique_ptr<Hero> CreateHero(Archetype HeroArchetype);

	static int32_t GetRandomInt(const int32_t min, const int32_t max);

	static std::string HeroClassToString(const Archetype Class);
	
	static AttributeSet GetRandomStats(Archetype HeroClass) ;
	
	static WeaponDamage GetDamageByType(EWeaponClass WeaponClass);
	
	

private:

	static const std::array<HeroArchetypeData,Archetype::Archetype_Max> StatsDB;
	static const std::array<WeaponDamage,EWeaponClass::EWeaponClass_Max> WeaponDB;
	static const std::array<std::array<std::shared_ptr<Ability>,4>,Archetype::Archetype_Max> AbilitiesDB;
};

template <typename T, typename... TArgs>
	requires std::derived_from<T, Hero>
std::unique_ptr<T> HeroFactory::CreateHeroTemplate(const AttributeSet& Set)
{
	return std::make_unique<T>(Set);
}

