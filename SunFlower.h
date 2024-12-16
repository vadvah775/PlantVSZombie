#pragma once
#include "Plant.h"
class SunFlower : public Plant
{
protected:
	bool generate() override;
	sf::Time currentTime = sf::Time::Zero;
	sf::Time sunTime = sf::seconds(7.5);
public:

	SunFlower();
	SunFlower(float x, float y);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
};

