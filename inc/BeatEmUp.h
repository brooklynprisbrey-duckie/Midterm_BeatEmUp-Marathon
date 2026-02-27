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

struct Player {
	const int movePool = 20;
	int health = 100;
	int earthAC = movePool;
	int metalAC = movePool;
	int waterAC = movePool;
	int woodAC = movePool;
	int fireAC = movePool;
};

Element printMenu();
int main();