#include "MapManager.h"

#include <iostream>

MapManager::MapManager()
{
	/*text.setCharacterSize(20);
	text.setFont(AssetManager::GetFont("Texts/CyrilicOld.ttf"));
	text.setString("0");
	text.setPosition(200, 200);*/
	font.loadFromFile("Texts/CyrilicOld.ttf");
	text.setCharacterSize(25);
	text.setFont(font);
	text.setString(std::to_string(countSuns));
	text.setFillColor(sf::Color::Black);
	text.setPosition(370, 65);
	//для баланса того какой уровень столько времени и идут зомби
	endGameTime = sf::seconds(60 + 3 * level);
}

void MapManager::MapLoader(uint16_t idx)
{
	for (int i = 0; i < _map.height; i++)
	{
		for (int j = 0; j < _map.width; j++)
		{
			//Сейчас все клекти это трава, поэтому даже не создаю тайлмап для них
			auto temp = std::make_unique<Grass>(325 + j * 100, 100 + i * 125);
			temp->setNumberOfLawn(i);
			_map._data.push_back(std::move(temp));

		}
	}
}

void MapManager::CardsLoader()
{
	//создание карточек для всех растений
	//создание карточки PeaShooter
	auto temp1 = std::make_unique<Card>(listOfPlants::PeaShooter);
	Cards.push_back(std::move(temp1));
	//создание карточки PotatoMine
	auto temp2 = std::make_unique<Card>(listOfPlants::PotatoMine);
	Cards.push_back(std::move(temp2));
	//создание карточки SunFlower
	auto temp3 = std::make_unique<Card>(listOfPlants::SunFlower);
	Cards.push_back(std::move(temp3));
	//создание карточки CherryBomb
	auto temp4 = std::make_unique<Card>(listOfPlants::CherryBomb);
	Cards.push_back(std::move(temp4));
	//создание карточки WallNut
	auto temp5 = std::make_unique<Card>(listOfPlants::WallNut);
	Cards.push_back(std::move(temp5));
}



const Map& MapManager::getMap()
{
	return _map;
}

std::list<std::unique_ptr<Card>>& MapManager::getCards()
{
	return Cards;
}

std::list<std::unique_ptr<Sun>>& MapManager::getSuns()
{
	return onMapSuns;
}

