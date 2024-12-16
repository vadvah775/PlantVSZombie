#include "Game.h"


#include "Pea.h" // лишнее

Game::Game() 
{
	//window.create(sf::VideoMode(640, 480), "PvZ!");
	//window.create(sf::VideoMode(1920, 480), "PvZ!");
	window.create(VideoMode::getDesktopMode(), "PVZ");
	//cam.reset(FloatRect(275, 0, 1000, 750));//устанавливаем начальную позицию камеры
	cam.reset(FloatRect(275, 0, 1000, 780));//тесты того как лучше поставить камеру
	window.setView(cam);

	menu.setPosition(275, 0);
	menu.setTexture(AssetManager::GetTexture("images/menu.png"));
	Vector2f targetSize(window.getView().getSize());
	menu.setScale(
		targetSize.x / menu.getLocalBounds().width,
		targetSize.y / menu.getGlobalBounds().height);
	
	settings.setPosition(580, 130);
	settings.setTexture(AssetManager::GetTexture("images/settings.png"));

	font = AssetManager::GetFont("Texts/CyrilicOld.ttf");

	//по хорошему все эти тексти надо сделать как отдельный класс buttom
	//но время поджимает поэтому имеем вот такое решение на коленке
	
	textStart = Text("Start Game", font, 70);
	textStart.setPosition(810, 130);
	textStart.rotate(7);
	textStart.setFillColor(sf::Color::Black);
	
	textQuit = Text("Quit", font, 30);//1180 660
	textQuit.setPosition(1180, 660);
	textQuit.setFillColor(sf::Color::Black);

	textSettings = Text("Settings", font, 25);
	textSettings.setPosition(985, 635);
	textSettings.rotate(5);
	textSettings.setFillColor(sf::Color::Black);


	textResolution = Text("Resolution", font, 60);
	textResolution.setPosition(650, 260);
	textResolution.setFillColor(sf::Color(122, 102, 102));

	resolution1 = Text("640 X 480", font, 20);
	resolution1.setPosition(745, 378);

	resolution2 = Text("1024 X 768", font, 20);
	resolution2.setPosition(740, 421);

	resolution3 = Text("DesktopMode", font, 20);
	resolution3.setPosition(730, 463);
	
	backToGame = Text("BackToGame", font, 50);
	backToGame.setPosition(655, 525);
	backToGame.setFillColor(sf::Color::Black);

	lowerLevel = Text("<", font, 60);
	lowerLevel.setPosition(900, 90);
	lowerLevel.rotate(7);
	lowerLevel.setFillColor(sf::Color::Black);

	increaseLevel = Text(">", font, 60);
	increaseLevel.setPosition(1010, 98);
	increaseLevel.rotate(7);
	increaseLevel.setFillColor(sf::Color::Black);

	textLevel = Text("1", font, 65);
	textLevel.setPosition(950, 90);
	textLevel.rotate(7);
	textLevel.setFillColor(sf::Color::Black);

	mapManager.MapLoader(0);//Пока что по стандарту загружается нулевая мапа
	mapManager.CardsLoader();

	background.setTexture(AssetManager::GetTexture("images/Background.png"));
	Hud.setTexture(AssetManager::GetTexture("images/Hud(not_card).png"));
	Hud.setTextureRect(IntRect(0, 0, 436, 99));
	Hud.setPosition(345, 0);
}

void Game::mainLoop()
{
	while (window.isOpen()) {
		if (_gameIsRunning)
		{
			_gameLoop();
		}
		else
		{
			_menuLoop();
		}
	}
}

void Game::_menuLoop()
{
	_inputMenuHandling();
	_showMenu();
}




