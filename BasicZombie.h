#pragma once
#include "Zombie.h"

//�������� ��������� ��� ��������� �� ������, ������, ������ (���-�� ��������)

class BasicZombie : public Zombie
{
	
public:
	BasicZombie();

	BasicZombie(float x, float y);

	bool collide(const Plant& op) const override;
	void collideHandling(Plant& op) override; // ��� ��������������� � ����������
	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;

};

