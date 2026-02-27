#include <iostream>
#include <iomanip>
#include <random>
#pragma once

using namespace std;

//srand(time(0)); TODO figure out why seed isn't working

enum Element {
	NOPE,
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
	void introspection();
};

Element printMenu(Player &checkMoves);
int main();