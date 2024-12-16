#pragma once
#include "Zombie.h"
class BucketZombie : public Zombie
{
public:
	BucketZombie();

	BucketZombie(float x, float y);

	bool collide(const Plant& op) const override;
	void collideHandling(Plant& op) override; // ��� ��������������� � ����������
	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;
};

