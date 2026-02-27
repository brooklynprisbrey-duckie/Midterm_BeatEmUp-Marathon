#include <iostream>
#include "BeatEmUp.h"
#pragma once

using namespace std;

class EarthClass {
private:
	int health = 50;
public:
	EarthClass();

	int attack();
};