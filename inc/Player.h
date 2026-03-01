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
	int validation(int minChoice, int maxChoice);
	const int movePool = 10;
	int health = 100;
	int earthAC = movePool;
	int metalAC = movePool;
	int waterAC = movePool;
	int woodAC = movePool;
	int fireAC = movePool;
	Element printAttackMenu();
	bool printOtherMenu();
	void introspection();
	int moveConversion(Element from, Element to);
};