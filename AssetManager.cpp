#include "AssetManager.h"

#include "iostream"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	//–азрешить существование только одного AssetManager
	//¬ противном случае сгенирировать исключение
	assert(sInstance == nullptr);
	sInstance = this;
}


//переделать в случае перехода на enum дл€ сущностей 
// и добавить отдельно метод дл€ загрузки всех ресурсов(спорный момент, может сильно нагружать программу в самам начале)
sf::Texture& AssetManager::GetTexture(std::string const& filename) {
	auto& texMap = sInstance->m_Textures;

	auto pairFound = texMap.find(filename);

	if (pairFound != texMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& texture = texMap[filename];
		texture.loadFromFile(filename); //загружаетс€ сразу из файла, то есть нет стадии image(может так и нужно)
		return texture;
	}
}

sf::Font& AssetManager::GetFont(std::string const& filename)
{
	auto& fontMap = sInstance->m_Fonts;

	auto pairFound = fontMap.find(filename);

	if (pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename)
{
	auto& soundMap = sInstance->m_SoundBuffer;

	auto pairFound = soundMap.find(filename);

	if (pairFound != soundMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& sound = soundMap[filename];
		sound.loadFromFile(filename);
		return sound;
	}
}