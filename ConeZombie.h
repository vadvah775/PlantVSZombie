#pragma once
#include "Zombie.h"


class ConeZombie : public Zombie
{
public:
	ConeZombie();

	ConeZombie(float x, float y);

	bool collide(const Plant& op) const override;
	void collideHandling(Plant& op) override; // для соприкосновения с растениями
	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;
};

