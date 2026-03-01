#include "BeatEmUp.h"
#pragma once

using namespace std;

class MonsterClass {
private:

	default_random_engine seed;
	string type = "Monster";
	int health = 50;
	float earthFactor;
	float metalFactor;
	float waterFactor;
	float woodFactor;
	float fireFactor;

public:

	MonsterClass();

	MonsterClass(default_random_engine seed);

	MonsterClass(default_random_engine seed, float earthFactor, float metalFactor, float waterFactor, float woodFactor, float fireFactor);

	friend int operator-(MonsterClass& injParty, float injfactor);

	int inspect();

	float switchElementFactor(Element match);
	//if you attack the monster with an element that aids it, it grows stronger
	void attack(Player& hitYou, Element boost);

	void defend(Element playerAttack);

};