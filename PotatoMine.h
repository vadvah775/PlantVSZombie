#pragma once
#include "Plant.h"
#include "PotatoBoom.h"

class PotatoMine : public Plant
{
protected:
	sf::Time reloadingTime = sf::seconds(4);
	sf::Time currentTime = sf::Time::Zero;

	Boom *boom;

	bool boomIsPlanting = false;
	bool readyToExplode = false;
public:
	PotatoMine();
	PotatoMine(float x, float y);

	void setBoom(Boom& b);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
	std::optional<std::unique_ptr<Shot>> shot(Zombie& z) override;
};

