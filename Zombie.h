#pragma once
#include "Movable.h"
#include "Entities.h"



class Zombie : public Movable
	//��� ���� �������� � �������, ��� ����� ���???
	//��������
{
protected:
	int _hp = 1;
	int _damage = 1;
	sf::Time speedEat = sf::seconds(1);
	sf::Time currentTime = sf::Time::Zero;
	void takeDamage(int damge);

	//FloatRect hitBoxes = FloatRect(0, 0, 125, 185);

	bool timeToEat(sf::Time dt);
	Plant* eatPlant;//���� ���-�� ���������, �� ������ ����� ��-�� ����� :|

public:
	//Plant* eatPlant; //� ���������
	int numberOfLawn = 0; //����� ������ �� ������� ��� �����
	bool isEat = false;
	bool isMove = true;
	bool isDead = false;
	
	//��������������� ��������(�����)
	FloatRect getHitboxes() const override;

	//�������������� ��������, ��� ��� ����� ��������� �������
	virtual void move(float dt) override;

	//��������� ��������� �����
	virtual void takeShot(Shot& s);//���� ��� ������������ ���� � zombie

	bool isAlive() const;
	int getDamage() const;
	//���������� true ���� ���� ��������� � �������� Plant op
	virtual bool collide(const Plant& op) const = 0;
	//virtual bool collide(const Shot& op) const = 0; ��� ��� ���������� ������
	virtual void collideHandling(Plant& op) = 0;
	//virtual void collideHandling(Shot& op); ��� ��� ���������� ������

	Zombie();
	Zombie(float x, float y);

	//Zombie(const Zombie&) = delete;
	//void operator=(const Zombie&) = delete;
};

