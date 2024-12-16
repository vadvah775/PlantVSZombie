#pragma once
#include "Movable.h"
#include "Entities.h"



class Zombie : public Movable
	//уже есть текстура и позицмя, что нужно ещё???
	//здоровье
{
protected:
	int _hp = 1;
	int _damage = 1;
	sf::Time speedEat = sf::seconds(1);
	sf::Time currentTime = sf::Time::Zero;
	void takeDamage(int damge);

	//FloatRect hitBoxes = FloatRect(0, 0, 125, 185);

	bool timeToEat(sf::Time dt);
	Plant* eatPlant;//если что-то крашнется, то скорее всего из-за этого :|

public:
	//Plant* eatPlant; //в протектед
	int numberOfLawn = 0; //номер поляны по которой идёт зомби
	bool isEat = false;
	bool isMove = true;
	bool isDead = false;
	
	//переопределение хитбокса(нужно)
	FloatRect getHitboxes() const override;

	//переопредление движиния, так как нужно учитывать хитбокс
	virtual void move(float dt) override;

	//обработка получения урона
	virtual void takeShot(Shot& s);//пока что определяется прям в zombie

	bool isAlive() const;
	int getDamage() const;
	//возвращает true если была коллиизия с объектом Plant op
	virtual bool collide(const Plant& op) const = 0;
	//virtual bool collide(const Shot& op) const = 0; нет ещё реализации класса
	virtual void collideHandling(Plant& op) = 0;
	//virtual void collideHandling(Shot& op); нет ещё реализации класса

	Zombie();
	Zombie(float x, float y);

	//Zombie(const Zombie&) = delete;
	//void operator=(const Zombie&) = delete;
};

