#include "PotatoMine.h"


PotatoMine::PotatoMine() : PotatoMine(0, 0) {}

PotatoMine::PotatoMine(float x, float y)
{
	setPos(x, y);
	sprite.setTextureRect(IntRect(_x, _y, 100, 100));

	auto spriteSize = sf::Vector2i(100, 100);
	Animator::Animation& buried = animator.CreateAnimation("buried", "images/BuriedPotatoMine.png", sf::seconds(2), true);
	buried.AddFrames(sf::Vector2i(0, 85), spriteSize, 1, 1);

	spriteSize = sf::Vector2i(100, 100);
	Animator::Animation& stand = animator.CreateAnimation("stand", "images/PotatoMineSign.png", sf::seconds(2), true);
	stand.AddFrames(sf::Vector2i(0, 85), spriteSize, 29, 1);


	_hp = 10;// объ€вл€ть по умолчанию в h файле
	hitBoxes = FloatRect(_x + 30, _y, 49, 95);

	_type = EntityType::Plant;
}

void PotatoMine::show(RenderWindow& window)const
{
	window.draw(sprite);
}


void PotatoMine::update(sf::Time const& dt)
{
	if (!isAlive()) landCell->isEmpty = true;
	if (!readyToExplode)
	{
		currentTime += dt;
		if (currentTime > reloadingTime)
		{
			readyToExplode = true;
			animator.SwitchAnimation("stand");
		}
	}
	if (readyToExplode && boom && boom->getActivate())
	{
		_hp = -1;
		landCell->isEmpty = true;
	}
	animator.Update(dt);
}

std::optional<std::unique_ptr<Shot>> PotatoMine::shot(Zombie& z)
{
	if (readyToExplode && !boomIsPlanting)
	{
		auto it = std::make_unique<PotatoBoom>(_x, _y);
		it->numberOfLawn = numberOfLawn;
		boomIsPlanting = true;
		setBoom(*it);
		return std::move(it);
	}
	return std::nullopt;
}

void PotatoMine::setBoom(Boom& b)
{
	boom = &b;
}