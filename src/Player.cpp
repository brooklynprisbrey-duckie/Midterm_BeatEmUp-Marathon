#include "Player.h"

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

Element Player::printAttackMenu() {
	cout << "1. Earth Attack: " << earthAC << endl;
	cout << "2. Metal Attack: " << metalAC << endl;
	cout << "3. Water Attack: " << waterAC << endl;
	cout << "4. Wood Attack: " << woodAC << endl;
	cout << "5. Fire Attack: " << fireAC << endl;
	cout << "0. Other Options" << endl;
	int choice = validation(0,5);
	choice = static_cast<Element>(choice);
	switch (choice) {
	case EARTH:
		if (earthAC > 0) {
			earthAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return EARTH;
	case METAL:
		if (metalAC > 0) {
			metalAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return METAL;
	case WATER:
		if (waterAC > 0) {
			waterAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return WATER;
	case WOOD:
		if (woodAC > 0) {
			woodAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return WOOD;
	case FIRE:
		if (fireAC > 0) {
			fireAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return FIRE;
	default:
		return NOPE;
	}
}

bool Player::printOtherMenu() {
	cout << "0. Back" << endl;
	cout << "1. Move Conversion (2:1)" << endl;
	cout << "2. Heal (1:1:1:1:1)" << endl;
	cout << "3. Quit Game" << endl;
	int choice = validation(0,3);
	switch (choice) {
	case 0:
		return true;
	case 1:
		bool validating = true;
		Element choice1; Element choice2;
		while (validating) {
		cout << "Pick move pool to take from:" << endl
			<< "1.Earth: " << earthAC << ", 2.Metal: " << metalAC << ", 3.Water: " << waterAC << ", 4.Wood: " << woodAC << ", 5.Fire: " << fireAC << endl;
		choice1 = static_cast<Element>(validation(1, 5));
		switch (choice1) {
		case EARTH:
			if (earthAC > 1) {
				earthAC -= 2;
				break;
			}
			else {
				cout << "Not enough moves." << endl;
				continue;
			}
		case METAL:
			if (metalAC > 1) {
				metalAC -= 2;
			}
			else {
				cout << "Not enough moves." << endl;
			}
			continue;
		case WATER:
			if (waterAC > 1) {
				waterAC -= 2;
			}
			else {
				cout << "Not enough moves." << endl;
			}
			continue;
		case WOOD:
			if (woodAC > 1) {
				woodAC -= 2;
			}
			else {
				cout << "Not enough moves." << endl;
			}
			continue;
		case FIRE:
			if (fireAC > 1) {
				fireAC -= 2;
			}
			else {
				cout << "Not enough moves." << endl;
			}
			continue;
		default:
			return false;
		}
		validating = false;
		}
		return true;
		moveConversion(choice1, choice2);
	}
	return false;
}

void Player::introspection() {
	cout << "Your health: " << health << endl;
	return;
}

int Player::moveConversion(Element from, Element to) {
	return 0;
}