#pragma once
#include "Movable.h"
class Sun : public Movable
{
private:
	int value = 25;
	sf::Time currentTime = sf::Time::Zero;
	sf::Time disappearTime = sf::seconds(5);//����� 5 ������ �������� ��������
	bool isFall = false;//��������� ����� �� �������� �� ����� � ���� �� �� �������� �������� ������ ��� ��� ������������
	float y_fall = 200;//(200,600)������� �� y ���� ����� ������������ ��������
public:
	Sun(); // ��� ������ �������� � ����
	Sun(float x, float y); // ��� �������� �� �����������

	void show(RenderWindow& window) const override;
	void update(sf::Time const& dt) override;

	int getValue() const;
};

