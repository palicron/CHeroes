//CHeroes Main File
#include <iostream>
#include "GameManager.h"

int main()
{
	std::unique_ptr<GameManager> GM = std::make_unique<GameManager>();

	GM->BeginGame();

	//TODO need to change this pooling for a delegate or something for the moment this should do it 
	while (GM->GetIsGameRunning())
	{
		GM->GameTick();
	}

	return 0;
}


