#include "Random.h"
#include <iostream>
#include <ctime>  


int getRandom(const float& random) {
	srand(time(NULL));
	int rndm = (random * 100) - 100;
	if (rndm < 0) rndm *= -1;
	if (rndm == 0) return 0;
	return rand() % rndm;
}