#include "WaterClass.h"

WaterClass::WaterClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF } {
	cout << "A puddle approaches!" << endl;
}

int WaterClass::inspect() {
	cout << "It's wet." << endl;
	cout << type << " health: " << health << endl;
	return health;
}