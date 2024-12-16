#pragma once
#include "Plant.h"
#include "CherryBoom.h"

class CherryBomb : public Plant
{
protected:
	//�� � ���� ��� ��� ����� ����������� ����� �� ����������� �� ��������
	//sf::Time reloadingTime = sf::seconds(4); 
	//sf::Time currentTime = sf::Time::Zero;


	bool boomIsPlanting = false; // ��� ����� ������
	bool readyToExplode = false;
public:
	CherryBomb();
	CherryBomb(float x, float y);

	void show(RenderWindow& window)const override;
	void update(sf::Time const& dt) override;
	std::optional<std::unique_ptr<Shot>> shot(Zombie& z) override;
};

