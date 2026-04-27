#pragma once
#include <concepts>
#include <memory>
#include <string>
#include <vector>

#include "Types.h"

class Hero;

class HeroFactory
{
public:

	static std::vector<std::unique_ptr<Hero>> CreateInitialRoster();

	template <typename T, typename... TArgs>
		requires std::derived_from<T, Hero>
	static std::unique_ptr<T> CreateHeroTemplate(TArgs&&... args);

	static std::unique_ptr<Hero> CreateHero(Archetype HeroArchetype);

	static int32_t GetRandomInt(const int32_t min, const int32_t max);

	static std::string HeroClassToString(const Archetype Class);

private:
	
};

template <typename T, typename... TArgs>
	requires std::derived_from<T, Hero>
std::unique_ptr<T> HeroFactory::CreateHeroTemplate(TArgs&&... args)
{
	return std::make_unique<T>(std::forward<TArgs>(args)...);
}

