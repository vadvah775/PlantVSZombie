#include "Animator.h"
#include <iostream>

Animator::Animation::Animation(std::string const& name, std::string const& textureName, sf::Time const& duration,
	bool looping) : m_Name(name), m_TextureName(textureName), m_Duration(duration), m_Looping(looping) {}

void Animator::Animation::AddFrames(sf::Vector2i const startFrom,
	sf::Vector2i const& frameSize, unsigned int frames,
	unsigned int traccia)
{
	sf::Vector2i  current = startFrom;
	for (unsigned int t = 0; t < traccia; t++) {
		for (unsigned int i = 0; i < frames; i++)
		{
			m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
			current.x += frameSize.x;
		}
		current.y += frameSize.y;
		current.x = startFrom.x;
	}
}

Animator::Animator(sf::Sprite& sprite) : m_CurrentAnimation(nullptr), m_Sprite{ sprite } {}

bool Animator::getEndAnim() const
{
	return endAnim;
}

Animator::Animation& Animator::CreateAnimation(std::string const& name,
	std::string const& textureName, sf::Time const& duration, bool loop)
{
	//m_Animations.emplace_back(name, textureName, duration, loop);
	m_Animations.push_back(Animation(name, textureName, duration, loop));

	if (m_CurrentAnimation == nullptr) SwitchAnimation(&m_Animations.back());

	return m_Animations.back();
}

void Animator::SwitchAnimation(Animator::Animation* animation)
{
	if (animation != nullptr)
	{
		m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName));
	}

	m_CurrentAnimation = animation;
	m_CurrentTime = sf::Time::Zero;
}

bool Animator::SwitchAnimation(std::string const& name)
{
	auto animation = FindAnimation(name);
	if (animation != nullptr)
	{
		SwitchAnimation(animation);
		endAnim = false;//для проверки на то что объект можно удалить
		return true;
	}
	return false;
}

Animator::Animation* Animator::FindAnimation(std::string const& name)
{
	for (auto it = m_Animations.begin(); it != m_Animations.end(); ++it)
	{
		if (it->m_Name == name) return &*it;
	}

	return nullptr;
}

std::string Animator::GetCurrentAnimationName() const
{
	if (m_CurrentAnimation != nullptr) return m_CurrentAnimation->m_Name;
	return "";
}

void Animator::restart()
{
	m_CurrentTime = sf::Time::Zero;
	endAnim = false;
}

void Animator::Update(sf::Time const& dt)
{
	if (m_CurrentAnimation == nullptr) return;

	m_CurrentTime += dt;

	float scaledTime = (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());
	auto numFrames = static_cast<int>(m_CurrentAnimation->m_Frames.size());
	auto currentFrame = static_cast<int>(scaledTime * numFrames);

	if (m_CurrentAnimation->m_Looping) currentFrame %= numFrames;
	else
		if (currentFrame >= numFrames) { currentFrame = numFrames - 1; endAnim = true; }

	m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}