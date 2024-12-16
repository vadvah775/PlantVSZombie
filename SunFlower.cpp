#include "SunFlower.h"

SunFlower::SunFlower() : SunFlower(0, 0) {}

SunFlower::SunFlower(float x, float y)
{
	setPos(x, y);
	sprite.setTextureRect(IntRect(_x, _y, 100, 100));
	auto spriteSize = sf::Vector2i(100, 100);
	Animator::Animation& stand = animator.CreateAnimation("stand", "images/SunFlower.png", sf::seconds(1.5), true);
	stand.AddFrames(sf::Vector2i(0, 0), spriteSize, 36, 1);
	_hp = 10; // поменять константами в классе и использовать их
	isGenerate = true;
	hitBoxes = FloatRect(_x, _y, 100, 100);
	_type = EntityType::Plant;
}

void SunFlower::show(RenderWindow& window)const
{
	window.draw(sprite);
}


void SunFlower::update(sf::Time const& dt)
{

	if (!isAlive()) landCell->isEmpty = true;
	currentTime += dt;
	animator.Update(dt);
}

bool SunFlower::generate()
{
	if (currentTime >= sunTime)
	{
		currentTime = sf::Time::Zero;
		return true;
	}
}