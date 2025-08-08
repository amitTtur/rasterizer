#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <string>

enum STATE_INPUT
{
	INPUT_BAD_VALUE = 0,
	INPUT_GOOD_VALUE = 1
};

STATE_INPUT checkInputBuffer();


// doesnt support parsing an input or scientific values as of now 
STATE_INPUT checkInt(const std::string& inp);

STATE_INPUT checkHex(const std::string& inp);


#endif // !INPUT_H
