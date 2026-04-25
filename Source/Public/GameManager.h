#pragma once
class GameManager
{
public:

	GameManager() = default;
	~GameManager() = default;

	void BeginGame();
	void GameTick();
	void EndGame();

	bool GetIsGameRunning() const { return bIsRunning; }
private:

	bool bIsRunning = true;
};

