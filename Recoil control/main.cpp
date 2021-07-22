#include "iostream"
#include "Windows.h"
#include "Menu.h"
#include "Mouse.h"


int main()
{
	//TESTING
	/*
		float x1 = 0, y1 = 0, x2 = 0, y2 = 0, delay = 100;
		Vec2 delta(0.0f, 0.0f);
		Vec2 delta2(0.0f, 0.0f);
		while(1)
		{
			if (GetAsyncKeyState(VK_ESCAPE))
			{ 
				std::cout << "Enter x1:\n";
				std::cin >> x1;
				std::cout << "Enter y1:\n";
				std::cin >> y1;
				delta.setX(x1);
				delta.setY(y1);
				std::cout << "Enter x2:\n";
				std::cin >> x2;
				std::cout << "Enter y2:\n";
				std::cin >> y2;
				delta2.setX(x2);
				delta2.setY(y2);
				std::cout << "Enter delay:\n";
				std::cin >> delay;
			}
			if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON)){
				perform_move(delta);
				Sleep(delay);
				perform_move(delta2);
			}
			Sleep(25);
		}
	*/
	
	
	bool paused = false;
	while (1) {
		Sleep(25);
		Weapon chosen = printMenu();
		if (chosen.getName() == "NULL") break;
		float random = getRndm(), timer = getTimer();
		paused = false;
		std::cout << "Script is running.\nPress RMB&LMB to trigger recoil control.\nPress INSERT to open menu.\n";
		while (paused == false)
		{
			if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON)){
				mouse_move(chosen, timer, random);
			}
			if (GetAsyncKeyState(VK_INSERT)) paused = true;
			Sleep(25); // Rest CPU
		}
	}


	// Standing should be 1.0 and crouched should be 0.5
	
	return 0;
}