#pragma once
#ifndef MENU_H
#define MENU_H

#define NUM_OF_FEATURES 1

#include "Input.h"
#include "defines.hpp"

#define next << std::endl <<

class Menu
{
private:
	void printMenu() const;
	uchar getUserInput() const;
	
private:
};

#endif