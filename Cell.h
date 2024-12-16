#pragma once
#include "Entity.h"
class Cell : public Entity
{
private:
	int numberOfLawn = 0;

public:
	Cell();
	Cell(float x, float y);

	bool isEmpty = true;

	virtual void setSpriteColor(bool col);

	int getNumberOfLawn();
	void setNumberOfLawn(int n);
};

