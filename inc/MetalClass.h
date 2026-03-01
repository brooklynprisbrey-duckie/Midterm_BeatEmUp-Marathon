#include "BeatEmUp.h"
#include "MonsterClass.h"
#pragma once

using namespace std;

class MetalClass : public MonsterClass {
private:

public:

	MetalClass(default_random_engine seed, float earthF = 0.75, float metalF = 0.75, float waterF = 1.25, float woodF = 0.5, float fireF = 1.5, Element type = METAL );

	int inspect();

	void interaction(Player& interact, Element act);

};