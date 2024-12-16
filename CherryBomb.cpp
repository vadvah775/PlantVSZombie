#include "CherryBomb.h"

CherryBomb::CherryBomb() : CherryBomb(0, 0) {}

CherryBomb::CherryBomb(float x, float y)
{
	hitBoxes = FloatRect(x, y, 100, 100);
	setPos(x, y + 40);
	sprite.setTextureRect(IntRect(_x, _y, 100, 100));

	auto spriteSize = sf::Vector2i(100, 81);
	Animator::Animation& load = animator.CreateAnimation("load", "images/CherryBomb.png", sf::seconds(1), false);
	load.AddFrames(sf::Vector2i(0, 0), spriteSize, 7, 1);

	//дл€ взрыва(пока что использует взрыв от картошки)
	spriteSize = sf::Vector2i(165, 120);
	Animator::Animation& explosion = animator.CreateAnimation("explosion", "images/CherryBomb.png", sf::seconds(0.5), false);
	explosion.AddFrames(sf::Vector2i(0, 111), spriteSize, 2, 1);


	_hp = 10;// объ€вл€ть по умолчанию в h файле

	_type = EntityType::Plant;
}

void CherryBomb::show(RenderWindow& window)const
{
	window.draw(sprite);
}

void CherryBomb::update(sf::Time const& dt)
{
	//надо подумать 
	if (!isAlive()) landCell->isEmpty = true;
	if (readyToExplode)
	{
		if (animator.getEndAnim())
		{
			_hp = -1;
			landCell->isEmpty = true;
		}
	}
	else if (!readyToExplode && animator.getEndAnim())
	{
		readyToExplode = true;
		animator.SwitchAnimation("explosion");
		sprite.setPosition(_x - 20, _y - 40);
		hitBoxes = FloatRect(0, 0, 0, 0);
	}
	animator.Update(dt);
}

std::optional<std::unique_ptr<Shot>> CherryBomb::shot(Zombie& z)
{
	if (animator.getEndAnim() && !readyToExplode)
	{
		animator.SwitchAnimation("explosion");
		readyToExplode = true;
		auto it = std::make_unique<CherryBoom>(_x, _y - 40);
		it->numberOfLawn = numberOfLawn;
		hitBoxes = FloatRect(0, 0, 0, 0);
		return std::move(it);
	}
	return std::nullopt;
}