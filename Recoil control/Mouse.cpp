#include "Mouse.h"
#include "Windows.h"
#include "iostream"
#include "Timer.h"
#include "ReadFromFile.h"
#include "Random.h"

void mouse_move(const Weapon& chosen, const float &timer, const float &random)
{
	unsigned shotsFired = 0;
	unsigned magSize = chosen.getMagSize();
	unsigned rndm = 0;
	float repeatDelay = (1000.0f / (chosen.getRpm() / 60.0f))*timer; // calculate actual repeat delay from RPM of weapon.

	while(1)
	{
		if (!GetAsyncKeyState(VK_LBUTTON) || !GetAsyncKeyState(VK_RBUTTON)) break; // Break if stop firing or scoping

		if (shotsFired < magSize) // If mag capacity is not exceeded
		{
			if (random != 1.0f) rndm = getRandom(random); // Fetch random if set
			Vec2 curShot = chosen.getPatternAtItr(shotsFired); // First shot is it's own delta.
			if (shotsFired > 0)
				curShot = chosen.getPatternAtItr(shotsFired) - chosen.getPatternAtItr(shotsFired - 1); // Calculate delta otherwise  
			Vec2 rawShot = chosen.getRawPatternAtItr(shotsFired); // First shot is it's own delta.
			if (shotsFired > 0)
				rawShot = chosen.getRawPatternAtItr(shotsFired) - chosen.getRawPatternAtItr(shotsFired - 1); // Calculate delta otherwise

			float x = round(curShot.getX()) - rndm; // Get actual movement and apply randomizer.
			float y = round(curShot.getY()) - rndm * 2;
			
			float animationTime = ((sqrt(((rawShot.getX()) * (rawShot.getX())) + ((rawShot.getY()) * (rawShot.getY()))))*timer)/0.02f; // Calculate animation time from raw angle delta.
			// std::cout << "shot number " << shotsFired << "\n";
			smooth_move(x, y, repeatDelay - rndm, animationTime - rndm); // Actual movement function
			
			shotsFired++; //Increment shot counter
			if (chosen.getName() == "M39" || chosen.getName() == "M92" || chosen.getName() == "SAR") {
				Sleep(25);
				break; //Break if single fire.
			}
		}

		else { // Sleep if bullets depleted and still holding, could sleep for reload time of weapon.
			SleepEx(250, false);
			break;
		}

	}
}

void perform_move(const Vec2& delta) { // function to perform actual move
	INPUT move_event;
	move_event.type = INPUT_MOUSE;
	move_event.mi.mouseData = 0;
	move_event.mi.time = 0;
	move_event.mi.dwFlags = MOUSEEVENTF_MOVE;
	move_event.mi.dx = (long)delta.getX();
	move_event.mi.dy = (long)delta.getY();
	SendInput(1, &move_event, sizeof(move_event));
}


void smooth_move(const float& x, const float& y, const float repeatDelay, float animationTime) { // Function to linearly interpolate between shots
	Timer t; //start timer
	Vec2 dest(x, y), moved, perform; // 3xVec2 for documentation of shots 
	bool move = false, time = false; // bools to determine if we finished by exceeding movement or by exceeding time spent in function
	while (1) {
		float lerpTo = t.Elapsed() / animationTime;
		Vec2 perform = (dest.Lerp(lerpTo) - moved).Down();
		perform_move(perform);
		moved = moved + perform;
		SleepEx(1,false); // increase if dogwater cpu
		if (abs(moved.getX()) > abs(dest.getX())) { move = true; break; }
		if (t.Elapsed() + 15.0f > repeatDelay) { time = true; break; }
	}
	if (time && dest.Lenght() != moved.Lenght()) // If exceeded by time, but not moved enough, move anyway.
	{
		perform.setX(dest.getX() - moved.getX());
		perform.setY(dest.getY() - moved.getY());
		perform_move(perform);
		if (t.Elapsed() + 5.0f < repeatDelay)
			Sleep((int)repeatDelay - t.Elapsed());
	}

	else if (move && (repeatDelay - animationTime) > 0.0f) // if exceeded by move but time is not up, sleep.
		Sleep((int)repeatDelay - t.Elapsed());

	else if (time && t.Elapsed() + 5.0f < repeatDelay) // if exceeded by anim time but repeat delay is not up, sleep for remainder.  
		Sleep((int)repeatDelay - t.Elapsed());
	/*
	std::cout << "moved " << moved.getX() << " " << moved.getY() << " for " << t.Elapsed() << "\n";
	std::cout << "should've moved for " << x << " " << y << "\n";
	std::cout << "animation time was: " << animationTime << "\n";
	*/
}




/*
void smooth_move(const float &x, const float &y, const float &repeatDelay, float& animationTime) {
	Timer t;
	Vec2 dest(x,y), moved, perform;
	bool move = false, time = false;
	while (1) {
		float lerpTo = t.Elapsed() / animationTime;
		Vec2 perform = (dest.Lerp(lerpTo) - moved).Down();
		perform_move(perform);
		moved = moved + perform;
		Sleep(5);
		if (abs(moved.getX()) > abs(dest.getX())) {
			std::cout << "break by move.";
			move = true;
			break;
		}
		if (t.Elapsed() + 15.0f > repeatDelay)
		{
			std::cout << "break by timeout.";
			time = true;
			break;
		}

	}

	if (time && dest.getX() != moved.getX())
	{
		perform.setX(dest.getX() - moved.getX());
		perform.setY(dest.getY() - moved.getY());
		perform_move(perform);
		moved = moved + perform;
		std::cout << "moved\n";
		if (t.Elapsed() + 5.0f < repeatDelay)
		{
			Sleep((int)repeatDelay - t.Elapsed());
			std::cout << "Sleeping additionally for " << (int)repeatDelay - t.Elapsed();
		}
	} else if (move && (repeatDelay - animationTime) > 0.0f)
	{
		Sleep((int)repeatDelay - t.Elapsed());
		std::cout << "slept\n";
	}
	else if (time && t.Elapsed() + 5.0f < repeatDelay) {
		Sleep((int)repeatDelay - t.Elapsed());
		std::cout << "Sleeping additionally for " << (int)repeatDelay - t.Elapsed();
	}

	std::cout << "We spent " << t.Elapsed() << "ms in this function.\n";
	std::cout << "We moved " << moved.Lenght() << "(" << moved.getX() << "," << moved.getY() << ")" << " in this function.\n";
	std::cout << "dest was: " << dest.getX() << " " << dest.getY() << "\n";
	std::cout << "delay was: " << repeatDelay << " animation time was " << animationTime << "\n\n\n";
}
*/
