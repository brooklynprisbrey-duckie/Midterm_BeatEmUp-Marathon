#include "MonsterClass.h"

MonsterClass::MonsterClass() { }

MonsterClass::MonsterClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF)
	:seed{ seed }, earthFactor{ earthF }, metalFactor{ metalF }, waterFactor{ waterF }, woodFactor{ woodF }, fireFactor{ fireF }
{
};

//monster getting attack
int operator-(MonsterClass& injParty, float injFactor) {
	uniform_int_distribution<int> injuryGen(5, 10);
	int injury = injuryGen(injParty.seed) * injFactor;
	cout << "damaged by " << injury << endl;
	return injParty.health -= injury;
}
//player getting attacked
int operator-(Player& injParty, float injFactor) {
	uniform_int_distribution<int> injuryGen(5, 10);
	int injury = injuryGen(injParty.seed) / injFactor;
	cout << "damaged by " << injury << endl;
	return injParty.health -= injury;
}

int MonsterClass::inspect() {
	cout << "It's a monster." << endl;
	cout << type << " health: " << health << endl;
	return health;
}

float MonsterClass::switchElementFactor(Element match) {
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

void MonsterClass::attack(Player& hitYou, Element boost) {
	cout << "The " << type << " monster attacked you!" << endl;
	float factor = switchElementFactor(boost);
	cout << "You were " << hitYou - factor << endl;
	return;
}

void MonsterClass::defend(Element playerAttack) {
	float factor = switchElementFactor(playerAttack);
	cout << "Monster was " << *this - factor << endl;
	return;
}