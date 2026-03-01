#include "WoodClass.h"

WoodClass::WoodClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, Element type)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF, type } {
	cout << "A leaf-pile approaches!" << endl;
}

int WoodClass::inspect() {
	cout << "It's full of bugs." << endl;
	cout << "Wood health: " << health << endl;
	return health;
}

void WoodClass::interaction(Player& interact, Element act) {
	cout << "Your attack was " << howEffective(switchElementFactor(act)) << "!" << endl
		<< "Wood ";
	defend(act);

	if (health <= 0) {
		return;
	}

	cout << "This leaf pile was not as fun to jump in as you expected!" << endl
		<< "It was made " << howEffective(2 - switchElementFactor(act)) << " by the attack you used!" << endl;
	attack(interact, act);
}