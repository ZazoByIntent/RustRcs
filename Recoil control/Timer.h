#pragma once
#include "Windows.h"
#include "ctime"


class Timer {
private:
	LARGE_INTEGER startTime;
public:
	Timer();
	float Elapsed() const;
};