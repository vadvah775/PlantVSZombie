#include "Zombie.h"


Zombie::Zombie(){}

Zombie::Zombie(float x, float y) {
	_x = x;
	_y = y;
}

void Zombie::takeDamage(int damage)
{
	_hp -= damage;
}

int Zombie::getDamage() const
{
	return _damage;
}

bool Zombie::isAlive() const
{
	return _hp > 0;
}

bool Zombie::timeToEat(sf::Time dt)
{
	currentTime += dt;
	if (currentTime > speedEat)
	{
		currentTime = sf::Time::Zero;
		return true;
	}
}

void Zombie::takeShot(Shot& s)
{
	if (getHitboxes().intersects(s.getHitboxes()))
	{
		if (numberOfLawn == s.numberOfLawn && s.isMayHarm && !s.isMine && !s.isCherry)
		{
			takeDamage(s.getDamage());
			s.isMayHarm = false;
		}
		else if (s.isMine && numberOfLawn == s.numberOfLawn)
		{
			takeDamage(s.getDamage());
			s.isMayHarm = false; // уже используется для того чтобы во время update удалить объект
		}
		else if (s.isCherry && abs(numberOfLawn - s.numberOfLawn) < 2)
		{
			takeDamage(s.getDamage());
			s.isMayHarm = false;
		}
	}
}

void Zombie::move(float time)
{
	_x = _x + _speed.x * time;
	_y = _y + _speed.y * time;
	sprite.setPosition(_x, _y);
	hitBoxes.left = _x + 30;//если у разных зомби будет разный хит бокс то сделать 
	//переопредление отдельно в каждом зомби
}

FloatRect Zombie::getHitboxes() const
{
	return hitBoxes;
}



