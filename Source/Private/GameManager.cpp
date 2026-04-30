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
	std::vector<std::string> HeroClasses;
	for (const auto& temp_hero : TempHeroes)
	{
		if (temp_hero)
		{
			HeroClasses.push_back(HeroFactory::HeroClassToString(temp_hero->GetHeroArchetype()));
			DisplayHeroStats(*temp_hero);
		}
	}
	bool Selected = false;
	
	std::cout << "====================================\n";
	std::cout << "Select a Hero to fight \n";
	std::cout << "====================================\n";
	
	while (!Selected)
	{
		int i = 0;
		for (const std::string& HeroClass : HeroClasses)
		{
			std::cout << (i + 1) << ". " << HeroClass <<  "\n";
			i++;
		}
		uint32_t InNumber;
		if (std::cin >> InNumber && InNumber > 0 && InNumber <= HeroClasses.size())
		{
			Selected = true;
			std::cout << "====================================\n";
			std::cout << "You Select a : " << HeroClasses[InNumber - 1] << "\n";
			std::cout << "====================================\n";

			PlayerHero = std::move(TempHeroes[InNumber - 1]);

			for (auto& hero : TempHeroes)
			{
				if (hero)
				{
					HeroesRooster.push_back(std::move(hero));
				}
			}
			TempHeroes.clear();
		}
		else
		{
			std::cout << "====================================\n";
			std::cout << "Invalid Entry.\n";
			std::cout << "====================================\n";
			std::cout << "Select a Hero to fight \n";
			std::cout << "====================================\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}

	std::cout << "Now playing as :  \n";
	std::cout << "====================================\n";
	PrintHeroBox(*PlayerHero);
	std::cout << "====================================\n";
	
	SelectOpponent();
	std::cout << "fighting :  \n";
	std::cout << "====================================\n";
	PrintHeroBox(*OpponentHero);
	std::cout << "====================================\n";
	
	CurrentTurn = 0;
}

void GameManager::GameTick()
{

	std::cout << "Input A number for actions\n";
	uint32_t InNumber;

	if (std::cin >> InNumber)
	{
		std::system("cls");
		PlayerHero->MeleeAttack(*OpponentHero);
		OpponentHero->MeleeAttack(*PlayerHero);
		std::cout << "====================================\n";
		PrintHeroBox(*PlayerHero);
		std::cout << "====================================\n";
		std::cout << "====================================\n";
		PrintHeroBox(*OpponentHero);
		std::cout << "====================================\n";
		std::cout << "Turn \n";
		if (PlayerHero->GetHealth() <= 0)
		{
			std::cout << "====================================\n";
			std::cout << "You Die!!!!!!!!"" :  \n";
			std::cout << "====================================\n";
			EndGame();
			return;
		}
		else if (OpponentHero->GetHealth() <= 0)
		{
			SelectOpponent();
		}
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		EndGame();
	}
	CurrentTurn++;
}
void GameManager::SelectOpponent()
{
	if (OpponentIndex >= HeroesRooster.size())
	{
		std::cout << "====================================\n";
		std::cout << "No more Enemies you WIN!"" :  \n";
		std::cout << "====================================\n";
		OpponentIndex = 0;
		EndGame();
		return;
	}
	
	OpponentHero = std::move(HeroesRooster[OpponentIndex]);
	OpponentIndex++;
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

    std::cout << "\n+" << Line << "+" << "\n";

    // Encabezado: Nombre y Clase
    std::cout << "| " << std::left << std::setw(Width - 2) << (" [" + HeroFactory::HeroClassToString(Inhero.GetHeroArchetype()) + "]") << " |" << "\n";
    std::cout << "+" << Line << "+" << "\n";

    // Stats Principales
    auto PrintStat = [&](std::string Label, auto Value) {
        std::cout << "| " << std::left << std::setw(15) << Label
            << ": " << std::right << std::setw(11) << Value << " |" << std::endl;
        };

    PrintStat("Vida", Inhero.GetHealth());
    PrintStat("Fuerza", Inhero.GetStrength());
    PrintStat("Inteligencia", Inhero.GetIntelligence());
    PrintStat("Rage",  Inhero.GetResource());

    std::cout << "|" << std::string(Width, ' ') << "|" << "\n"; 

    // Stats de Combate (F�sico vs M�gico)
    PrintStat("Armor", Inhero.GetArmor());
    PrintStat("Magic Armor", Inhero.GetMagicArmor());
    PrintStat("Atk Power", Inhero.GetAttackPwr());
    PrintStat("Magic Power", Inhero.GetMagicPwr());

    std::cout << "+" << Line << "+\n" << "\n";
}

void GameManager::PrintHeroBox(const Hero& Inhero)
{
	std::cout << "┌──────────────────────────────────────────┐" << "\n";
	std::cout << "│  CLASS: " << HeroFactory::HeroClassToString(Inhero.GetHeroArchetype()) << std::string(33 - HeroFactory::HeroClassToString(Inhero.GetHeroArchetype()).length(), ' ') << "│" << "\n";
	std::cout << "├──────────────────────────────────────────┤" << "\n";
    
	// Fila de Vida
	std::cout << "│  HP  : " << Inhero.GetHealth() << "  " << GenerateProgressBar(Inhero.GetHealth(), Inhero.GetMaxHealth(),'=') << "  │" << "\n";
    
	// Fila de Recurso
	std::cout << "│  RES : " << Inhero.GetResource() << "  " << GenerateProgressBar(Inhero.GetResource(), Inhero.GetMaxResource(), '=') << "  │" << "\n";
	std::cout << "────────────────────────────────────────────" << "\n";
	
	if (Inhero.GetEquippedWeapon())
	{
		std::cout << "────────────────────────────────────────────" << "\n";
		std::cout << Inhero.GetEquippedWeapon()->ToString() << "\n";
		std::cout << "────────────────────────────────────────────" << "\n";
	}
    
	std::cout << "└──────────────────────────────────────────┘" << "\n";
}


std::string GameManager::GenerateProgressBar(int value, int max, char symbol)
{
	std::string bar = "";
	// Calculamos cuántos segmentos llenar
	float percentage = static_cast<float>(value) / max;
	int filledSegments = static_cast<int>(percentage * 20);

	for (int i = 0; i < 20; ++i) {
		if (i < filledSegments) bar += symbol;
		else bar += '='; // Fondo de la barra
	}
	return "[" + bar + "]";
}
