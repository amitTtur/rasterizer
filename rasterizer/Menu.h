#pragma once
#ifndef MENU_H
#define MENU_H

#define NUM_OF_FEATURES 1
#define SDL_MAIN_HANDLED


#include <windows.h>

#include "Input.h"
#include "2dRenderer.h"


#define next << std::endl <<

enum ScreenRes {
	Full = 0,
	Big = 1,
	Medium = 2,
	Small = 3
};

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
	Point getPointInput() const;

	void getTriangleInput();

	// screen width
	ScreenRes _screenRes;
	usho _fullW;
	usho _fullH;
	usho _bigW;
	usho _bigH;
	usho _medW;
	usho _medH;
	usho _smallW;
	usho _smallH;

};

#endif