#pragma once
#include "Shot.h"
class Boom : public Shot
{
protected:
	bool activate = false;

public:

	Boom();
	Boom(float x, float y);

	bool getActivate() const;
};

