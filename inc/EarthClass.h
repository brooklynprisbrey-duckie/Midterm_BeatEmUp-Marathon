#include "BeatEmUp.h"
#include "MonsterClass.h"
#pragma once

using namespace std;

class EarthClass : public MonsterClass {
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

	int inspect();

};