#include "WallNut.h"


WallNut::WallNut() : WallNut(0, 0){}

WallNut::WallNut(float x, float y) // передаются координаты ячейки
{
	setPos(x, y);
	sprite.setTextureRect(IntRect(_x, _y, 100, 100));

	auto spriteSize = sf::Vector2i(100, 100);

	Animator::Animation& stand = animator.CreateAnimation("stand", "images/WallNut.png", sf::seconds(1), true);
	stand.AddFrames(sf::Vector2i(0, 0), spriteSize, 1, 1);

	Animator::Animation&  cracked1 = animator.CreateAnimation("cracked1", "images/WallNutCracked1.png", sf::seconds(1), true);
	cracked1.AddFrames(sf::Vector2i(0, 0), spriteSize, 1, 1);

	Animator::Animation& cracked2 = animator.CreateAnimation("cracked2", "images/WallNutCracked2.png", sf::seconds(1), true);
	cracked2.AddFrames(sf::Vector2i(0, 0), spriteSize, 1, 1);

	_hp = 20; // поменять константами в классе WallNut и использовать их
	hitBoxes = FloatRect(_x, _y, 100, 100);
	_type = EntityType::Plant;
}

void WallNut::show(RenderWindow& window) const 
{
	window.draw(sprite);
}

void WallNut::update(sf::Time const& dt)
{
	if (!isAlive()) landCell->isEmpty = true;
	if (_hp < 15 && _hp > 5)
	{
		animator.SwitchAnimation("cracked1");
	}
	else if (_hp <= 5)
	{
		animator.SwitchAnimation("cracked2");
	}
	animator.Update(dt);
}
