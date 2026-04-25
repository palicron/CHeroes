//CHeroes Main File
#include <iostream>

int main()
{
	bool bIsRunning = true;

	std::cout << "====================================\n";
	std::cout << "   CHEROES COMBAT SIMULATOR v1.0 \n";
	std::cout << "====================================\n";

	while (bIsRunning)
	{
		std::cout << "Input a number to end the game\n";
		uint32_t TemporalChoise;

		if ((std::cin >> TemporalChoise))
		{
			bIsRunning = false;
		}
		else
		{
			std::cout <<" Not a number Try again\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
	std::cout << "Bye\n";
	return 0;
}


