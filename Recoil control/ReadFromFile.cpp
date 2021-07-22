#include "ReadFromFile.h"
#include "iostream"

std::vector<Vec2> getPattern(const std::string& name){
	
	if (name == "AR")
	{
		std::vector<Vec2> pattern{ Vec2(1.390706, -2.003941), Vec2(1.176434, -3.844176), Vec2(3.387171, -5.516686), Vec2(5.087049, -7.017456), Vec2(5.094189, -8.342467), Vec2(4.426013, -9.487704), Vec2(3.250455, -10.44915), Vec2(1.73545, -11.22279), Vec2(0.04893398, -11.8046), Vec2(-1.641158, -12.19056), Vec2(-3.166891, -12.58713), Vec2(-4.360331, -13.32077), Vec2(-5.053545, -14.32128), Vec2(-5.090651, -15.51103), Vec2(-4.489915, -16.81242), Vec2(-3.382552, -18.14783) , Vec2(-1.899585, -19.43966), Vec2(-0.1720295, -20.61031) , Vec2(1.669086, -21.58213) , Vec2(3.492748, -22.27755) , Vec2(5.16793, -22.61893) , Vec2(6.563614, -22.81778) , Vec2(7.548776, -23.37389) , Vec2(7.992399, -24.21139) , Vec2(7.512226, -25.23734) , Vec2(6.063792, -26.35886) , Vec2(4.117367, -27.48302) , Vec2(2.143932, -28.51692), Vec2(0.6144824, -29.36766) };
		return pattern;
	}
	else
	{
		std::vector<Vec2> pattern;
		return pattern;
	}
} 



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
