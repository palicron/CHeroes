#include "GameManager.h"

#include <iomanip>
#include <iostream>
#include "HeroFactory.h"

void GameManager::BeginGame()
{
	std::cout << "====================================\n";
	std::cout << "   CHEROES COMBAT SIMULATOR v1.0 \n";
	std::cout << "====================================\n";

	std::vector<std::unique_ptr<Hero>> TempHeroes = HeroFactory::CreateInitialRoster();

	for (const auto& temp_hero : TempHeroes)
	{
		if (temp_hero)
		{
			DisplayHeroStats(*temp_hero);
		}
	}
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

void GameManager::DisplayHeroStats(const Hero& Inhero) const
{
    const int Width = 30;
    const std::string Line(Width, '-');

    std::cout << "\n+" << Line << "+" << std::endl;

    // Encabezado: Nombre y Clase
    std::cout << "| " << std::left << std::setw(Width - 2) << (" [" + HeroFactory::HeroClassToString(Inhero.GetHeroArchetype()) + "]") << " |" << std::endl;
    std::cout << "+" << Line << "+" << std::endl;

    // Stats Principales
    auto PrintStat = [&](std::string Label, auto Value) {
        std::cout << "| " << std::left << std::setw(15) << Label
            << ": " << std::right << std::setw(11) << Value << " |" << std::endl;
        };

    PrintStat("Vida", Inhero.GetHealth());
    PrintStat("Fuerza", Inhero.GetStrength());
    PrintStat("Inteligencia", Inhero.GetIntelligence());
    PrintStat("Rage",  Inhero.GetResource());

    std::cout << "|" << std::string(Width, ' ') << "|" << std::endl; // Espacio

    // Stats de Combate (Físico vs Mágico)
    PrintStat("Armor", Inhero.GetArmor());
    PrintStat("Magic Armor", Inhero.GetMagicArmor());
    PrintStat("Atk Power", Inhero.GetAttackPwr());
    PrintStat("Magic Power", Inhero.GetMagicPwr());

    std::cout << "+" << Line << "+\n" << std::endl;
}
