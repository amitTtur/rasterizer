#include "Menu.h"

Menu::Menu()
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	_screenSizes._sizes[ScreenRes::Full] = { static_cast<usho>(screenWidth),static_cast<usho>(screenHeight) };
	_screenSizes._sizes[ScreenRes::Big] = { static_cast<usho>(screenWidth * 0.75),static_cast<usho>(screenHeight * 0.75) };
	_screenSizes._sizes[ScreenRes::Medium] = { static_cast<usho>(screenWidth * 0.55),static_cast<usho>(screenHeight * 0.55) };
	_screenSizes._sizes[ScreenRes::Small] = { static_cast<usho>(screenWidth * 0.35),static_cast<usho>(screenHeight * 0.35) };

	std::cout << "Enter a screen resolution" next
		"[0] Full screen (" << _screenSizes._sizes[ScreenRes::Full].first << "x" << _screenSizes._sizes[ScreenRes::Full].second << ")" next
		"[1] Big screen (" << _screenSizes._sizes[ScreenRes::Big].first << "x" << _screenSizes._sizes[ScreenRes::Big].second << ")" next
		"[2] Medium screen (" << _screenSizes._sizes[ScreenRes::Medium].first << "x" << _screenSizes._sizes[ScreenRes::Medium].second << ")" next
		"[3] Small screen (" << _screenSizes._sizes[ScreenRes::Small].first << "x" << _screenSizes._sizes[ScreenRes::Small].second << ")" << std::endl;
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
					_screenSizes._screenRes = Full;
					break;
				}
				case 1:
				{
					_screenSizes._screenRes = Big;
					break;
				}
				case 2:
				{
					_screenSizes._screenRes = Medium;
					break;
				}
				case 3:
				{
					_screenSizes._screenRes = Small;
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
	_renderer = std::make_unique<D2_renderer>(_screenSizes._sizes[_screenSizes._screenRes].first,
		_screenSizes._sizes[_screenSizes._screenRes].second);
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
		"";

}

uchar Menu::getUserInput() const
{
	while (true)
	{
		printMenu();
		std::cout << "Enter: ";
		std::string inp;
		std::cin >> inp;
		if (!(checkInputBuffer() && checkInt(inp)))
		{
			std::cout << "Invalid input... Try again." next std::endl;
		}
		else
		{
			uchar tmp = std::stoi(inp,0,10);
			if (tmp >= 0 && tmp <= NUM_OF_FEATURES)
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
		"Enter The value in Hexadecimal format (ex: #RRGGBBAA)"
		"Entering 00 means the color would be dimmer (for alpha transparent)" next
		"Entering FF means the color would be brighter (for alpha opaque)" << std::endl;
	
	std::string inp;
	size_t calInp;
	do
	{
		std::cout << "Enter value: ";
		std::cin >> inp;

		if (checkInputBuffer() && checkHex(inp))
		{
			if (!inp.empty()) {
				if (inp[0] == '#') {
					inp.erase(0, 1);
				}
				else if (inp.size() >= 2 && (inp[0] == '0') && (inp[1] == 'x' || inp[1] == 'X')) {
					inp.erase(0, 2);
				}
			}

			calInp = std::stoul(inp.c_str(), 0, 16);
			if (calInp > 4294967295) {
				std::cout << "Invalid input... The input value is higher then requested." << std::endl;
			}
			else break;
		}
		else { std::cout << "Invalid input... Please enter in a hexadecimal format." << std::endl; }	
	} while (true);

	ret.r = (calInp >> 24) & 0xFF;
	ret.g = (calInp >> 16) & 0xFF;
	ret.b = (calInp >> 8) & 0xFF;
	ret.a = calInp & 0xFF;

	std::cout << "Red value selected is: " << std::to_string(ret.r) next
		"Green value selected is: " << std::to_string(ret.g) next
		"Blue value selected is: " << std::to_string(ret.b) next
		"Alpha value selected is: " << std::to_string(ret.a) next "";

	//
	return ret;
}

Point Menu::getPointInput()
{
	Point ret;
	std::cout next "Enter the coordinatees for the shape, the input would be in a (X,Y) format." next
		"The value range for the width is from 0 to " << _screenSizes._sizes[_screenSizes._screenRes].first << "." next
		"The value range for the height is from 0 to " << _screenSizes._sizes[_screenSizes._screenRes].second << "." next
		"Entering 0 means the shape would be on the left (or top)" next
		"Entering  means the shape would be on the right (or bottom)" << std::endl;


	std::string inp;
	size_t calInp;
	bool f = false;
	startOfLoop:
	do
	{
		std::cout << "Enter " << (f ? "Y" : "X") << " value: ";
		std::cin >> inp;
		if ((checkInputBuffer() && checkInt(inp))){
			calInp = std::stoi(inp.c_str(), 0, 10);

			if ((!f && ((calInp > _screenSizes._sizes[_screenSizes._screenRes].first) || (calInp < 0))) ||
				(f && ((calInp > _screenSizes._sizes[_screenSizes._screenRes].second) || (calInp < 0)))) {
				std::cout << "Invalid input... The input value is higher then requested.";
			}
			else break;
		}
		else { std::cout << "Invalid input... Try again." << std::endl; }
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
	std::unique_ptr<Object> obj = std::make_unique<Triangle>(getColorInput(), getPointInput());
	_renderer->addShape(std::move(obj));
}
