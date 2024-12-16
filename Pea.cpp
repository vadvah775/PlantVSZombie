#include "Pea.h"

#include <iostream>//лишнее

Pea::Pea() : Pea(0, 0) {}

Pea::Pea(float x, float y) // передаются left и top от _scope
{
	setPos(x, y + 15);
	sprite.setTextureRect(IntRect(_x, _y, 20, 20)); // задать правильно координаты появления и спрайта


	auto spriteSize = sf::Vector2i(28, 28);
	Animator::Animation& goForward = animator.CreateAnimation("goForward", "images/Peas.png", sf::seconds(1), true);
	goForward.AddFrames(sf::Vector2i(5, 69), spriteSize, 1, 1);

	spriteSize = sf::Vector2i(22, 22);
	Animator::Animation& splats = animator.CreateAnimation("splats", "images/pea_splats.png", sf::seconds(0.5), false);
	splats.AddFrames(sf::Vector2i(0, 0), spriteSize, 4, 1);

	_speed.x = 0.3;
	_speed.y = 0.;

	_type = EntityType::Shot;
}

void Pea::update(sf::Time const& dt)
{
	float time = dt.asMicroseconds();
	time = time / 800;
	if (isMayHarm)
	{
		move(time);
	}
	if (!isMayHarm && !explosion_animation)
	{
		explosion_animation = true;
		animator.SwitchAnimation("splats");
	}

	animator.Update(dt);

	if (animator.getEndAnim())
	{
		isExisted = false;
	}
	if (_x > 1400)
	{
		isExisted = false;
	}
}

void Pea::show(RenderWindow& window) const
{
	window.draw(sprite);
}