void Game::_inputMenuHandling()
{
	Event ev;

	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			window.close();
		}
		if (ev.type == Event::MouseButtonPressed)
		{
			Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
			Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые 
			if (ev.key.code == Mouse::Left)
			{
				if (!_openSettings)
				{
					if (textStart.getGlobalBounds().contains(pos))
					{
						_gameIsRunning = true;
					}
					if (textQuit.getGlobalBounds().contains(pos))
					{
						window.close();
					}
					if (textSettings.getGlobalBounds().contains(pos))
					{
						_openSettings = true;
						textSettings.setFillColor(sf::Color::Black);
					}
					if (increaseLevel.getGlobalBounds().contains(pos))
					{
						std::string s = textLevel.getString().toAnsiString();
						int l = atoi(s.c_str()) + 1;
						if (l > 10) l = 10;
						textLevel.setString(std::to_string(l));
						mapManager.setLevel(l);
					}
					if (lowerLevel.getGlobalBounds().contains(pos))
					{
						std::string s = textLevel.getString().toAnsiString();
						int l = atoi(s.c_str()) - 1;
						if (l <= 0) l = 1;
						textLevel.setString(std::to_string(l));
						mapManager.setLevel(l);
					}
				}
				else
				{
					if (resolution1.getGlobalBounds().contains(pos))
					{
						window.setSize(Vector2u(640, 480));
					}
					else if (resolution2.getGlobalBounds().contains(pos))
					{
						window.setSize(Vector2u(1024, 768));
					}
					else if (resolution3.getGlobalBounds().contains(pos))
					{
						window.setSize(Vector2u(VideoMode().getDesktopMode().width, VideoMode().getDesktopMode().height));
					}
					else if (backToGame.getGlobalBounds().contains(pos))
					{
						_openSettings = false;
					}
				}
			}

		}
		if (ev.type == sf::Event::MouseMoved)
		{
			Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
			Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые 
			std::cout << pos.x << ' ' << pos.y << '\n';
			if (!_openSettings)
			{
				if (textStart.getGlobalBounds().contains(pos))
				{
					textStart.setFillColor(sf::Color::Green);
				}
				else
				{
					textStart.setFillColor(sf::Color::Black);
				}
				if (textQuit.getGlobalBounds().contains(pos))
				{
					textQuit.setFillColor(sf::Color::Green);
				}
				else
				{
					textQuit.setFillColor(sf::Color::Black);
				}
				if (textSettings.getGlobalBounds().contains(pos))
				{
					textSettings.setFillColor(sf::Color::Green);
				}
				else
				{
					textSettings.setFillColor(sf::Color::Black);
				}
				if (increaseLevel.getGlobalBounds().contains(pos))
				{
					increaseLevel.setFillColor(sf::Color::Green);
				}
				else
				{
					increaseLevel.setFillColor(sf::Color::Black);
				}
				if (lowerLevel.getGlobalBounds().contains(pos))
				{
					lowerLevel.setFillColor(sf::Color::Green);
				}
				else
				{
					lowerLevel.setFillColor(sf::Color::Black);
				}
			}
			else
			{
				if (resolution1.getGlobalBounds().contains(pos))
				{
					resolution1.setFillColor(sf::Color::Green);
				}
				else
				{
					resolution1.setFillColor(sf::Color::Black);
				}
				if (resolution2.getGlobalBounds().contains(pos))
				{
					resolution2.setFillColor(sf::Color::Green);
				}
				else
				{
					resolution2.setFillColor(sf::Color::Black);
				}
				if (resolution3.getGlobalBounds().contains(pos))
				{
					resolution3.setFillColor(sf::Color::Green);
				}
				else
				{
					resolution3.setFillColor(sf::Color::Black);
				}
				if (backToGame.getGlobalBounds().contains(pos))
				{
					backToGame.setFillColor(sf::Color::Green);
				}
				else
				{
					backToGame.setFillColor(sf::Color::Black);
				}
			}

		}
	}
}

void Game::_showMenu()
{

	window.clear();

	window.draw(menu);
	window.draw(textStart);
	window.draw(textQuit);
	window.draw(textSettings);
	window.draw(lowerLevel);
	window.draw(increaseLevel);
	window.draw(textLevel);
	if (_openSettings)
	{
		window.draw(settings);
		window.draw(textResolution);
		window.draw(resolution1);
		window.draw(resolution2);
		window.draw(resolution3);
		window.draw(backToGame);
	}
	window.display();
}

void Game::_gameLoop()
{
	sf::Time deltaTime = _frameClock.restart();

	_inputHandling();
	_ingameHandling(deltaTime);
	_showObjects();
	if (mapManager.getWin()) {
		window.close();
	}
}

void Game::_inputHandling()
{
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
			if (ev.type == sf::Event::MouseMoved)
			{
				Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
				Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые 
				mapManager.cellLight(pos);
			}
			if (ev.type == Event::MouseButtonPressed)
			{
				if (ev.key.code == Mouse::Left)
				{
					Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
					Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
					mapManager.chooseCard(pos);
					mapManager.putPlant(pos, onMapPlants);
					mapManager.clickOnSun(pos);
				}

			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				//auto temp = std::make_unique<BasicZombie>(); 
				int random = rand() % 4;
				switch (random)
				{
				case(0):
				{
					auto temp = std::make_unique<PoleZombie>();
					onMapZombies.push_back(std::move(temp));
					break;
				}
				case(1):
				{
					auto temp = std::make_unique<BasicZombie>();
					onMapZombies.push_back(std::move(temp));
					break;
				}
				case(2):
				{
					auto temp = std::make_unique<ConeZombie>();
					onMapZombies.push_back(std::move(temp));
					break;
				}
				case(3):      
				{
					auto temp = std::make_unique<BucketZombie>();
					onMapZombies.push_back(std::move(temp));
					break;
				}
				default:
					break;
				}
				//auto temp = std::make_unique<PoleZombie>();
				//std::unique_ptr<BasicZombie> temp(new BasicZombie());//так не надо
				//onMapZombies.push_back(std::move(temp));
				/*auto sh = std::make_unique<Pea>(300, 300);
				onMapShots.push_back(std::move(sh));*/
			}
		}
	}
}

