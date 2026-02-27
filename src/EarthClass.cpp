#include "EarthClass.h"

void EarthClass::inspect() {
	cout << "A blob of earth approaches!" << endl;
	cout << "Health: " << health;
	return;
}

void EarthClass::attack(Player &hitYou) {
	hitYou.health -= 10;
	return;
}

void EarthClass::defend(Element playerAttack, int injury) {
	switch (playerAttack) {
	case EARTH:
		injury *= earthFactor;
		cout << "Injury multiplied by factor of " << earthFactor << endl;
		break;
	case METAL:
		injury *= metalFactor;
		cout << "Injury multiplied by factor of " << metalFactor << endl;
		break;
	case WATER:
		injury *= waterFactor;
		cout << "Injury multiplied by factor of " << waterFactor << endl;
		break;
	case WOOD:
		injury *= woodFactor;
		cout << "Injury multiplied by factor of " << woodFactor << endl;
		break;
	case FIRE:
		injury *= fireFactor;
		cout << "Injury multiplied by factor of " << fireFactor << endl;
		break;
	}
	health -= injury; //TODO consider overloading this operator to autogenerate injury amount to be multiplied by supplied factor
	return;
}