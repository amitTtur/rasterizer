#include "Menu.h"

Menu::Menu()
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	_fullW = static_cast<usho>(screenWidth);
	_fullH = static_cast<usho>(screenHeight);
	_bigW = static_cast<usho>(_fullW * 0.75);
	_bigH = static_cast<usho>(_fullH * 0.75);
	_medW = static_cast<usho>(_fullW * 0.6);
	_medH = static_cast<usho>(_fullH * 0.6);
	_smallW = static_cast<usho>(_fullW * 0.35);
	_smallH = static_cast<usho>(_fullH * 0.35);

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
					break;
				}
				case 1:
				{
					_screenRes = Big;
					_renderer = std::make_unique<D2_renderer>(_bigW, _bigH);
					break;
				}
				case 2:
				{
					_screenRes = Medium;
					_renderer = std::make_unique<D2_renderer>(_medW, _medH);
					break;
				}
				case 3:
				{
					_screenRes = Small;
					_renderer = std::make_unique<D2_renderer>(_smallW, _smallH);
					break;
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
	uchar option = 1;
	std::cout << "Note: all shapes are their regular form " next
		"All degrees and sides are the same sides" next
		"The only shape that isn't regualr is the N'th sides shape" << std::endl;
	while (option)
	{
		printMenu();
		option = getUserInput();

		switch (option)
		{
		case 0:
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		case 1:
		{
			getTriangleInput();
			break;
		}
		}
	}
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

Color Menu::getColorInput() const
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

Point Menu::getPointInput() const
{
	Point ret;
	std::cout << "Enter the coordinatees for the shape, the input would be in a (X,Y) format." next
		"The value range is from 0 to 65535." next
		"Entering 00 means the shape would be on the left (or top)" next
		"Entering FF means the shape would be on the right (or bottom)" << std::endl;


	std::string inp;
	size_t calInp;
	bool f = false;
	startOfLoop:
	do
	{
		std::cout << "Enter " << (f ? "Y" : "X") << " value: ";
		std::cin >> inp;
		try {
			calInp = std::stoi(inp.c_str(), 0, 10);

			if (calInp > 65535) {
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
	if (!f)
	{
		ret.setX(calInp);
		f = true;
		goto startOfLoop;
	}
	else {
		ret.setY(calInp);
		return ret;
	}
}

void Menu::getTriangleInput()
{
	// could be a one-liner
	/*std::unique_ptr<Triangle> triangle = std::make_unique<Triangle>(getColorInput(), getPointInput());
	std::unique_ptr<Object> obj = std::make_unique<Object>(triangle);
	_renderer->addShape(std::move(obj));*/

}
