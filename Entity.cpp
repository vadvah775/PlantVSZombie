#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	_x = 0;
	_y = 0;
}

Entity::Entity(float x, float y) 
{
	_x = x;
	_y = y;
}

Vector2f Entity::getPos() const{
	return { _x, _y };
}

FloatRect Entity::getHitboxes() const
{
	return sprite.getGlobalBounds();
}

EntityType Entity::getType() const
{
	return _type;
}

void Entity::setPos(float x, float y)
{
	_x = x;
	_y = y;
	sprite.setPosition(_x, _y);
}
