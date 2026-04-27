//CHeroes Main File

#include "GameManager.h"
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	GameManager::GetInstace().BeginGame();

	//TODO need to change this pooling for a delegate or something for the moment this should do it 
	while (GameManager::GetInstace().GetIsGameRunning())
	{
		GameManager::GetInstace().GameTick();
	}

	return 0;
}


