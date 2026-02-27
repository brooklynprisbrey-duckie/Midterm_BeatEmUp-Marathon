#include "EarthClass.h"

EarthClass::EarthClass(default_random_engine seed) {
	this->seed = seed;
	cout << "A blob of earth approaches!" << endl;
}

int operator-(EarthClass& injParty, float injFactor) {
	uniform_int_distribution<int> injuryGen(5, 10);
	int injury = injuryGen(injParty.seed) * injFactor;
	cout << "damaged by " << injury << endl;
	return injParty.health -= injury;
}

int EarthClass::inspect() {
	cout << "It's muddy." << endl;
	cout << type << " health: " << health << endl;
	return health;
}

float EarthClass::switchElementFactor(Element match) {
	switch (match) {
	case EARTH:
		return earthFactor;
	case METAL:
		return metalFactor;
	case WATER:
		return waterFactor;
	case WOOD:
		return woodFactor;
	case FIRE:
		return fireFactor;
	}
}

void EarthClass::attack(Player &hitYou) {
	hitYou.health -= 10;
	cout << "The " << type << " monster attacked you!" << endl;
	return;
}

void EarthClass::defend(Element playerAttack) {
	float factor = switchElementFactor(playerAttack);
	cout << "Monster was " << * this - factor << endl;
	return;
}