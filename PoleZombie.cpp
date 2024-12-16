#include "PoleZombie.h"


PoleZombie::PoleZombie()
{
	int Random = rand() % 5;
	int Random2 = rand() % 10;
	numberOfLawn = Random;
	setPos(940, -60 + 125 * numberOfLawn + Random2);//место в котором появляется зомби
	sprite.setTextureRect(IntRect(_x, _y, 125, 185));
	auto spriteSize = sf::Vector2i(446, 280);

	

	
	Animator::Animation& run = animator.CreateAnimation("run", "images/PoleZombieRun.png", sf::seconds(2), true);
	run.AddFrames(sf::Vector2i(0, 0), spriteSize, 34, 1);

	Animator::Animation& eat = animator.CreateAnimation("eat", "images/PoleZombieEat.png", sf::seconds(3), true);
	eat.AddFrames(sf::Vector2i(0, 0), spriteSize, 28, 1);

	Animator::Animation& dead = animator.CreateAnimation("dead", "images/PoleZombieDead.png", sf::seconds(3), false);
	dead.AddFrames(sf::Vector2i(0, 0), spriteSize, 27, 1);

	Animator::Animation& jump = animator.CreateAnimation("jump", "images/PoleZombieJump.png", sf::seconds(3), false);
	jump.AddFrames(sf::Vector2i(0, 0), spriteSize, 4, 11);

	Animator::Animation& walk = animator.CreateAnimation("walk", "images/PoleZombieWalk.png", sf::seconds(3), true);
	walk.AddFrames(sf::Vector2i(0, 0), spriteSize, 5, 9);


	

	




	//изначальная скорость(возможно стоит добавить доп переменные где хранится эта информация
	_speed.x = -0.05;
	_speed.y = 0;

	_hp = 10;

	hitBoxes = FloatRect(_x + 330, _y + 80, 67, 185);

	_type = EntityType::Zombie;
}

//просто заглушка
PoleZombie::PoleZombie(float x, float y) : PoleZombie() {}

void PoleZombie::update(sf::Time const& dt)
{
	float time = dt.asMicroseconds();
	time = time / 800;

	//для обработки прыжка
	if (isAlive() && playingJump && !havePole)
	{
		hitBoxes.left -= (0.052 * time);
		//std::cout << hitBoxes.left << '\n';
		if (animator.getEndAnim())
		{
			animator.SwitchAnimation("walk");
			isMove = true;
			playingJump = false;
			_x -= 200;
			sprite.setPosition(_x, _y);
		}
	}


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
				animator.SwitchAnimation("walk");
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
		animator.SwitchAnimation("dead");
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

bool PoleZombie::collide(const Plant& op) const
{
	return getHitboxes().intersects(op.getHitboxes());
}

void PoleZombie::collideHandling(Plant& op)
{
	if ((collide(op) && numberOfLawn == op.getNumberOfLawn() && op.isAlive() && !isDead && havePole))
	{
		//обработка прыжка
		havePole = false;
		isMove = false;
		playingJump = true;
		animator.SwitchAnimation("jump");

	}
	else if (collide(op) && numberOfLawn == op.getNumberOfLawn() && op.isAlive() && !isDead && !playingJump)
	{
		if (eatPlant == nullptr)
		{
			animator.SwitchAnimation("eat");
		}
		isMove = false;
		isEat = true;
		eatPlant = &op;
	}
}

void PoleZombie::show(RenderWindow& window) const {
	window.draw(sprite);
}

void PoleZombie::move(float time)
{
	_x = _x + _speed.x * time;
	_y = _y + _speed.y * time;
	sprite.setPosition(_x, _y);
	hitBoxes.left = _x + 330;//если у разных зомби будет разный хит бокс то сделать 
	//переопредление отдельно в каждом зомби
	//std::cout << "----------\n";
	//std::cout << hitBoxes.left << '\n';
}