#pragma once
#include<string>
#include<vector>
#include<list>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

#include<type_traits>

//����� ��� ������ � ���������
class Animator
{
public:
	struct Animation
	{
		std::string m_Name;
		std::string m_TextureName;
		std::vector<sf::IntRect> m_Frames;
		sf::Time m_Duration;
		bool m_Looping;

		Animation(std::string const& name, std::string const& textureName, 
			sf::Time const& duration, bool looping);

		void AddFrames(sf::Vector2i const startFrom, sf::Vector2i const& frameSize, 
			unsigned int frames, unsigned int traccia);

	};

	
	explicit Animator(sf::Sprite& sprite);

	//�������� ��������, ��������� � ���, �������� ������ ����� ������, � ������������ � �����������
	Animator::Animation& CreateAnimation(std::string const& name, std::string const& textureName,
											sf::Time const& duration, bool loop = false);

	void Update(sf::Time const& dt);
	bool SwitchAnimation(std::string const& name);
	std::string GetCurrentAnimationName() const;
	void restart();
	bool getEndAnim() const;

	

private:
	Animator::Animation* FindAnimation(std::string const& name);
	void SwitchAnimation(Animator::Animation* animation);
	sf::Sprite& m_Sprite;
	sf::Time m_CurrentTime;
	std::list<Animator::Animation> m_Animations;
	Animator::Animation* m_CurrentAnimation;
	bool endAnim = false;
};

