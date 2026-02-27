#include "BeatEmUp.h"
#include "EarthClass.h"

Element printMenu() {//TODO fuss over later
	Player p1;
	cout << "1. Earth Attack: " << p1.earthAC << endl;
	cout << "2. Metal Attack: " << p1.metalAC << endl;
	cout << "3. Water Attack: " << p1.waterAC << endl;
	cout << "4. Wood Attack: " << p1.woodAC << endl;
	cout << "5. Fire Attack: " << p1.fireAC << endl;
	int choice = 0;
	while (cin.fail()) {
		cin >> choice;
		if (cin.fail()) {
			cout << "Invalid entry" << endl;
		}
		if (0 > choice || choice > 5) {
			cout << "Invalid number" << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	switch (choice) {
	case 1: return EARTH;
	case 2: return METAL;
	case 3: return WATER;
	case 4: return WOOD;
	case 5: return EARTH;
	}
	return QUIT;
}

int main() {
	int rounds = 0;
	bool play = true;

	do {
		Element attack = printMenu();
		play = false;
	} while (play);

	return 0;
}