#include "Timer.h"

Timer::Timer() {
	QueryPerformanceCounter(&startTime); // Start timer at current system time.
}


float Timer::Elapsed() const{
	LARGE_INTEGER curTime, elapsedPc, frequency;
	QueryPerformanceFrequency(&frequency); // Get frequency.
	QueryPerformanceCounter(&curTime); // Set current time.
	elapsedPc.QuadPart = curTime.QuadPart - startTime.QuadPart; // Get elapsed cycles.
	return ((static_cast<float>(elapsedPc.QuadPart) * 1000.0f) / (static_cast<float>(frequency.QuadPart))); // Convert cycles to ms (elapsed cycles*1000/frequency of cycle in ghz).
}