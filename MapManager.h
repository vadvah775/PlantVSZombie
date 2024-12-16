#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

#include"CherryBomb.h"
#include"PotatoMine.h"
#include"SunFlower.h"
#include"WallNut.h"
#include"PeaShooter.h"
#include"Grass.h"
#include"Sun.h"

#include"PoleZombie.h"
#include"BucketZombie.h"
#include"ConeZombie.h"
#include"BasicZombie.h"

#include "Entities.h"
#include <vector>
#include<list>

#include "Card.h"

using namespace sf;



struct Map
{
	Map() = default;

	int width = 9, height = 5;

	std::vector<std::unique_ptr<Cell>> _data;
};

class MapManager
{
private:
	Map _map;//уровень на котором находимся в данный момент
	//список карточек с растениями
	std::list<std::unique_ptr<Card>> Cards;
	//даёт понять какое растение в данный момент выбрано для посадки
	listOfPlants plant = listOfPlants::NotPlant; 
	//список солнышек на карте
	std::list<std::unique_ptr<Sun>> onMapSuns;
	//таймер для спавна солнышка на карте
	sf::Time sunTimer = sf::seconds(5);
	sf::Time currentTimeSun = sf::Time::Zero;
	//таймер для спавна зомби
	sf::Time currentTime = sf::Time::Zero;
	sf::Time spawnTime = sf::seconds(5);
	sf::Time endGameTime = sf::seconds(60);

	void resetCardSelection(listOfPlants resetCard);
	void setCardSelection(listOfPlants setCard);
	//текст для отображения солнышек
	//Text text("", AssetManager::GetFont("CyrilicOld.ttf"), 20);
	Text text;
	Font font;
	int level = 1;
	float zombiePoints = 1;

	//выйграл ли игрок
	bool win = false;
public:
	MapManager();
	void MapLoader(uint16_t idx);
	const Map& getMap();
	std::list<std::unique_ptr<Sun>>& getSuns();
	std::list<std::unique_ptr<Card>>& getCards();
	void addSun(sf::Time const& dt);
	//обработка того что солнышко было собрано
	void clickOnSun(Vector2f pos);
	//количество солнышек
	int countSuns = 100;
	void putPlant(Vector2f pos, std::list<std::unique_ptr<Plant>>& onMapPlants);
	//по позиции мыши выбирает растение для посадки
	void chooseCard(Vector2f pos);//можно сделать так чтобы возвращало true если было выбрано другое растение
	//загрузка карт на карту
	void CardsLoader();
	//подстветка клеток если выбрано растение
	void cellLight(Vector2f pos);
	Text getTextCountOfSuns();
	//обновления текста отвечающего за кол-во солнышек
	void updateText(sf::Time const& dt);
	bool haveEnoughSuns(listOfPlants card) const;
	//отправление карты на перезарядку
	void cardReload(listOfPlants card);
	//для создание объекто которые были воспроизведены растиями и которые не являются shot
	void generatePlantObject(Plant& op);
	void setLevel(int l);
	//для спавна зомби
	void spawnZombie(sf::Time dt, std::list<std::unique_ptr<Zombie>>& onMapZombies);
	//Возвращает значение выйграл ли игрок
	bool getWin();
};

