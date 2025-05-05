#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>

using namespace std;

vector<string> habits;
vector<string> menuEntrys;
vector<string> extra;

int cmi = 0;

void printMenu();

int main() {
	habits.push_back("Test");
	
	// Main Loop
	while (true) {
		system("cls");
		
		// Menu
		printMenu();
		
		// Input
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
            cmi--;
            Sleep(200);
        }
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			cmi++;
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (cmi < habits.size()) {
				
			} else {
				
			}

		}
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }
	}
}

void printMenu() {
	menuEntrys = habits;
	extra = { "Add", "Edit", "Remove", "Exit" };
	menuEntrys.insert(menuEntrys.end(), extra.begin(), extra.end());
	// List Habits
	for (size_t i = 0; i < menuEntrys.size(); ++i) {
		string entry = menuEntrys[i];
		if (i == cmi) {
			cout << "\033[47m\033[30m " << entry << "\033[0m" << endl;
		} else {
			cout << entry << endl;
		}
	}
}