#include <iostream>
#include <iomanip>
#pragma once

using namespace std;

enum Element {
	QUIT,
	EARTH,
	METAL,
	WATER,
	WOOD,
	FIRE,
};

struct {
	const int movePool = 20;
	int health = 100;
	int earthAC = movePool;
	int metalAC = movePool;
	int waterAC = movePool;
	int woodAC = movePool;
	int fireAC = movePool;
} player;

Element printMenu() {//TODO fuss over later
	cout << "1. Earth Attack: " << player.earthAC << endl;
	cout << "2. Metal Attack: " << player.metalAC << endl;
	cout << "3. Water Attack: " << player.waterAC << endl;
	cout << "4. Wood Attack: " << player.woodAC << endl;
	cout << "5. Fire Attack: " << player.fireAC << endl;
	int choice = 0;
	while (cin.fail()){
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