void MapManager::putPlant(Vector2f pos, std::list<std::unique_ptr<Plant>>& onMapPlants)
{
	for (auto &i : _map._data)
	{
		//проверяем что мышь находится в нужной позиции(то есть в области клетки)
		if (i->sprite.getGlobalBounds().contains(pos))
		{
			if (i->isEmpty)//ну тут не знай, если добавить ещё землю то всё переделывать надо будет 
			{
				switch (plant)
				{
				case listOfPlants::PeaShooter:
				{
					auto temp = std::make_unique<PeaShooter>(i->sprite.getPosition().x, i->sprite.getPosition().y);
					temp->setNumberOfLawn(i->getNumberOfLawn());
					temp->setCell(*i);
					onMapPlants.push_back(std::move(temp));
					i->isEmpty = false;
					cardReload(plant);//установка перезарядки карты
					//resetCardSelection(plant);
					plant = listOfPlants::NotPlant;
					countSuns -= 100;
					return;
					break;
				}
				case listOfPlants::SunFlower:
				{
					auto temp = std::make_unique<SunFlower>(i->sprite.getPosition().x, i->sprite.getPosition().y);
					temp->setNumberOfLawn(i->getNumberOfLawn());
					temp->setCell(*i);
					onMapPlants.push_back(std::move(temp));
					i->isEmpty = false;
					cardReload(plant);//установка перезарядки карты
					//resetCardSelection(plant);
					plant = listOfPlants::NotPlant;
					countSuns -= 50;
					return;
					break;
				}
				case listOfPlants::WallNut:
				{
					auto temp = std::make_unique<WallNut>(i->sprite.getPosition().x, i->sprite.getPosition().y);
					temp->setNumberOfLawn(i->getNumberOfLawn());
					temp->setCell(*i);
					onMapPlants.push_back(std::move(temp));
					i->isEmpty = false;
					cardReload(plant);//установка перезарядки картыы
					//resetCardSelection(plant);
					plant = listOfPlants::NotPlant;
					countSuns -= 50;
					return;
					break;
				}
					
				case listOfPlants::PotatoMine:
				{
					auto temp = std::make_unique<PotatoMine>(i->sprite.getPosition().x, i->sprite.getPosition().y);
					temp->setNumberOfLawn(i->getNumberOfLawn());
					temp->setCell(*i);
					onMapPlants.push_back(std::move(temp));
					i->isEmpty = false;
					cardReload(plant);//установка перезарядки карты
					//resetCardSelection(plant);
					plant = listOfPlants::NotPlant;
					countSuns -= 25;
					return;
					break;
				}
				case listOfPlants::CherryBomb:
				{
					auto temp = std::make_unique<CherryBomb>(i->sprite.getPosition().x, i->sprite.getPosition().y);
					temp->setNumberOfLawn(i->getNumberOfLawn());
					temp->setCell(*i);
					onMapPlants.push_back(std::move(temp));
					i->isEmpty = false;
					cardReload(plant);//установка перезарядки карты
					//resetCardSelection(plant);
					plant = listOfPlants::NotPlant;
					countSuns -= 150;
					return;
					break;
				}
				default:
					break;
				}
				//auto temp = std::make_unique<PeaShooter>(PeaShooter(i->sprite.getPosition().x, i->sprite.getPosition().y));
				/*auto temp = std::make_unique<CherryBomb>(i->sprite.getPosition().x, i->sprite.getPosition().y);
				temp->setNumberOfLawn(i->getNumberOfLawn());
				temp->setCell(*i);
				onMapPlants.push_back(std::move(temp));
				i->isEmpty = false;*/
			}
		}
	}
}

void MapManager::chooseCard(Vector2f pos)
{
	for (auto& i : Cards)
	{
		//на основании того где находится pos выбирать plant
		if (i->getHitboxes().contains(pos) && !i->getReload())
		{
			if (plant == listOfPlants::NotPlant)
			{
				if (haveEnoughSuns(i->getPlantType()))
				{
					plant = i->getPlantType();
					i->setSelect(true);
				}
			}
			else if (plant != i->getPlantType())
			{
				if (haveEnoughSuns(i->getPlantType()))
				{
					resetCardSelection(plant);
					plant = i->getPlantType();
					i->setSelect(true);
				}
			}
			else if (plant == i->getPlantType())
			{
				i->setSelect(false);
				plant = listOfPlants::NotPlant;
			}
		}
		
	}

	
}

void MapManager::resetCardSelection(listOfPlants resetCard)
{
	for (auto& i : Cards)
	{
		if (i->getPlantType() == resetCard)
		{
			i->setSelect(false);
			break;
		}
	}
}

void MapManager::cardReload(listOfPlants card)
{
	for (auto& i : Cards)
	{
		if (i->getPlantType() == card)
		{
			i->setReload(true);
		}
	}
}

void MapManager::setCardSelection(listOfPlants setCard)
{
	for (auto& i : Cards)
	{
		if (i->getPlantType() == setCard)
		{
			i->setSelect(true);
			break;
		}
	}
}

void MapManager::cellLight(Vector2f pos)
{
	for (auto& i : _map._data)
	{
		if (i->getHitboxes().contains(pos) && plant != listOfPlants::NotPlant && i->isEmpty)
		{
			i->setSpriteColor(true);
		}
		else
		{
			i->setSpriteColor(false);
		}
	}
}

void MapManager::addSun(sf::Time const& dt)
{
	currentTimeSun += dt;
	if (currentTimeSun > sunTimer)
	{
		auto temp = std::make_unique<Sun>();
		onMapSuns.push_back(std::move(temp));
		currentTimeSun = sf::Time::Zero;
	}
}

