#include "Sun.h"

Sun::Sun()
{
	int r1 = 350 + rand() % 850;//���������� x ��� ���������� ��������
	int r2 = 200 + rand() % 400; // ��� ���� ����� ���������� � ����� ����� ��� �����
	setPos(r1, 100);//������ 200 ������� ��� ����� ����� ��������
	y_fall = r2;
	auto spriteSize = sf::Vector2i(100, 100);

	Animator::Animation& sun = animator.CreateAnimation("sun", "images/Sun.png", sf::seconds(2), true);
	sun.AddFrames(sf::Vector2i(0, 0), spriteSize, 22, 1);

	_speed.x = 0;
	_speed.y = 0.1;
}

Sun::Sun(float x, float y) //��������� ����� ������� ������� ������� ��������
{
	int r1 = x + rand() % 100;//���������� x ��� ���������� ��������
	//int r2 = 200 + rand() % 400; // ��� ���� ����� ���������� � ����� ����� ��� �����
	setPos(r1, y);//������ 200 ������� ��� ����� ����� ��������
	y_fall = y + 100;
	auto spriteSize = sf::Vector2i(100, 100);

	Animator::Animation& sun = animator.CreateAnimation("sun", "images/Sun.png", sf::seconds(2), true);
	sun.AddFrames(sf::Vector2i(0, 0), spriteSize, 22, 1);

	_speed.x = 0;
	_speed.y = 0.1;
}


void Sun::show(RenderWindow& window) const
{
	window.draw(sprite);
}

void Sun::update(sf::Time const& dt)
{
	if (isFall)
	{
		currentTime += dt;
		if (currentTime >= disappearTime)
		{
			isExisted = false;
		}
	}
	float time = dt.asMicroseconds();
	time = time / 800;
	move(time);
	if (_y >= y_fall)
	{
		_speed.y = 0;
		isFall = true;
	}
	animator.Update(dt);
}

int Sun::getValue() const
{
	return value;
}
