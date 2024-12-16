#pragma once
#include "Entity.h"

class Movable : public Entity
{
protected:
	sf::Vector2f _speed{ 0, 0 };
	sf::FloatRect hitBoxes;
public:
	bool isExisted = true;
	//возможно добавить ещё координаты в которых хранится предыдущее значение
	//чтобы при столкновении откатывать объект назад и он не накладывался на другой
	Movable();
	Movable(float x, float y);




	

	virtual void move(float time);
};

