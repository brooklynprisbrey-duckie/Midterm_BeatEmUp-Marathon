#include "Player.h"
#include "MonsterClass.h"
#pragma once

using namespace std;

class FireClass : public MonsterClass {
private:

public:

	FireClass(default_random_engine seed, float earthF = 1.25, float metalF = 0.5, float waterF = 1.5, float woodF = 0.75, float fireF = 0.75, Element type = FIRE);

	int inspect();

	void interaction(Player& interact, Element act);

};