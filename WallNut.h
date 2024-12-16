#pragma once
#include "Plant.h"
class WallNut : public Plant
{
public:
	WallNut();
	WallNut(float x, float y);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
};

