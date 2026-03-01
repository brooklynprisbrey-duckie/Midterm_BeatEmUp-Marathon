#include "BeatEmUp.h"
#include "MonsterClass.h"
#pragma once

using namespace std;

class WaterClass : public MonsterClass {
private:

	string type = "Water";

public:

	WaterClass(default_random_engine seed, float earthF = 1.5, float metalF = 0.75, float waterF = 0.75, float woodF = 1.25, float fireF = 0.5);

	int inspect();

};