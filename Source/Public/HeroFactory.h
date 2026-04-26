#pragma once
#include <concepts>
#include <memory>
#include <vector>

#include "Types.h"

class Hero;

class HeroFactory
{
public:

	template <typename T, typename... TArgs>
		requires std::derived_from<T, Hero>
	static std::unique_ptr<T> CreateHero(TArgs&&... args);

	std::unique_ptr<Hero> CreateHero(Archetype HeroArchetype);

private:
	static std::vector<std::unique_ptr<Hero>> CreateInitialRoster();
};

template <typename T, typename... TArgs>
	requires std::derived_from<T, Hero>
std::unique_ptr<T> HeroFactory::CreateHero(TArgs&&... args)
{
	return std::make_unique<T>(std::forward<TArgs>(args)...);
}

