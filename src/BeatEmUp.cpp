#include "Player.h"
#include "EarthClass.h"
#include "MetalClass.h"
#include "WaterClass.h"
#include "WoodClass.h"
#include "FireClass.h"

//Loops battle until defeat
template<typename elementalMonster>
elementalMonster arenaBattle(Player& fighter, elementalMonster& monster) {
	while (fighter.health > 0 && monster.getHealth() > 0) {
		Element attack = fighter.printMenu();
		if (attack == NOPE) {
			cout << "You exploded!" << endl;
			fighter.health = 0;
			break;
		}

		monster.interaction(fighter, attack);
	}
	if (fighter.health <= 0) {
		cout << "You have died!" << endl;
	}
	else {
		cout << "You won! You got " << monster.rewardCalc(fighter) << " moves as a reward!" << endl;
	}
	return monster;
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
			EarthClass monster(seed);
			arenaBattle(itsYou, monster);
			break;
		}
		case METAL:
		{
			MetalClass monster(seed);
			arenaBattle(itsYou, monster);
			break;
		}
		case WATER:
		{
			WaterClass monster(seed);
			arenaBattle(itsYou, monster);
			break;
		}
		case WOOD:
		{
			WoodClass monster(seed);
			arenaBattle(itsYou, monster);
			break;
		}
		case FIRE:
		{
			FireClass monster(seed);
			arenaBattle(itsYou, monster);
			break;
		}
		}
		rounds += 1;
		cout << "You fought " << rounds << " monsters!" << endl;
		if (itsYou.health == 0) {
			play = false;
		}
	} while (play);

	return 0;
}