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

	Element type = NOPE;
	int health = 25;
	float rewards = 0.0;

public:

	MonsterClass();

	~MonsterClass();

	MonsterClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, Element type);

	friend int operator-(MonsterClass& injParty, float injfactor);

	int getHealth();

	float switchElementFactor(Element match);

	string howEffective(float elementF);

	//if you attack the monster with an element that aids it, it grows stronger
	void attack(Player& hitYou, Element boost);

	void defend(Element playerAttack);

	int rewardCalc(float elementF);

};