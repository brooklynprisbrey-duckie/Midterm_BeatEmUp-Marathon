#include "EarthClass.h"

EarthClass::EarthClass(default_random_engine seed) {
	this->seed = seed;
	cout << "A blob of earth approaches!" << endl;
}

int EarthClass::inspect() {
	cout << "It's muddy." << endl;
	cout << type << " health: " << health << endl;
	return health;
}