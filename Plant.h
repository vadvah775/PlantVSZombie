#pragma once
#include "Entity.h"
#include "Entities.h"
#include <optional>

class Shot;

class Plant : public Entity
{
protected:
	int _hp = 1;
	int numberOfLawn = 0;//номер поляны на котором находится растение
	Cell* landCell; //указатель на клетку, где находится растение

	//хитбокс Растения
	FloatRect hitBoxes = FloatRect(0, 0, 100, 100);

public:

	Plant();
	Plant(float x, float y);
	//факт того что растение явл генератором чего-то(конкретно солнышек)
	bool isGenerate = false;
	virtual bool generate();

	void takeDamage(int damage);
	bool isAlive() const;

	bool isPlanted; //скорее всего не нужно будет(факт того что растение посажено на поле)
	
	//возвращает true если была коллиизия с объектом Zombie op
	virtual bool collide(const Zombie& op) const;

	virtual void collideHandling(Zombie& op);

	//переопределение хитбокса
	FloatRect getHitboxes() const override;

	virtual std::optional<std::unique_ptr<Shot>> shot(Zombie& z);

	int getNumberOfLawn();
	void setNumberOfLawn(int n);
	void setCell(Cell& cell);
};

