#include "EarthClass.h"

EarthClass::EarthClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, Element type )
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF, type } {
	cout << "A mudball approaches!" << endl;
}

int EarthClass::inspect() {
	cout << "It's muddy." << endl;
	cout << "Earth health: " << health << endl;
	return health;
}

void EarthClass::interaction(Player& interact, Element act) {
	cout << "Your attack was " << howEffective(switchElementFactor(act)) << "!" << endl
		<< "Earth ";
	defend(act);

	if (health <= 0) {
		return;
	}

	cout << "The earth monster threw a mudball at you!" << endl
		<< "It was made " << howEffective(2-switchElementFactor(act)) << " by the attack you used!" << endl;
	attack(interact, act);
}