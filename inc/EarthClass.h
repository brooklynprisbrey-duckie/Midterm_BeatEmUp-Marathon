#include "BeatEmUp.h"
#include "MonsterClass.h"
#pragma once

using namespace std;

class EarthClass : public MonsterClass {
private:

	string type = "Earth";

public:

	EarthClass(default_random_engine seed, float earthF = 0.75, float metalF = 1.25, float waterF = 0.5, float woodF = 1.5, float fireF = 0.75);

	int inspect();

};