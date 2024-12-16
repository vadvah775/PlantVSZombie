#include "PeaShooter.h"
#include "Pea.h"


PeaShooter::PeaShooter() : PeaShooter(0, 0) {}

PeaShooter::PeaShooter(float x, float y) {//� ��������� ��������� ������� �� ����� ����
	setPos(x, y);
	sprite.setTextureRect(IntRect(_x, _y, 100, 100));

	auto spriteSize = sf::Vector2i(100, 100);
	Animator::Animation& stand = animator.CreateAnimation("stand", "images/PeaShooterLong.png", sf::seconds(1.5), true);
	stand.AddFrames(sf::Vector2i(0, 132), spriteSize, 77, 1);

	//sprite.setTexture(AssetManager::GetTexture("images/PeaShooter.png"));
	//sprite.setTextureRect(IntRect(124, 75, 62, 75)); //������� ��� ��������� ����������� � ������ PeaShooter � ������������ ��
	_scope = FloatRect(_x + 50, _y, 1300 - _x, 125); //�������� ������� ���������, � ������ ������ �� �������� �� ������ ��������� ��� ������(�������� �������, �� � ������� ���� ���� ��������
	_hp = 20; // �������� ����������� � ������ PeaShooter � ������������ ��
	hitBoxes = FloatRect(_x, _y, 100, 100);
	_type = EntityType::Plant;
}

void PeaShooter::show(RenderWindow &window) const {
	window.draw(sprite);
}

bool PeaShooter::timeToShoot(sf::Time dt)
{
	currentTime += dt;
	if (currentTime >= attackSpeed)
	{
		currentTime = sf::Time::Zero;
		return true;
	}
	return false;
}

bool PeaShooter::collide(const Zombie& op) const
{
	return sprite.getGlobalBounds().intersects(op.getHitboxes());
}

void PeaShooter::collideHandling(Zombie& op)
{
	//� ������ ������ �� ������������
	if (_scope.intersects(op.getHitboxes()) && numberOfLawn == op.numberOfLawn)
	{
		
	}
}

void PeaShooter::update(sf::Time const& dt)
{
	if (!isAlive()) landCell->isEmpty = true;
	if (!(currentTime > attackSpeed))
	{
		currentTime += dt;
	}
	animator.Update(dt);
}

std::optional<std::unique_ptr<Shot>> PeaShooter::shot(Zombie& z)
{
	if (_scope.intersects(z.getHitboxes()) && numberOfLawn == z.numberOfLawn && currentTime > attackSpeed)
	{

		currentTime = sf::Time::Zero;
		auto it = std::make_unique<Pea>(_scope.left, _scope.top);
		it->numberOfLawn = numberOfLawn;
		return std::move(it);
	}
	return std::nullopt;
}