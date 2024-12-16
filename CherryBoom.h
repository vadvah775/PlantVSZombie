#pragma once
#include "Boom.h"
class CherryBoom : public Boom
{
public:
	CherryBoom();
	CherryBoom(float x, float y);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
	FloatRect getHitboxes() const override;
};

