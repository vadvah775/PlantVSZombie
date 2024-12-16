#pragma once
#include "Entity.h"
#include "Entities.h"
//#include "MapManager.h"

class Card : public Entity
{
protected:
	bool select = false;
	bool reload = false;
	listOfPlants plantType = listOfPlants::NotPlant;
	sf::Time reloadTime; // для перезарядки растения
	sf::Time currentTime = sf::Time::Zero;
public:
	Card();
	Card(listOfPlants cardType);

	bool getSelect() const;
	bool getReload() const;
	void setSelect(bool s);
	void setReload(bool r);

	listOfPlants getPlantType() const;

	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;
};

