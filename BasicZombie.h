#pragma once
#include "Zombie.h"

//добавить константы для отрисовки из тайтла, ширину, высоту (кол-во спрайтов)

class BasicZombie : public Zombie
{
	
public:
	BasicZombie();

	BasicZombie(float x, float y);

	bool collide(const Plant& op) const override;
	void collideHandling(Plant& op) override; // для соприкосновения с растениями
	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;

};

