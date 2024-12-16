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
	Map _map;//������� �� ������� ��������� � ������ ������
	//������ �������� � ����������
	std::list<std::unique_ptr<Card>> Cards;
	//��� ������ ����� �������� � ������ ������ ������� ��� �������
	listOfPlants plant = listOfPlants::NotPlant; 
	//������ �������� �� �����
	std::list<std::unique_ptr<Sun>> onMapSuns;
	//������ ��� ������ �������� �� �����
	sf::Time sunTimer = sf::seconds(5);
	sf::Time currentTimeSun = sf::Time::Zero;
	//������ ��� ������ �����
	sf::Time currentTime = sf::Time::Zero;
	sf::Time spawnTime = sf::seconds(5);
	sf::Time endGameTime = sf::seconds(60);

	void resetCardSelection(listOfPlants resetCard);
	void setCardSelection(listOfPlants setCard);
	//����� ��� ����������� ��������
	//Text text("", AssetManager::GetFont("CyrilicOld.ttf"), 20);
	Text text;
	Font font;
	int level = 1;
	float zombiePoints = 1;

	//������� �� �����
	bool win = false;
public:
	MapManager();
	void MapLoader(uint16_t idx);
	const Map& getMap();
	std::list<std::unique_ptr<Sun>>& getSuns();
	std::list<std::unique_ptr<Card>>& getCards();
	void addSun(sf::Time const& dt);
	//��������� ���� ��� �������� ���� �������
	void clickOnSun(Vector2f pos);
	//���������� ��������
	int countSuns = 100;
	void putPlant(Vector2f pos, std::list<std::unique_ptr<Plant>>& onMapPlants);
	//�� ������� ���� �������� �������� ��� �������
	void chooseCard(Vector2f pos);//����� ������� ��� ����� ���������� true ���� ���� ������� ������ ��������
	//�������� ���� �� �����
	void CardsLoader();
	//���������� ������ ���� ������� ��������
	void cellLight(Vector2f pos);
	Text getTextCountOfSuns();
	//���������� ������ ����������� �� ���-�� ��������
	void updateText(sf::Time const& dt);
	bool haveEnoughSuns(listOfPlants card) const;
	//����������� ����� �� �����������
	void cardReload(listOfPlants card);
	//��� �������� ������� ������� ���� �������������� �������� � ������� �� �������� shot
	void generatePlantObject(Plant& op);
	void setLevel(int l);
	//��� ������ �����
	void spawnZombie(sf::Time dt, std::list<std::unique_ptr<Zombie>>& onMapZombies);
	//���������� �������� ������� �� �����
	bool getWin();
};

