#include "BeatEmUp.h"
#pragma once

using namespace std;

class EarthClass {
private:

	default_random_engine seed;
	string type = "Earth";
	int health = 50;
	float earthFactor = 0.75;
	float metalFactor = 1.25;
	float waterFactor = 0.5;
	float woodFactor = 1.5;
	float fireFactor = 0.75;

public:

	EarthClass(default_random_engine seed);

	friend int operator-(EarthClass& injParty, float injfactor);

	int inspect();

	float switchElementFactor(Element match);
	//if you attack the monster with an element that aids it, it grows stronger
	void attack(Player &hitYou, Element boost);

	void defend(Element playerAttack);

};