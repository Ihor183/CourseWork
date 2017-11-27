#include "Dice.h"
#include<stdlib.h>
#include<time.h>

Dice::Dice() { }


Dice::~Dice() { }

void Dice::ThrowDice(int* point) {
	srand(time(NULL));
	for (int i = 0; i < 2; i++) { points[i] = rand() % 6 + 1; point[i] = points[i]; }
}