#include "ReadFromFile.h"
#include "iostream"


std::vector<float> getSettings() {
	std::ifstream file(R"(C:\Users\hafneral\Desktop\rcs.txt)");
	std::vector<float> set;
	float sens, fov, mult, rndm, timer, aftimer;
	file >> sens; set.push_back(sens);
	file >> fov; set.push_back(fov);
	file >> mult; set.push_back(mult);
	file >> rndm; set.push_back(rndm);
	file >> timer; set.push_back(timer);
	return set;
}


float getRndm() {
	std::ifstream file(R"(C:\Users\hafneral\Desktop\rcs.txt)");
	float rndm;
	file >> rndm; file >> rndm; file >> rndm; file >> rndm;
	return rndm;
}

float getTimer() {
	std::ifstream file(R"(C:\Users\hafneral\Desktop\rcs.txt)");
	float timer;
	file >> timer; file >> timer; file >> timer; file >> timer; file >> timer;
	return timer;
}
