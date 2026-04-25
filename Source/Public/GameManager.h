#pragma once
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

private:

	GameManager() = default;
	bool bIsRunning = true;
};

