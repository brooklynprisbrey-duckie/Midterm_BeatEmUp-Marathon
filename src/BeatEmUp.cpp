#include "BeatEmUp.h"
#include "EarthClass.h"

Element printMenu(Player &p1) {//TODO fuss over later
	cout << "1. Earth Attack: " << p1.earthAC << endl;
	cout << "2. Metal Attack: " << p1.metalAC << endl;
	cout << "3. Water Attack: " << p1.waterAC << endl;
	cout << "4. Wood Attack: " << p1.woodAC << endl;
	cout << "5. Fire Attack: " << p1.fireAC << endl;
	int choice = 0;
	bool validating = true;
	while (validating) {
		cin >> choice;
		if (cin.fail()) {
			cout << "Invalid entry" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		if (0 > choice || choice > 5) {
			cout << "Invalid number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		validating = false;
	}
	switch (choice) {
	case 1:
		if (p1.earthAC > 0) {
			p1.earthAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return EARTH;
	case 2:
		if (p1.metalAC > 0) {
			p1.metalAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return METAL;
	case 3:
		if (p1.waterAC > 0) {
			p1.waterAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return WATER;
	case 4:
		if (p1.woodAC > 0) {
			p1.woodAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return WOOD;
	case 5:
		if (p1.fireAC > 0) {
			p1.fireAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return EARTH;
	}
}

void Player::introspection() {
	cout << "Your health: " << health << endl;
	return;
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	default_random_engine seed(rand());

	int rounds = 0;
	bool play = true;
	Player itsYou;
	itsYou.seed = seed;

	do {//loop that makes monster
		EarthClass monster(seed);
		monster.inspect();

		while (itsYou.health > 0) {//loop that defeats monster
			itsYou.introspection();

			Element attack = NOPE;
			while (!attack) {
				attack = printMenu(itsYou);//TODO add check if full movepool is empty
			};//should loop if movepool is empty

			monster.defend(attack);

			if (monster.inspect() < 0) {
				cout << "The monster died!" << endl;
				break;
			}

			monster.attack(itsYou,attack);

		}//TODO make deconstructor?

		rounds += 1;
		cout << "You defeated " << rounds << " monsters!" << endl;
		if (rounds == 1) {//TODO make more responsive exit condition
			play = false;
		}

	} while (play);

	return 0;
}