#include "Boom.h"

Boom::Boom() : Boom(0, 0) {}

Boom::Boom(float x, float y)
{
	//setPos(x + 10, y + 26);
	//sprite.setTextureRect(IntRect(_x, _y, 100, 100)); // задать правильно координаты появления и спрайта


	/*auto spriteSize = sf::Vector2i(28, 28);
	Animator::Animation& stand = animator.CreateAnimation("stand", "images/.png", sf::seconds(1), true);
	goForward.AddFrames(sf::Vector2i(5, 69), spriteSize, 1, 1);*/

	/*auto spriteSize = sf::Vector2i(22, 22);
	Animator::Animation& explosion = animator.CreateAnimation("splats", "images/pea_splats.png", sf::seconds(0.5), false);
	explosion.AddFrames(sf::Vector2i(0, 0), spriteSize, 4, 1);

	_speed.x = 0;
	_speed.y = 0.;

	isMine = true;
	_damage = 20;

	_type = EntityType::Shot;*/
}

bool Boom::getActivate() const
{
	return activate;
}