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
	Element mpCheck(Element pool, int checkAmount);
	const int movePool = 10; //movePool also determines healing amount
	int health = 100;
	int earthAC = movePool;
	int metalAC = movePool;
	int waterAC = movePool;
	int woodAC = movePool;
	int fireAC = movePool;
	Element printMenu();
private:
	Element printAttackMenu();
	bool printOtherMenu();
};