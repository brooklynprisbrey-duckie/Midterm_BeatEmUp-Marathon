#include "MetalClass.h"

MetalClass::MetalClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF } {
	cout << "A blob of red clay approaches!" << endl;
}

int MetalClass::inspect() {
	cout << "It's rusty." << endl;
	cout << type << " health: " << health << endl;
	return health;
}