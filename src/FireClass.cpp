#include "FireClass.h"

FireClass::FireClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, Element type)
	: MonsterClass{ seed, earthF, metalF, waterF, woodF, fireF, type } {
	cout << "A campfire approaches!" << endl;
}

int FireClass::inspect() {
	cout << "Is that... Calcifer?" << endl;
	cout << "Fire health: " << health << endl;
	return health;
}

void FireClass::interaction(Player& interact, Element act) {
	cout << "Your attack was " << howEffective(switchElementFactor(act)) << "!" << endl
		<< "Fire ";
	defend(act);

	if (health <= 0) {
		return;
	}

	cout << "The fire monster sparked at you!" << endl
		<< "It was made " << howEffective(2 - switchElementFactor(act)) << " by the attack you used!" << endl;
	attack(interact, act);
}