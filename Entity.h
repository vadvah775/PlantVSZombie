#pragma once

#include "AssetManager.h"
#include "Animator.h"
#include <SFML/Graphics.hpp>

#include <iostream>

class Plant;
class Shot;
class Zombie;
class Cell;


using namespace sf;

//�������� �������� enum ��� ���� ��������� ���������

enum class EntityType
{
	None,
	Zombie,
	Plant,
	Shot,
	Cell
};


class Entity
{
protected:
	//�������
	float _x;
	float _y;
	EntityType _type = EntityType::None;
public:

	Entity();
	Entity(float x, float y);

	Entity(const Entity&) = delete;
	void operator=(const Entity&) = delete;

	virtual ~Entity() = default;
	

	Sprite sprite;
	Animator animator = Animator(sprite); // ��� ��������

	EntityType getType() const;
	virtual void show(RenderWindow &window) const = 0; 
	virtual void update(sf::Time const& dt) = 0;
	virtual FloatRect getHitboxes() const;//����� �� ������� ���� ����������� ��� ���� � ������ ����� ���������� ������� ������
	//���������� ������ getHitboxes()
	//virtual std::vector<sf::FloatRect> getHitboxes() const = 0;

	
	Vector2f getPos() const;
	void setPos(float x, float y);

};

