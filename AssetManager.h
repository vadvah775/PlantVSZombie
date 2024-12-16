#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<map>
#include<string>
#include<assert.h>//для генирации исключения в конструкторе

using namespace sf;

class AssetManager
{
public:
	AssetManager();

	static Texture& GetTexture(std::string const& filename);
	static sf::SoundBuffer& GetSoundBuffer(std::string const& filename);
	static sf::Font& GetFont(std::string const& filename);


private:
	std::map<std::string, sf::Texture> m_Textures;
	std::map<std::string, sf::SoundBuffer> m_SoundBuffer;
	std::map<std::string, sf::Font> m_Fonts;


	static AssetManager* sInstance;

};

