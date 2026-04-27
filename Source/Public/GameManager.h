#pragma once
#include <memory>
#include <vector>

#include "Hero.h"

class GameManager
{
public:

	
	~GameManager() = default;

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	static GameManager& GetInstace()
	{
		static GameManager Instance;
		return Instance;
	}

	void BeginGame();
	void GameTick();
	void EndGame();

	void DisplayHeroStats(const Hero& Inhero) const;

	bool GetIsGameRunning() const { return bIsRunning; }

private:

	GameManager() = default;
	bool bIsRunning = true;

	std::unique_ptr<Hero> PlayerHero;

	std::vector<std::unique_ptr<Hero>> HeroesRooster;
};

