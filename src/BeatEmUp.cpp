#include "Player.h"
#include "EarthClass.h"
#include "MetalClass.h"
#include "WaterClass.h"
#include "WoodClass.h"
#include "FireClass.h"

template<typename elementalMonster>
elementalMonster arenaBattle(Player& fighter, elementalMonster& monster) {
	while (fighter.health > 0 && monster.getHealth() > 0) {//loop that defeats monster
		fighter.introspection();

		Element attack = NOPE;
		attack = printAttackMenu(fighter);
		if (!attack) {

		}

		monster.interaction(fighter, attack);
	}
	if (fighter.health <= 0) {
		cout << "You have died!" << endl;
	}
	else {
		cout << "You won! You got " << monster.rewardCalc(fighter) << " moves as a reward!" << endl;
		return monster;
	}
};

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	default_random_engine seed(rand());

	int rounds = 0;
	bool play = true;
	Player itsYou;
	itsYou.seed = seed;

	do {//Put yourself in the arena
		uniform_int_distribution<int> monsterGen(1, 5);
		int yolk = monsterGen(seed);
		Element embryo = static_cast<Element>(yolk);
		switch (embryo) {
		case EARTH:
		{
			EarthClass m1(seed);
			arenaBattle(itsYou, m1);
			break;
		}
		case METAL:
		{
			MetalClass m2(seed);
			arenaBattle(itsYou, m2);
			break;
		}
		case WATER:
		{
			WaterClass m3(seed);
			arenaBattle(itsYou, m3);
			break;
		}
		case WOOD:
		{
			WoodClass m4(seed);
			arenaBattle(itsYou, m4);
			break;
		}
		case FIRE:
		{
			FireClass m5(seed);
			arenaBattle(itsYou, m5);
			break;
		}
		}
		rounds += 1;
		cout << "You fought " << rounds << " monsters!" << endl;
		if (itsYou.health == 0) {//TODO make more responsive exit condition
			play = false;
		}
	} while (play);

	return 0;
}