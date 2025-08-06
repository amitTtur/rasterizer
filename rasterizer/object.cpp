#include "object.h"

unsigned int Object::count = 0;

Object::Object(Color color) : _color(color) {
	_id = count;
	count++;
}
