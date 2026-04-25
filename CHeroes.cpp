//CHeroes Main File
#include <iostream>
#include "GameManager.h"

int main()
{
	GameManager::GetInstace().BeginGame();

	//TODO need to change this pooling for a delegate or something for the moment this should do it 
	while (GameManager::GetInstace().GetIsGameRunning())
	{
		GameManager::GetInstace().GameTick();
	}

	return 0;
}


