#include "WaterClass.h"

WaterClass::WaterClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, Element type)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF, type } {
	cout << "A puddle approaches!" << endl;
}

int WaterClass::inspect() {
	cout << "It's wet." << endl;
	cout << "Water health: " << health << endl;
	return health;
}

void WaterClass::interaction(Player& interact, Element act) {
	cout << "Your attack was " << howEffective(switchElementFactor(act)) << "!" << endl
		<< "Water ";
	defend(act);

	if (health <= 0) {
		return;
	}

	cout << "The water monster threw a fish at you!" << endl
		<< "It was made " << howEffective(2 - switchElementFactor(act)) << " by the attack you used!" << endl;
	attack(interact, act);
}