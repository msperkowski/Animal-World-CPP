#ifndef ORGANISM_H
#define ORGANISM_H

#include "World.hpp"
#include <iostream>

class Organism
{
protected:
	int power;
	int age;
	int initiative;
	struct Point position;
	World &world;

	virtual void createNew(Organism **ptr, struct Point position) = 0;
public:
	Organism(World &world, struct Point position, int power, int initiative);

	virtual void wrapPosition(struct Point &position);
	virtual void getOlder();

	virtual struct Point getPosition();
	virtual int getInitiative();
	virtual int getAge();
	virtual int& getPower();

	virtual void action() = 0;
	virtual void collision(Organism &other) = 0;
	virtual void fight(Organism &other);
	virtual bool reproduce();
	virtual void die();
	virtual void draw() = 0;
};

#endif
