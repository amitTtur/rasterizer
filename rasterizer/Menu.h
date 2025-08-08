#pragma once
#ifndef MENU_H
#define MENU_H

#define NUM_OF_FEATURES 1
#define SDL_MAIN_HANDLED


#include <windows.h>
#include <map>

#include "Input.h"
#include "2dRenderer.h"


#define next << std::endl <<

enum ScreenRes {
	Full = 0,
	Big = 1,
	Medium = 2,
	Small = 3
};

typedef struct {
	ScreenRes _screenRes;
	// size, {width,height}
	std::map<ScreenRes, std::pair<usho, usho>> _sizes;
} ScreenSizes;

class Menu
{
public:
	Menu();
	void cycle();
private:
	std::unique_ptr<D2_renderer> _renderer;
	void printMenu() const;
	uchar getUserInput() const;

	// inputs
	Color getColorInput() const;
	Point getPointInput();

	void getTriangleInput();

	// screen width
	ScreenSizes _screenSizes;
};

#endif