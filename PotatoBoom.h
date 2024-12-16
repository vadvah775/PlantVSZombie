#pragma once
#include "Boom.h"
class PotatoBoom : public Boom
{
public:
	PotatoBoom();
	PotatoBoom(float x, float y);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
};

