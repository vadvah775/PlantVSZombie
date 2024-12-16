#include "Card.h"

Card::Card() {}

Card::Card(listOfPlants typeCard)
{
	plantType = typeCard;
	switch (plantType)
	{
	case listOfPlants::PeaShooter:
	{
		setPos(440, 11);
		//54 x 76
		sprite.setTextureRect(IntRect(0, 120, 54, 76));
		reloadTime = seconds(5);
		auto spriteSize = sf::Vector2i(54, 76);
		Animator::Animation& active = animator.CreateAnimation("active", "images/Hud.png", sf::seconds(1), true);
		active.AddFrames(sf::Vector2i(0, 120), spriteSize, 0, 1);
		//задание координат где должа появлятся карта
	}
		break;
	case listOfPlants::PotatoMine:
		//задание координат где должа появлятся карта
	{
		setPos(507, 11);
		//54 x 76
		sprite.setTextureRect(IntRect(67, 120, 54, 76));
		reloadTime = seconds(10);
		auto spriteSize = sf::Vector2i(54, 76);
		Animator::Animation& active = animator.CreateAnimation("active", "images/Hud.png", sf::seconds(1), true);
		active.AddFrames(sf::Vector2i(67, 120), spriteSize, 0, 1);
	}
		break;
	case listOfPlants::CherryBomb:
		//задание координат где должа появлятся карта
	{
		setPos(574, 11);
		//54 x 76
		sprite.setTextureRect(IntRect(134, 120, 54, 76));
		reloadTime = seconds(15);
		auto spriteSize = sf::Vector2i(54, 76);
		Animator::Animation& active = animator.CreateAnimation("active", "images/Hud.png", sf::seconds(1), true);
		active.AddFrames(sf::Vector2i(134, 120), spriteSize, 0, 1);
	}
		break;
	case listOfPlants::WallNut:
		//задание координат где должа появлятся карта
	{
		setPos(641, 11);
		//54 x 76
		sprite.setTextureRect(IntRect(201, 120, 54, 76));
		reloadTime = seconds(10);
		auto spriteSize = sf::Vector2i(54, 76);
		Animator::Animation& active = animator.CreateAnimation("active", "images/Hud.png", sf::seconds(1), true);
		active.AddFrames(sf::Vector2i(201, 120), spriteSize, 0, 1);
	}
		break;
	case listOfPlants::SunFlower:
		//задание координат где должа появлятся карта
	{
		setPos(708, 11);
		//54 x 76
		sprite.setTextureRect(IntRect(268, 120, 54, 76));
		reloadTime = seconds(5);
		auto spriteSize = sf::Vector2i(54, 76);
		Animator::Animation& active = animator.CreateAnimation("active", "images/Hud.png", sf::seconds(1), true);
		active.AddFrames(sf::Vector2i(268, 120), spriteSize, 0, 1);
	}
		break;
	default:
		break;
	}
}

bool Card::getSelect() const
{
	return select;
}

bool Card::getReload() const
{
	return reload;
}

void Card::setSelect(bool s)
{
	if (s)
	{
		sprite.setColor(sf::Color::Green);
	}
	else
	{
		sprite.setColor(sf::Color::White);
	}
	select = s;
	
}

listOfPlants Card::getPlantType() const
{
	return plantType;
}

void Card::setReload(bool r)
{
	if (r)
	{
		sprite.setColor(sf::Color(66, 64, 64));
	}
	else
	{
		sprite.setColor(sf::Color::White);
	}
	reload = r;
}

void Card::show(RenderWindow& window) const
{
	window.draw(sprite);
}
void Card::update(sf::Time const& dt)
{
	if (reload)
	{
		currentTime += dt;
		if (currentTime >= reloadTime)
		{
			currentTime = sf::Time::Zero;
			setReload(false);
		}
	}

}