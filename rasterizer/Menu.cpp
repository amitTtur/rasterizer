#include "Menu.h"

void Menu::printMenu() const
{
	std::cout <<
		"Menu: " next
		"[1] Create triangle instance." next 
		"[0] Exit." next
		std::endl;


}

uchar Menu::getUserInput() const
{
	while (true)
	{
		printMenu();

		std::string inp;
		std::cin >> inp;
		if (checkInputBuffer() || checkInt(inp))
		{
			std::cout << "Invalid input... Try again." next std::endl;
		}
		else
		{
			uchar tmp = std::stoi(inp,0,10);
			if (tmp > 0 && tmp <= NUM_OF_FEATURES)
			{
				return tmp;
			}
			else
			{
				std::cout << "Input not within range... Try again." next std::endl;
			}
		}
	}
}
