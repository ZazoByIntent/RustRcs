#include "Mouse.h"
#include "Windows.h"
#include "iostream"
#include "Timer.h"
#include "ReadFromFile.h"
#include "Random.h"

void mouse_move(const Weapon& chosen, const float &timer, const float &random)
{
	unsigned shotsFired = 0; unsigned magSize = chosen.getMagSize(); unsigned rndm = 0; bool once = false;
	float repeatDelay = (1000.0f / (chosen.getRpm() / 60.0f))*timer;
	if (chosen.getName() == "M39" || chosen.getName() == "M92" || chosen.getName() == "SAR") once = true;
	while(1)
	{
		if (!GetAsyncKeyState(VK_LBUTTON) || !GetAsyncKeyState(VK_RBUTTON)) break;
		if (shotsFired <= magSize)
		{
			if (random != 1.0f) rndm = getRandom(random);
			Vec2 curShot = chosen.getPatternAtItr(shotsFired);
			Vec2 rawShot = chosen.getRawPatternAtItr(shotsFired);
			float x = round(curShot.getX()) - rndm;
			float y = round(curShot.getY()) - rndm *2;
			float animationTime = (sqrt(((rawShot.getX()) * (rawShot.getX())) + ((rawShot.getY()) * (rawShot.getY()))))*timer;
			smooth_move(x, y, repeatDelay - rndm, animationTime - rndm);
			shotsFired++;
			if (once) break;
		}
		else {
			SleepEx(250, false);
			break;
		}
	}
}

void perform_move(const Vec2& delta) {
	INPUT move_event;
	move_event.type = INPUT_MOUSE;
	move_event.mi.mouseData = 0;
	move_event.mi.time = 0;
	move_event.mi.dwFlags = MOUSEEVENTF_MOVE;
	move_event.mi.dx = (long)delta.getX();
	move_event.mi.dy = (long)delta.getY();
	SendInput(1, &move_event, sizeof(move_event));
}


void smooth_move(const float& x, const float& y, const float repeatDelay, float animationTime) {
	Timer t;
	Vec2 dest(x, y), moved, perform;
	bool move = false, time = false;
	while (1) {
		float lerpTo = t.Elapsed() / animationTime;
		Vec2 perform = (dest.Lerp(lerpTo) - moved).Down();
		perform_move(perform);
		moved = moved + perform;
		SleepEx(1,false);
		if (abs(moved.getX()) > abs(dest.getX())) { move = true; break; }
		if (t.Elapsed() + 15.0f > repeatDelay) { time = true; break; }
	}
	if (time && dest.Lenght() != moved.Lenght())
	{
		perform.setX(dest.getX() - moved.getX());
		perform.setY(dest.getY() - moved.getY());
		perform_move(perform);
		if (t.Elapsed() + 5.0f < repeatDelay)
			Sleep((int)repeatDelay - t.Elapsed());
	}
	else if (move && (repeatDelay - animationTime) > 0.0f)
		Sleep((int)repeatDelay - t.Elapsed());
	else if (time && t.Elapsed() + 5.0f < repeatDelay)
		Sleep((int)repeatDelay - t.Elapsed());
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
