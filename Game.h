#pragma once
#include<SFML/Graphics.hpp>
#include<list>
#include<memory>
#include <algorithm>
#include<iostream>
#include"MapManager.h"
#include"Zombie.h"
#include"Plant.h"
#include"Shot.h"

#include"PoleZombie.h"
#include"BucketZombie.h"
#include"ConeZombie.h"
#include"BasicZombie.h"
#include"PeaShooter.h"

using namespace sf;

class Game
{
	RenderWindow window;

	bool _gameIsRunning = false;
	bool _openSettings = false;

	MapManager mapManager;
	std::list<std::unique_ptr<Zombie>> onMapZombies;
	std::list<std::unique_ptr<Plant>> onMapPlants;
	std::list<std::unique_ptr<Shot>> onMapShots;
	
	

	Clock _frameClock;
	View cam;
	AssetManager assetManager;

	Sprite menu;
	Sprite settings;
	Font font = AssetManager::GetFont("Texts/CyrilicOld.ttf");
	Text textStart;
	Text textQuit;
	Text textHelp;
	Text textSettings;

	Text textResolution;
	Text resolution1;
	Text resolution2;
	Text resolution3;
	Text backToGame;

	Text lowerLevel;
	Text increaseLevel;
	Text textLevel;

	//оба этих спрайта лучше перенести в mapManager но мне уже лень этим заниматься
	Sprite background;
	sf::Sprite Hud;

	void _menuLoop();
	void _showMenu();
	void _inputMenuHandling();

	void _gameLoop();
	void _inputHandling();
	void _ingameHandling(sf::Time const& dt);
	void _showObjects();
public:
	Game();
	void mainLoop();

};

