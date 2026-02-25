#include <iostream>
#include "BeatEmUp.h"
#pragma once

using namespace std;

class Earth {
private:
	int health = 50;
public:
	Earth();

	int attack() {
		health -= 10;
		return 0;
	}
};