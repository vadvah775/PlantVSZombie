#pragma once
#include "Plant.h"
#include <iostream>
class PeaShooter : public Plant
{
private:
	sf::FloatRect _scope;
	sf::Time attackSpeed = sf::seconds(1);//для баланса поменять(сделать больше)
	sf::Time currentTime = sf::Time::Zero;

	bool timeToShoot(sf::Time dt);

public:
	PeaShooter();
	PeaShooter(float x, float y);
	~PeaShooter() = default;

	bool collide(const Zombie& op) const override;

	void collideHandling(Zombie& op) override;
	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
	std::optional<std::unique_ptr<Shot>> shot(Zombie& z) override;
};

