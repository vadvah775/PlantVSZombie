#include "Plant.h"

Plant::Plant() {};

Plant::Plant(float x, float y) {
	_x = x;
	_y = y;
}

int Plant::getNumberOfLawn()
{
	return numberOfLawn;
}

void Plant::setNumberOfLawn(int num)//ну можно добавить фильтр что num валидный
{
	numberOfLawn = num;
}

void Plant::setCell(Cell& cell)
{
	landCell = &cell;
}

void Plant::takeDamage(int damage)
{
	_hp -= damage;
}

bool Plant::isAlive() const
{
	return _hp > 0;
}

std::optional<std::unique_ptr<Shot>> Plant::shot(Zombie& z)
{
	return std::nullopt;
}

void Plant::collideHandling(Zombie & op)
{

}

bool Plant::collide(const Zombie& op) const
{
	return false;
}

FloatRect Plant::getHitboxes() const
{
	return hitBoxes;
}

bool Plant::generate()
{
	return false;
}
