#pragma once
#include "Zombie.h"
class PoleZombie : public Zombie
{
public:
	PoleZombie();

	PoleZombie(float x, float y);

	bool collide(const Plant& op) const override;
	void collideHandling(Plant& op) override; // ��� ��������������� � ����������
	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;

	void move(float dt) override;

	//����� ����������� ����� �� ����� ��������� ������
	bool havePole = true;
	bool playingJump = false;
};

