#include "BeatEmUp.h"
#pragma once

using namespace std;

class MonsterClass {
private:

	default_random_engine seed;
	float earthFactor;
	float metalFactor;
	float waterFactor;
	float woodFactor;
	float fireFactor;

protected:

	string type = "Monster";
	int health = 50;

public:

	MonsterClass();

	MonsterClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF);

	friend int operator-(MonsterClass& injParty, float injfactor);

	int inspect();

	float switchElementFactor(Element match);
	//if you attack the monster with an element that aids it, it grows stronger
	void attack(Player& hitYou, Element boost);

	void defend(Element playerAttack);

};