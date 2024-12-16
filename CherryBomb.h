#pragma once
#include "Plant.h"
#include "CherryBoom.h"

class CherryBomb : public Plant
{
protected:
	//не к чему так как можно отслеживать через то закончилась ли анимация
	//sf::Time reloadingTime = sf::seconds(4); 
	//sf::Time currentTime = sf::Time::Zero;


	bool boomIsPlanting = false; // как будто лишнее
	bool readyToExplode = false;
public:
	CherryBomb();
	CherryBomb(float x, float y);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
	std::optional<std::unique_ptr<Shot>> shot(Zombie& z) override;
};

