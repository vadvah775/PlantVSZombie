#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include<memory>
#include "PeaShooter.h"
#include "AssetManager.h"
#include"Game.h"

using namespace sf;


int main()
{
	Game game;
	game.mainLoop();
}


//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
//    Clock clock;
//
//    /*Image peaShooterImage;
//    peaShooterImage.loadFromFile("images/PeashooterAssetsDS2.png");
//    Texture peaShooterTexture;
//    peaShooterTexture.loadFromImage(peaShooterImage);
//
//    Sprite peaSprite;
//    peaSprite.setTexture(peaShooterTexture);
//    peaSprite.setTextureRect(IntRect(0, 0, 62, 75));
//    peaSprite.setPosition(50, 25);*/
//
//    std::list<std::unique_ptr<Plant>> onMapPlants;
//
//    AssetManager assetManager;
//    {//блок кода где я создаю(блять нельзя тут создавать затупок ты) и загружаю текстуру гороха, нужно потом вынести всё это в отдельный метод, а лучше даже класс
//        
//        assetManager.GetTexture("images/PeashooterAssetsDS2.png");
//    }
//
//
//    while (window.isOpen())
//    {
//        float time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time = time / 800;
//
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//           //получение координат мыши, пока не нужно, но очев понадобится позже ну и событие о том что мышь передвинута
//           if (event.type == sf::Event::MouseButtonPressed)
//            {
//               if(event.key.code == Mouse::Left)
//                {
//                    std::cout << "new mouse x: " << event.mouseButton.x << std::endl;
//                    std::cout << "new mouse y: " << event.mouseButton.y << std::endl;
//                    //auto j = std::make_unique<PeaShooter>(event.mouseMove.x, event.mouseMove.y);
//                    onMapPlants.push_back(std::make_unique<PeaShooter>(PeaShooter(event.mouseButton.x, event.mouseButton.y)));
//                }
//            }
//            
//        }
//
//        window.clear();
//        
//        for (const auto &i : onMapPlants) {
//            i->show(window);
//        }
//        //window.draw(peaSprite);
//        window.display();
//    }
//
//    return 0;
//}
