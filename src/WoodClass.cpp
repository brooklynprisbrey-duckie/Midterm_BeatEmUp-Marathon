#include "WoodClass.h"

WoodClass::WoodClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF } {
	cout << "A leaf-pile approaches!" << endl;
}

int WoodClass::inspect() {
	cout << "It's full of bugs." << endl;
	cout << type << " health: " << health << endl;
	return health;
}