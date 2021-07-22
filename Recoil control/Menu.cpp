#include "Menu.h"
#include "WriteToFile.h"

Weapon getInput(){
	Weapon chosen;
	while (1)
	{
		if (GetAsyncKeyState(VK_F1))
		{
			std::cout << "Chosen weapon: AR\n";
			chosen.setEntries(29);
			chosen.setName("AR");
			chosen.setMagSize(30);
			chosen.setPattern(getPattern("AR", 29));
			chosen.setRPM(450);

			break;
		}
		if (GetAsyncKeyState(VK_F2))
		{
			std::cout << "Chosen weapon: LR\n";
			chosen.setEntries(31);
			chosen.setName("LR");
			chosen.setMagSize(30);
			chosen.setPattern(getPattern("LR", 31));
			chosen.setRPM(500);
			break;
		}
		if (GetAsyncKeyState(VK_F3))
		{
			std::cout << "Chosen weapon: SAR\n";
			chosen.setEntries(2);
			chosen.setName("SAR");
			chosen.setMagSize(16);
			chosen.setPattern(getPattern("SAR", 2));
			chosen.setRPM(343);
			break;
		}
		if (GetAsyncKeyState(VK_F4))
		{
			std::cout << "Chosen weapon: SMG\n";
			chosen.setEntries(24);
			chosen.setName("SMG");
			chosen.setMagSize(24);
			chosen.setPattern(getPattern("SMG", 24));
			chosen.setRPM(600);
			break;
		}
		if (GetAsyncKeyState(VK_F5))
		{
			std::cout << "Chosen weapon: MP5\n";
			chosen.setEntries(32);
			chosen.setName("MP5");
			chosen.setMagSize(30);
			chosen.setPattern(getPattern("MP5", 32));
			chosen.setRPM(600);
			break;
		}
		if (GetAsyncKeyState(VK_F6))
		{
			std::cout << "Chosen weapon: TOMMY\n";
			chosen.setEntries(19);
			chosen.setName("TOMMY");
			chosen.setMagSize(20);
			chosen.setPattern(getPattern("TOMMY", 19));
			chosen.setRPM(462);
			break;
		}
		if (GetAsyncKeyState(VK_F7))
		{
			std::cout << "Chosen weapon: M92\n";
			chosen.setEntries(1);
			chosen.setName("M92");
			chosen.setMagSize(15);
			chosen.setPattern(getPattern("M92", 1));
			chosen.setRPM(400);
			break;
		}
		if (GetAsyncKeyState(VK_F8))
		{
			std::cout << "Chosen weapon: M39\n";
			chosen.setEntries(1);
			chosen.setName("M39");
			chosen.setMagSize(20);
			chosen.setPattern(getPattern("M39", 1));
			chosen.setRPM(300);
			break;
		}
		if (GetAsyncKeyState(VK_F9))
		{
			std::cout << "Chosen weapon: M249\n";
			chosen.setEntries(1);
			chosen.setName("M249");
			chosen.setMagSize(100);
			chosen.setPattern(getPattern("M249", 1));
			chosen.setRPM(500);
			break;
		}
		if (GetAsyncKeyState(VK_HOME))
		{
			float sens, fov, m, rndm, timer, aftimer;
			std::vector<float> sets;
			std::cout << "Input sensitivity: >\n";
			std::cin >> sens; sets.push_back(sens);
			std::cout << "Input fov: >\n";
			std::cin >> fov; sets.push_back(fov);
			std::cout << "Input strenght: >\n";
			std::cin >> m; sets.push_back(m);
			std::cout << "Input random modifier: >\n";
			std::cin >> rndm; sets.push_back(rndm);
			std::cout << "Input timer modifier: >\n";
			std::cin >> timer; sets.push_back(timer);
			overwriteSettings(sets);
			continue;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			std::cout << "Exiting...\n";
			chosen.setName("NULL");
			break;
		}
	}
	return chosen;
}


float getAttachments() {
	Sleep(500);
	while (1)
	{
		if (GetAsyncKeyState(VK_F1))
		{
			std::cout << "Chosen sight: Silencer\n";
			return 0.8f;
		}
		if (GetAsyncKeyState(VK_F2))
		{
			std::cout << "No attachment\n";
			return 1.0f;
		}
	}
}

float getScope(){
	Sleep(500);
	while (1)
	{
		if (GetAsyncKeyState(VK_F1))
		{
			std::cout << "Chosen sight: Holo\n";
			return 1.18605f;
		}
		if (GetAsyncKeyState(VK_F2))
		{
			std::cout << "Chosen sight: 8x\n";
			return 3.83721f;
		}
		if (GetAsyncKeyState(VK_F3))
		{
			std::cout << "Chosen sight: 16x\n";
			return 7.65116f;
		}
		if (GetAsyncKeyState(VK_F4))
		{
			std::cout << "Chosen sight: Handmade\n";
			return 0.8f;
		}
		if (GetAsyncKeyState(VK_F5))
		{
			return 1.0f;
		}
	}
}

Weapon printMenu() {
	std::vector<float> set = getSettings();
	float sens = set[0], fov = set[1], m = set[2], rndm = set[3], timer = set[4];
	std::cout << "Current sensitivity: " << sens << ", current fov: " << fov << ", current strenght: " << m << ", current random modifier: " << rndm << ", current timer modifier: " << timer << "\n";
	std::cout << "--- PAUSED ---\n Choose option: \n  -F1 : AR\n  -F2 : LR\n  -F3 : SAR\n  -F4 : SMG\n  -F5 : MP5\n  -F6 : TOMMY\n  -F7 : M92\n  -F8 : M39\n  -F9 : M249\n  -HOME : Change settings\n  -ESC : Exit script\n";
	Weapon chosen = getInput();
	if (chosen.getName() == "NULL") return chosen;
	std::cout << "\n Choose attachment: \n  -F1 : Silencer\n  -F2 : None\n";
	float attachment_mult = getAttachments();
	if (attachment_mult != 0.0) chosen.applyMult(attachment_mult);
	std::cout << "Choose scope: \n  -F1 : Holo\n  -F2 : 8x\n  -F3 : 16x\n  -F4 : Handmade\n  -F5 : Ads\n";
	float scope_mult = getScope();
	if (scope_mult != 1.0) chosen.applyMult(scope_mult);
	if (getSettings() != set) {
		set = getSettings(); sens = set[0]; fov = set[1]; m = set[2]; rndm = set[3]; timer = set[4];
	}
	float mult = m * (sens * 3.0f) * (fov / 100.0f);
	chosen.applyMult(mult);
	return chosen;
}