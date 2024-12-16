#include "Grass.h"

Grass::Grass(){}

Grass::Grass(float x, float y)
{
	_x = x;
	_y = y;
	sprite.setPosition(_x, _y);
	sprite.setTexture(AssetManager::GetTexture("images/Blank.png"));
	sprite.setTextureRect(IntRect(0, 0, 100, 125));
	sprite.setColor(sf::Color(0, 0, 0, 0));
}

void Grass::show(RenderWindow& window) const
{
	window.draw(sprite);
}

void Grass::update(sf::Time const& dt)
{

}