#include "PotatoBoom.h"

PotatoBoom::PotatoBoom() : PotatoBoom(0, 0) {}

PotatoBoom::PotatoBoom(float x, float y)
{
	setPos(x + 10, y + 26);
	sprite.setTextureRect(IntRect(_x, _y, 100, 100)); // задать правильно координаты появления и спрайта


	/*auto spriteSize = sf::Vector2i(28, 28);
	Animator::Animation& stand = animator.CreateAnimation("stand", "images/.png", sf::seconds(1), true);
	goForward.AddFrames(sf::Vector2i(5, 69), spriteSize, 1, 1);*/

	auto spriteSize = sf::Vector2i(165, 145);
	Animator::Animation& explosion = animator.CreateAnimation("explosion", "images/PotatoMine.png", sf::seconds(0.5), false);
	explosion.AddFrames(sf::Vector2i(0, 273), spriteSize, 5, 1);

	_speed.x = 0;
	_speed.y = 0.;

	isMine = true;
	_damage = 20;

	_type = EntityType::Shot;
}

void PotatoBoom::show(RenderWindow& window)const
{
	if (activate)
	{
		window.draw(sprite);
	}
}

void PotatoBoom::update(sf::Time const& dt)
{
	if (!isMayHarm && !activate)
	{
		activate = true;
		isMine = false;//чтобы во время проигривания анимации взрыва не умирали зомби ещё
		//sprite.setTextureRect(IntRect(_x - 50, _y - 50, 100, 100));
		setPos(_x - 50, _y - 50);
	}
	if (activate)
	{
		animator.Update(dt);
		if (animator.getEndAnim())
		{
			isExisted = false;
		}
	}
}