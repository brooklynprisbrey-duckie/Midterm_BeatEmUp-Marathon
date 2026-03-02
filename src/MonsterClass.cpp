#include "MonsterClass.h"

MonsterClass::MonsterClass() { }

MonsterClass::MonsterClass(default_random_engine seed, float earthF, float metalF, float waterF, float woodF, float fireF, Element type)
	:seed{ seed }, earthFactor{ earthF }, metalFactor{ metalF }, waterFactor{ waterF }, woodFactor{ woodF }, fireFactor{ fireF }, type{ type }
{
};

//monster getting attack
int operator-(MonsterClass& injParty, float injFactor) {
	uniform_int_distribution<int> injuryGen(5, 10);
	int injury = injuryGen(injParty.seed) * injFactor;
	cout << "damaged by " << injury << endl
		<< "Remaining health: ";
	return injParty.health -= injury;
}
//player getting attacked
int operator-(Player& injParty, float injFactor) {
	uniform_int_distribution<int> injuryGen(5, 10);
	int injury = injuryGen(injParty.seed) / injFactor;
	cout << "damaged by " << injury << endl
		<< "Remaining health: ";
	return injParty.health -= injury;
}

int MonsterClass::getHealth() { return health; }

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

string MonsterClass::howEffective(float elementF) {
	if (elementF <= 0.5) { return "very ineffective"; }
	else if (elementF <= 0.75) { return "ineffective"; }
	else if (elementF <= 1.25) { return "effective"; }
	else if (elementF <= 1.50) { return "very effective"; }
	else return "...what did you attack with...?";
}

void MonsterClass::attack(Player& hitYou, Element boost) {
	float factor = switchElementFactor(boost);
	cout << "You were " << hitYou - factor << endl << endl;
	return;
}

void MonsterClass::defend(Element playerAttack) {
	float factor = switchElementFactor(playerAttack);
	rewards += 2 - factor; //hitting the monster makes it bigger
	cout << "monster was " << *this - factor << endl << endl;
	return;
}

int MonsterClass::rewardCalc(Player& victor) {
	int mpBoost;
	mpBoost = static_cast<int>(rewards);
	switch (type) {//ineffective moves result in a higher reward, thus a greater reward to your movepool
	case EARTH:
		victor.earthAC += mpBoost;
		break;
	case METAL:
		victor.metalAC += mpBoost;
		break;
	case WATER:
		victor.waterAC += mpBoost;
		break;
	case WOOD:
		victor.woodAC += mpBoost;
		break;
	case FIRE:
		victor.fireAC += mpBoost;
		break;
	}//if I add a multiplying factor to the rewards, use another overload operator.
	return mpBoost;
}