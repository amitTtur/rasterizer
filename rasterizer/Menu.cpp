#include "Menu.h"

Menu::Menu()
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	_fullW = DM.w;
	_fullH = DM.h;
	_bigW = _fullW * 0.75;
	_bigH = _fullH * 0.75;
	_medW = _fullW * 0.6;
	_medH = _fullH * 0.6;
	_smallW = _fullW * 0.35;
	_smallH = _fullH * 0.35;

	std::cout << "Enter a screen resolution" next
		"[0] Full screen (" << _fullW << "x" << _fullH << ")" next
		"[1] Big screen (" << _bigW << "x" << _bigH << ")" next
		"[2] Medium screen (" << _medW << "x" << _medH << ")" next
		"[3] Small screen (" << _smallW << "x" << _smallH << ")" << std::endl;
	std::string inp;
	do {
		std::cout << "Enter value: ";
		std::cin >> inp;
		if (checkInt(inp) && checkInputBuffer())
		{
			int tmp = std::stoi(inp.c_str(), 0, 10);
			if (tmp <= 3 && tmp >= 0) {
				switch (tmp)
				{
				case 0:
				{
					_screenRes = Full;
					_renderer = std::make_unique<D2_renderer>(_fullW, _fullH);
				}
				case 1:
				{
					_screenRes = Big;
					_renderer = std::make_unique<D2_renderer>(_bigW, _bigH);
				}
				case 2:
				{
					_screenRes = Medium;
					_renderer = std::make_unique<D2_renderer>(_medW, _medH);
				}
				case 3:
				{
					_screenRes = Small;
					_renderer = std::make_unique<D2_renderer>(_smallW, _smallH);
				}
				}
				break;
			}
			std::cout << "Invalid input... Please enter a value within the valid range." <<
				std::endl;
		}
		else
		{
			std::cout << "Invalid input... Try again." << std::endl;
		}
	} while (true);
	cycle();
}

void Menu::cycle()
{

}

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

Color Menu::getColorInput()
{
	Color ret;
	std::cout << "Enter the color for the shape, the input would be in a RGBA format."
		"Enter The value in Hexadecimal format (ex: #FF00EEFF)"
		"Entering 00 means the color would be dimmer (for alpha transparent)" next
		"Entering FF means the color would be brighter (for alpha opaque)" << std::endl;
	
	std::string inp;
	size_t calInp;
	do
	{
		std::cout << "Enter value: ";
		std::cin >> inp;
		try {
			calInp = std::stoi(inp.c_str(), 0, 16);

			if (calInp > 4294967295) {
				std::cout << "Invalid input... The input value is higher then requested.";
			}
			else break;
		}
		catch (...)
		{	
			std::cout << "Invalid input... Please enter in a hexadecimal format.";
		}
		checkInputBuffer();
	} while (true);

	ret.a = calInp & 0xFF;
	ret.b = calInp & 0xFF00;
	ret.g = calInp & 0xFF0000;
	ret.r = calInp & 0xFF000000;

	//
	return ret;
}

void Menu::getRectangleInput()
{
	Point p1, p2, p3;
	 
}
