#include "Shot.h"

Shot::Shot() {};

Shot::Shot(float x, float y) : Movable(x, y)
{
	_x = x;
	_y = y;
}

int Shot::getDamage() const
{
	return _damage;
}