#include "CherryBoom.h"

CherryBoom::CherryBoom() : CherryBoom(0, 0) {}

CherryBoom::CherryBoom(float x, float y)
{
	setPos(x, y);
	sprite.setTextureRect(IntRect(_x, _y, 100, 100)); // задать правильно координаты появления и спрайта
	hitBoxes = FloatRect(_x - 100, _y - 125, 300, 375);
	
	/*auto spriteSize = sf::Vector2i(28, 28);
	Animator::Animation& stand = animator.CreateAnimation("stand", "images/.png", sf::seconds(1), true);
	goForward.AddFrames(sf::Vector2i(5, 69), spriteSize, 1, 1);*/

	//auto spriteSize = sf::Vector2i(165, 145);
	//Animator::Animation& explosion = animator.CreateAnimation("explosion", "images/PotatoMine.png", sf::seconds(0.5), false);
	//explosion.AddFrames(sf::Vector2i(0, 273), spriteSize, 5, 1);

	_speed.x = 0;
	_speed.y = 0.;

	isCherry = true;
	_damage = 20;

	_type = EntityType::Shot;
}

FloatRect CherryBoom::getHitboxes() const
{
	return hitBoxes;
}

void CherryBoom::show(RenderWindow& window)const{}

void CherryBoom::update(sf::Time const& dt)
{
	isExisted = false;
	//if (!isMayHarm && !activate)
	//{
	//	activate = true;
	//	isCherry = false;//чтобы во время проигривания анимации взрыва не умирали зомби ещё
	//}
	/*if (activate)
	{
		animator.Update(dt);
		if (animator.getEndAnim())
		{
			isExisted = false;
		}
	}*/
}