void Game::_ingameHandling(sf::Time const& dt)
{
	//соприкосновение Зомби и Растений
	for (auto& z : onMapZombies)
	{
		for (auto& p : onMapPlants)
		{
			z->collideHandling(*p);
			//p->collideHandling(*z);
			auto it = p->shot(*z);
			//возвращает std::optional и если в нём есть значения 
			// то загружать его в onMapShots
			//currentTime прибавляется в update и там же проверяется обновляется time to shoot
			// а здесь происходит выстрел только если time to shot == true после чего он заменяетя на false
			// и может получть true только в update
			if (it.has_value())
			{
				onMapShots.push_back(std::move(it.value()));
			}
		}
	}
	mapManager.addSun(dt);

	//обработка столкновений shot и зомби
	//можно сделать либо через shot либо через zombie обработку 
	for (auto& s : onMapShots)
	{
		for (auto& z : onMapZombies)
		{
			z->takeShot(*s);
		}
		//сделать
		//обработка того что выстрел пересек гранцу карты и его стоит удалить
	}
	

	//update для отсальных сущностей
	for (auto& i : onMapZombies)
	{
		i->update(dt);
	}
	for (auto& i : onMapPlants)
	{
		if (i->isGenerate) mapManager.generatePlantObject(*i);
		i->update(dt);
	}
	for (auto& i : onMapShots)
	{
		i->update(dt);
	}
	for (auto& i : mapManager.getSuns())
	{
		i->update(dt);
	}
	for (auto& i : mapManager.getCards())
	{
		i->update(dt);
	}

	mapManager.updateText(dt);

	//удаление растения из списка
	auto it_p = std::remove_if(onMapPlants.begin(), onMapPlants.end(),
		[](std::unique_ptr<Plant>& i) { return !i->isAlive(); });
	onMapPlants.erase(it_p, onMapPlants.end());

	//удаление зомби из списка
	auto it_z = std::remove_if(onMapZombies.begin(), onMapZombies.end(),
		[](std::unique_ptr<Zombie>& i) { return !i->isExisted; });//поменять на isExisted, это пока временная мера т.к. не обрабатывается анимация смерти
	onMapZombies.erase(it_z, onMapZombies.end());

	//удаление выстрела из списка
	auto it_s = std::remove_if(onMapShots.begin(), onMapShots.end(),
		[](std::unique_ptr<Shot>& i) { return !i->isExisted; });
	onMapShots.erase(it_s, onMapShots.end());

	//удаление солнышка из списка
	auto it_sun = std::remove_if(mapManager.getSuns().begin(), mapManager.getSuns().end(),
		[](std::unique_ptr<Sun>& i) { return !i->isExisted; });
	mapManager.getSuns().erase(it_sun, mapManager.getSuns().end());

	//проверка того что зомби пересёк границу
	for (auto& z : onMapZombies)
	{
		if (z->getHitboxes().left < 230)
		{
			std::cout << "game over\n";
			window.close();
			_gameIsRunning = false;
		}
	}

	mapManager.spawnZombie(dt, onMapZombies);
}

void Game::_showObjects()
{
	window.clear();

	window.draw(background);// рисуем бэкраунд

	
	//рисование самих клеток ни к чему, важен только факт их существования(но рисуем для того чтобы подсвечивать куда можно посадить растение)
	for (const auto& i : mapManager.getMap()._data)
	{
		i->show(window);
	}

	for (const auto& i : onMapPlants)
	{
		i->show(window);
	}

	for (const auto& i : onMapZombies)
	{
		i->show(window);
	}

	for (const auto& i : onMapShots)
	{
		i->show(window);
	}

	for (const auto& i : mapManager.getSuns())
	{
		i->show(window);
	}

	//рисуем hud
	window.draw(Hud);
	for (const auto& i : mapManager.getCards())
	{
		i->show(window);
	}
	window.draw(mapManager.getTextCountOfSuns());
	window.display();
}