#include <iostream>
#include <iomanip>
#include <random>
#pragma once

using namespace std;

enum Element {
	NOPE,
	EARTH,
	METAL,
	WATER,
	WOOD,
	FIRE,
};

struct Player {
	default_random_engine seed;
	const int movePool = 10;
	int health = 100;
	int earthAC = movePool;
	int metalAC = movePool;
	int waterAC = movePool;
	int woodAC = movePool;
	int fireAC = movePool;
	void introspection();
	int moveConversion(Element from, Element to);
};

Element printAttackMenu(Player& checkMoves);

Element printOtherMenu();