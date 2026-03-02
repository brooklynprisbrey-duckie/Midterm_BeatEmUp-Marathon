#include "Player.h"

//validates that input is an integer within specified range
int Player::validation(int minChoice, int maxChoice) {
	int choice = 0;
	bool validating = true;
	while (validating) {
		cin >> choice;
		if (cin.fail()) {
			cout << "Invalid entry" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (minChoice > choice || choice > maxChoice) {
			cout << "Invalid number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		validating = false;
	}
	return choice;
}

//finds correct movepool, checks if enough moves, reduces and passes element if yes, returns NOPE if not.
Element Player::mpCheck(Element pool, int moveCheck) {
	switch (pool) {
	case EARTH:
		if (earthAC >= moveCheck) {
			earthAC -= moveCheck;
			return pool;
		}
		else {
			cout << "Not enough moves." << endl;
			return NOPE;
		}
	case METAL:
		if (metalAC >= moveCheck) {
			metalAC -= moveCheck;
			return pool;
		}
		else {
			cout << "Not enough moves." << endl;
			return NOPE;
		}
	case WATER:
		if (waterAC >= moveCheck) {
			waterAC -= moveCheck;
			return pool;
		}
		else {
			cout << "Not enough moves." << endl;
			return NOPE;
		}
	case WOOD:
		if (woodAC >= moveCheck) {
			woodAC -= moveCheck;
			return pool;
		}
		else {
			cout << "Not enough moves." << endl;
			return NOPE;
		}
	case FIRE:
		if (fireAC >= moveCheck) {
			fireAC -= moveCheck;
			return pool;
		}
		else {
			cout << "Not enough moves" << endl;
			return NOPE;
		}
	default:
		return NOPE;
	}
}

Element Player::printMenu() {
	Element choice = NOPE;
	bool play = true;
	do {
		choice = printAttackMenu();
		if (choice) {
			choice = mpCheck(choice, 1);//is move allowed?
		}
		else {
			play = printOtherMenu();
			if (play == NOPE) { return NOPE; }//only way to return NOPE
		}
	} while (choice == NOPE);
	return choice;
}


Element Player::printAttackMenu() {
	Element move = NOPE;
	cout << "Your health: " << health << endl;
	cout << "1. Earth Attack: " << earthAC << endl;
	cout << "2. Metal Attack: " << metalAC << endl;
	cout << "3. Water Attack: " << waterAC << endl;
	cout << "4. Wood Attack: " << woodAC << endl;
	cout << "5. Fire Attack: " << fireAC << endl;
	cout << "0. Other Options" << endl;
	Element choice = static_cast<Element>(validation(0, 5));
	return choice;
}
//returns false if quit is chosen. Also handles conversion and healing
bool Player::printOtherMenu() {
	cout << "1. Back" << endl;
	cout << "2. Move Conversion (2:1)" << endl;
	cout << "3. Heal (1:1:1:1:1)" << endl;
	cout << "0. Quit Game" << endl;
	int choice = validation(0,3);
	switch (choice) {
	case 1:
		return true;
	case 2:
	{
		bool valid = false;
		Element choice1; Element choice2;
		while (!valid) {
			cout << "Pick move pool to take from:" << endl
				<< "1.Earth: " << earthAC << ", 2.Metal: " << metalAC << ", 3.Water: " << waterAC << ", 4.Wood: " << woodAC << ", 5.Fire: " << fireAC << endl;
			choice1 = static_cast<Element>(validation(1, 5));
			valid = static_cast<bool>(mpCheck(choice1, 2));
		}
		cout << "Pick move pool to give to:" << endl
			<< "1.Earth: " << earthAC << ", 2.Metal: " << metalAC << ", 3.Water: " << waterAC << ", 4.Wood: " << woodAC << ", 5.Fire: " << fireAC << endl;
		choice2 = static_cast<Element>(validation(1, 5));
		mpCheck(choice2, -1);
		return true;
	}
	case 3:
	{
		if (earthAC > 0 && metalAC > 0 && waterAC > 0 && woodAC > 0 && fireAC > 0) {
			for (int i = 0; i <= FIRE; i++) {
				mpCheck(static_cast<Element>(i), 1);
				health += movePool;
			}
		}
		else {
			cout << "One or more pools is empty" << endl;
		}
		return true;
	}
	}
	return false;
}