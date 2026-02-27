#include <iostream>
#include <iomanip>
#include <random>
#pragma once

using namespace std;

//srand(time(0)); TODO figure out why seed isn't working

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
	void introspection();//TODO do I define this function out of struct?
};

Element printMenu(Player &checkMoves);
int main();