void MapManager::clickOnSun(Vector2f pos)
{
	for (auto& i : onMapSuns)
	{
		if (i->getHitboxes().contains(pos))
		{
			countSuns += i->getValue();
			i->isExisted = false;
			break;
		}
	}
}

Text MapManager::getTextCountOfSuns()
{
	return text;
}

void  MapManager::updateText(sf::Time const& dt)
{
	text.setString(std::to_string(countSuns));
}

bool MapManager::haveEnoughSuns(listOfPlants card) const
{
	switch (card)
	{
	case listOfPlants::PeaShooter:
		return countSuns >= 100;
		break;
	case listOfPlants::SunFlower:
		return countSuns >= 50;
		break;
	case listOfPlants::WallNut:
		return countSuns >= 50;
		break;
	case listOfPlants::PotatoMine:
		return countSuns >= 25;
		break;
	case listOfPlants::CherryBomb:
		return countSuns >= 150;
		break;
	default:
		return false;
		break;
	}
}

void MapManager::generatePlantObject(Plant& op)
{
	if (op.generate())
	{
		auto temp = std::make_unique<Sun>(op.getHitboxes().left, op.getHitboxes().top);
		onMapSuns.push_back(std::move(temp));
	}
}

void MapManager::setLevel(int l)
{
	level = l;
}

void MapManager::spawnZombie(sf::Time dt, std::list<std::unique_ptr<Zombie>>& onMapZombies)
{
	currentTime += dt;
	spawnTime -= dt;
	if (currentTime >= endGameTime && onMapZombies.size() == 0)
	{
		
		std::cout << "you win\n";
		win = true;
	}
	/*if (spawnTime < sf::Time::Zero && currentTime < endGameTime)
	{
		spawnTime = sf::seconds(5);
		while (zombiePoints >= 1)
		{
			int random = rand() % 4;
			switch (random)
			{
			case(0):
			{
				if (zombiePoints >= 4)
				{
					auto temp = std::make_unique<BucketZombie>();
					onMapZombies.push_back(std::move(temp));
					zombiePoints -= 4;
					break;
				}
			}
			case(1):
			{
				if (zombiePoints >= 3)
				{
					auto temp = std::make_unique<PoleZombie>();
					onMapZombies.push_back(std::move(temp));
					zombiePoints -= 3;
					break;
				}
			}
			case(2):
			{
				if (zombiePoints >= 2)
				{
					auto temp = std::make_unique<ConeZombie>();
					onMapZombies.push_back(std::move(temp));
					zombiePoints -= 2;
					break;
				}
			}
			case(3):
			{
				if (zombiePoints >= 1)
				{
					auto temp = std::make_unique<BasicZombie>();
					onMapZombies.push_back(std::move(temp));
					zombiePoints -= 1;
					break;
				}
			}
			default:
				break;
			}
		}
		zombiePoints = currentTime.asSeconds() * level / 10;
	}*/

	if (spawnTime < sf::Time::Zero && currentTime < endGameTime)
	{
		spawnTime = seconds(5);
		int random = rand() % 4;
		switch (random)
		{
		case(0):
		{
			if (zombiePoints >= 4)
			{
				auto temp = std::make_unique<BucketZombie>();
				onMapZombies.push_back(std::move(temp));
				zombiePoints -= 4;
			}
			break;
		}
		case(1):
		{
			if (zombiePoints >= 3)
			{
				auto temp = std::make_unique<PoleZombie>();
				onMapZombies.push_back(std::move(temp));
				zombiePoints -= 3;
			}
			break;
		}
		case(2):
		{
			if (zombiePoints >= 2)
			{
				auto temp = std::make_unique<ConeZombie>();
				onMapZombies.push_back(std::move(temp));
				zombiePoints -= 2;
			}
			break;
		}
		case(3):
		{
			if (zombiePoints >= 1)
			{
				auto temp = std::make_unique<BasicZombie>();
				onMapZombies.push_back(std::move(temp));
				zombiePoints -= 1;
			}
			break;
		}
		default:
			break;
		}
		zombiePoints += currentTime.asSeconds() * level / 10;
	}
}

bool MapManager::getWin()
{
	return win;
}