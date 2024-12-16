#pragma once
#include "Shot.h"
class Pea : public Shot
{
protected:

public:
	Pea();
	Pea(float x, float y);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;

};

