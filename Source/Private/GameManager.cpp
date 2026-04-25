#include "GameManager.h"
#include <iostream>

void GameManager::BeginGame()
{
	std::cout << "====================================\n";
	std::cout << "   CHEROES COMBAT SIMULATOR v1.0 \n";
	std::cout << "====================================\n";

	std::cout << "Input a number to Start the game \n";
	uint32_t InNumber;

	std::cin >> InNumber;

}

void GameManager::GameTick()
{
	std::cout << "Input a number To next Turn a letter to end the game\n";
	uint32_t InNumber;

	if (std::cin >> InNumber)
	{
		std::cout << "Turn \n";
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		EndGame();
	}

	
}

void GameManager::EndGame()
{
	std::cout << "Bye\n";
	bIsRunning = false;
}
