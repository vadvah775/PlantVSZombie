#include "Movable.h"

#include <iostream>//лишнее

Movable::Movable() { _x = 0; _y = 0;}

Movable::Movable(float x, float y)
{
	_x = x;
	_y = y;
}

void Movable::move(float time)
{
	_x = _x + _speed.x * time;
	_y = _y + _speed.y * time;
	sprite.setPosition(_x, _y);
}


