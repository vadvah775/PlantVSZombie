#include "AssetManager.h"

#include "iostream"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	//��������� ������������� ������ ������ AssetManager
	//� ��������� ������ ������������� ����������
	assert(sInstance == nullptr);
	sInstance = this;
}


//���������� � ������ �������� �� enum ��� ��������� 
// � �������� �������� ����� ��� �������� ���� ��������(������� ������, ����� ������ ��������� ��������� � ����� ������)
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
		texture.loadFromFile(filename); //����������� ����� �� �����, �� ���� ��� ������ image(����� ��� � �����)
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