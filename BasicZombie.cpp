#include "BasicZombie.h"
#include <iostream>


BasicZombie::BasicZombie() 
{
	int Random = rand() % 5;
	int Random2 = rand() % 10;
	numberOfLawn = Random;
	setPos(1240, 25 + 125 * numberOfLawn + Random2);//место в котором появляется зомби
	sprite.setTextureRect(IntRect(_x, _y, 125, 185));
	auto spriteSize = sf::Vector2i(125, 185);
	
	Animator::Animation& goForward = animator.CreateAnimation("goForward", "images/BasicZombie.png", sf::seconds(3), true);
	goForward.AddFrames(sf::Vector2i(0, 0), spriteSize, 9, 1);
	
	spriteSize = sf::Vector2i(125, 185);
	Animator::Animation& Eat = animator.CreateAnimation("Eat", "images/BasicZombieEat.png", sf::seconds(3), true);
	Eat.AddFrames(sf::Vector2i(0, 0), spriteSize, 40, 1);

	spriteSize = sf::Vector2i(185, 185);
	Animator::Animation& Dead = animator.CreateAnimation("Dead", "images/BasicZombieDead.png", sf::seconds(3), false);
	Dead.AddFrames(sf::Vector2i(0, 0), spriteSize, 8, 1);
	
	


	//изначальная скорость(возможно стоит добавить доп переменные где хранится эта информация
	_speed.x = -0.05;
	_speed.y = 0;

	_hp = 5;

	//хитбокс зомби
	hitBoxes = FloatRect(_x + 30, _y, 67, 185);


	_type = EntityType::Zombie;
}


//в самой игру в идеале использовать именно по умолчанию, так как 
//именно в конструкторе решается на какой поляне появится зомби

BasicZombie::BasicZombie(float x, float y)//использовать только для тестов!
{

	setPos(x, y);
	int Random = rand() % 6;
	numberOfLawn = Random;

	auto spriteSize = sf::Vector2i(125, 185);
	//auto& goForward = animator.CreateAnimation("goForward", "images/BasicZombie.png", sf::seconds(1), true);
	Animator::Animation& goForward = animator.CreateAnimation("goForward", "images/BasicZombie.png", sf::seconds(1), true);
	goForward.AddFrames(sf::Vector2i(0, 0), spriteSize, 9, 1);


	sprite.setTexture(AssetManager::GetTexture("images/BasicZombie1.png"));
	sprite.setTextureRect(IntRect(0, 0, 125, 185));


	//изначальная скорость(возможно стоит добавить доп переменные где хранится эта информация
	_speed.x = -0.05;
	_speed.y = 0; 


	//хитбоск
	hitBoxes = FloatRect(_x + 30, _y, 67, 185);

	_type = EntityType::Zombie;

}

void BasicZombie::update(sf::Time const& dt)
{
	float time = dt.asMicroseconds();
	time = time / 800;
	if (isMove && !isDead)
	{
		move(time);
	}
	if (eatPlant != nullptr && !isDead)
	{
		if (timeToEat(dt))
		{
			eatPlant->takeDamage(_damage);
			//std::cout << "UM-NOM-NAM\n";
			if (!eatPlant->isAlive())
			{
				eatPlant = nullptr;
				isMove = true;
				isEat = false;
				animator.SwitchAnimation("goForward");
				//возможен другой подход
				//впринципе хорошее место чтобы и анимацию сменить и всякое 
				//связанное с переходом в другое состояние сделать
			}
		}
	}
	//способ понять когда зомби уже умер и нужно начинать воспроизводить анимацию
	if (!isDead && !isAlive())
	{
		isDead = true;
		animator.SwitchAnimation("Dead");
	}
	if (isDead)
	{
		if (animator.getEndAnim())
		{
			isExisted = false;
		}
	}
	animator.Update(dt);
}

bool BasicZombie::collide(const Plant& op) const
{
	return getHitboxes().intersects(op.getHitboxes());
}

void BasicZombie::collideHandling(Plant& op)
{
	if (collide(op) && numberOfLawn == op.getNumberOfLawn() && op.isAlive() && !isDead)
	{
		if (eatPlant == nullptr)
		{
			animator.SwitchAnimation("Eat");
		}
		isMove = false;
		isEat = true;
		eatPlant = &op;
	}
}



void BasicZombie::show(RenderWindow& window) const {
	window.draw(sprite);
}