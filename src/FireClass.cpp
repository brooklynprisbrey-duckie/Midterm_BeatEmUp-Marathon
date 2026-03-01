#include "FireClass.h"

FireClass::FireClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF } {
	cout << "A campfire approaches!" << endl;
}

int FireClass::inspect() {
	cout << "Is that... Calcifer?" << endl;
	cout << type << " health: " << health << endl;
	return health;
}