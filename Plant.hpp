#ifndef PLANT_H
#define PLANT_H

#include "Organism.hpp"

class Plant : public Organism
{
protected:

public:
	Plant(World &world, struct Point position, int power);

	void action();
	virtual void collision(Organism &other) override;
	virtual void fight(Organism &other) override;
	virtual void draw() = 0;
};
#endif
