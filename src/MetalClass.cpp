#include "MetalClass.h"

MetalClass::MetalClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, Element type)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF, type } {
	cout << "A clump of red clay approaches!" << endl;
}

int MetalClass::inspect() {
	cout << "It's rusty." << endl;
	cout << "Metal health: " << health << endl;
	return health;
}

void MetalClass::interaction(Player& interact, Element act) {
	cout << "Your attack was " << howEffective(switchElementFactor(act)) << "!" << endl
		<< "Metal ";
	defend(act);

	if (health <= 0) {
		return;
	}

	cout << "The metal monster showed off its sculpting!" << endl
		<< "It was made " << howEffective(2 - switchElementFactor(act)) << " by the attack you used!" << endl;
	attack(interact, act);
}