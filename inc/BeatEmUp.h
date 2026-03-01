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
	const int movePool = 20;
	int health = 100;
	int earthAC = movePool;
	int metalAC = movePool;
	int waterAC = movePool;
	int woodAC = movePool;
	int fireAC = movePool;
	void introspection();
};

Element printMenu(Player& checkMoves);

template<typename elementalMonster>
elementalMonster arenaBattle(Player& fighter, elementalMonster& monster);

int main();