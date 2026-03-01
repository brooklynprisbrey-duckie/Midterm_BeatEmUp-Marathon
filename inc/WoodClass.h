#include "BeatEmUp.h"
#include "MonsterClass.h"
#pragma once

using namespace std;

class WoodClass : public MonsterClass {
private:

public:

	WoodClass(default_random_engine seed, float earthF = 0.5, float metalF = 1.5, float waterF = 0.75, float woodF = 0.75, float fireF = 1.25, Element type = WOOD );

	int inspect();

	void interaction(Player& interact, Element act);

};