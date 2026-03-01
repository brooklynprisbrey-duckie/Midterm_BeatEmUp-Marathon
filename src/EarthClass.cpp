#include "EarthClass.h"

EarthClass::EarthClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, string type )
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF, type } {
}

int EarthClass::inspect() {
	cout << "It's muddy." << endl;
	cout << type << " health: " << health << endl;
	return health;
}

void EarthClass::interaction(Player& interact, Element act) {
	defend(act);
	if (health < 0) {
		return;
	}
	attack(interact, act);
}