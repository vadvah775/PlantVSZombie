#pragma once
#include "Movable.h"
class Sun : public Movable
{
private:
	int value = 25;
	sf::Time currentTime = sf::Time::Zero;
	sf::Time disappearTime = sf::seconds(5);//через 5 секунд солнышко исчезнет
	bool isFall = false;//проверяет упало ли солнышко на землю и если да то начинает обратный отсчёт для его исчезновения
	float y_fall = 200;//(200,600)позиция по y куда может призимлиться солнышко
public:
	Sun(); // для спавна солнышек с неба
	Sun(float x, float y); // для солнышек от подсолнухов

	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;

	int getValue() const;
};

