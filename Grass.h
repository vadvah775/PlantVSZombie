#pragma once
#include"Cell.h"
#include"AssetManager.h"

class Grass : public Cell
{
public:
	Grass();
	Grass(float x, float y);

	bool isEmpty = true;

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
};

