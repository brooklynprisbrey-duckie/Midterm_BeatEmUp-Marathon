#include "EarthClass.h"

EarthClass::EarthClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF )
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF } {
	cout << "A blob of earth approaches!" << endl;
}

int EarthClass::inspect() {
	cout << "It's muddy." << endl;
	cout << type << " health: " << health << endl;
	return health;
}