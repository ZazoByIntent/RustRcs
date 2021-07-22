#include "WriteToFile.h"
#include "iostream"

void overwriteSettings(const std::vector<float> &sets) {
	std::ofstream file(R"(C:\Users\zazo2\Desktop\rcs.txt)");
	file << sets[0]; file << "\n";
	file << sets[1]; file << "\n";
	file << sets[2]; file << "\n";
	file << sets[3]; file << "\n";
	file << sets[4];
	std::cout<< "New assigned settings: " << " sensitivity: " << sets[0] << ", current fov: " << sets[1] << ", current strenght: " << sets[2] << ", current random modifier: " << sets[3] << ", current timer modifier: " << sets[4] << "\n";
}