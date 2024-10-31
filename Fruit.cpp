#include "Fruit.h"
#include <cstdlib>
Fruit::Fruit()
{
	respawn();
}
void Fruit::respawn()
{
	x = rand() % 15;
	y = rand() % 17;
}