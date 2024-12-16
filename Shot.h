#pragma once
#include "Movable.h"
//#include "Entities.h"

class Shot : public Movable
{
protected:
	int _damage = 1;


public:
	int numberOfLawn = 0;

	bool isMine = false;
	bool isCherry = false;
	bool isMayHarm = true;
	bool explosion_animation = false;//�� ������ � isBoom?, ��� ��� ���� ��� �������������� �������� ������ � �� �� ��� ��� shot ��� �������

	int getDamage() const;

	Shot();
	Shot(float x, float y);
};

