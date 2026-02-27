#include "BeatEmUp.h"
#pragma once

using namespace std;

class EarthClass {
private:

	string type = "Earth";
	int health = 50;
	float earthFactor = 0.75;
	float metalFactor = 1.25;
	float waterFactor = 0.5;
	float woodFactor = 1.5;
	float fireFactor = 0.75;

public:

	EarthClass();

	int inspect();

	void attack(Player &hitYou);

	void defend(Element playerAttack, int injury);

};