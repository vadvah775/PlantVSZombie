#include "Cell.h"

Cell::Cell(){}

Cell::Cell(float x, float y)
{
	_x = x;
	_y = y;
}

int Cell::getNumberOfLawn()
{
	return numberOfLawn;
}

void Cell::setNumberOfLawn(int num)//ну можно добавить фильтр что num валидный
{
	numberOfLawn = num;
}

void Cell::setSpriteColor(bool col)
{
	if (col)
	{
		sprite.setColor(sf::Color(0, 0, 0, 125));
	}
	else
	{
		sprite.setColor(sf::Color(0,0,0,0));
	}
}