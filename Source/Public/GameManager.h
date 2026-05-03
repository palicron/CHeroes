#pragma once
#include <memory>
#include <string>
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
	
	bool GetIsGameRunning() const { return bIsRunning; }

	static int32_t GetCurrentTurn() { return GetInstace().CurrentTurn; }
private:
	
	int32_t CurrentTurn = 0;
	int32_t OpponentIndex = 0;
	GameManager() = default;
	bool bIsRunning = true;

	std::unique_ptr<Hero> PlayerHero;
	std::unique_ptr<Hero> OpponentHero;
	
	std::vector<std::unique_ptr<Hero>> HeroesRooster;
	
	void DisplayHeroStats(const Hero& Inhero) const;
	void PrintHeroBox(const Hero& Inhero);
	void PrintAbilityBox(const Hero& Inhero);

	void SelectOpponent();
	
	std::string GenerateProgressBar(int value, int max, char symbol);
};

