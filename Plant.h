#pragma once
#include "Entity.h"
#include "Entities.h"
#include <optional>

class Shot;

class Plant : public Entity
{
protected:
	int _hp = 1;
	int numberOfLawn = 0;//����� ������ �� ������� ��������� ��������
	Cell* landCell; //��������� �� ������, ��� ��������� ��������

	//������� ��������
	FloatRect hitBoxes = FloatRect(0, 0, 100, 100);

public:

	Plant();
	Plant(float x, float y);
	//���� ���� ��� �������� ��� ����������� ����-��(��������� ��������)
	bool isGenerate = false;
	virtual bool generate();

	void takeDamage(int damage);
	bool isAlive() const;

	bool isPlanted; //������ ����� �� ����� �����(���� ���� ��� �������� �������� �� ����)
	
	//���������� true ���� ���� ��������� � �������� Zombie op
	virtual bool collide(const Zombie& op) const;

	virtual void collideHandling(Zombie& op);

	//��������������� ��������
	FloatRect getHitboxes() const override;

	virtual std::optional<std::unique_ptr<Shot>> shot(Zombie& z);

	int getNumberOfLawn();
	void setNumberOfLawn(int n);
	void setCell(Cell& cell);
};

