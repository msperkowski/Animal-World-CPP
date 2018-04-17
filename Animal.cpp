#include "Animal.hpp"
#include <random>
#include <typeinfo>

void Animal::action()
{
	getOlder();
	std::random_device r;
	std::mt19937 range(r());
	std::uniform_int_distribution<int> uni(0, 3);

	int randomDirection = uni(range);
	struct Point destination(position.x, position.y);
	int dx = 0;
	int dy = 0;

	switch (randomDirection)
	{
		case 0:
			dx = 1;
			break;
		case 1:
			dx = -1;
			break;
		case 2:
			dy = 1;
			break;
		case 3:
			dy = -1;
			break;
	}

	destination.x += dx;
	destination.y += dy;

	wrapPosition(destination);
	if (world.getOrganism(destination) != nullptr)
		world.getOrganism(destination)->collision(*this);
	else
		move(dx, dy);

}

void Animal::move(int dx, int dy)
{
	position.x += dx;
	position.y += dy;

	wrapPosition(position);
}

void Animal::collision(Organism &other)
{
	if (typeid(*this).hash_code() == typeid(other).hash_code())
	{
		if (this->getAge() > 18 && other.getAge() > 18)
			if (!reproduce())
				other.reproduce();
	}
	else
	{
		fight(other);
	}

}
