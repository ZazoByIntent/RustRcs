#pragma once
#include "fstream"
#include "Vec2.h"
#include "vector"
#include "string.h"


std::vector<Vec2> getPattern(const std::string& name);

std::vector<float> getSettings();

float getRndm();

float getTimer();
