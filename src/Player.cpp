#include "Player.h"

Element printAttackMenu(Player& p1) {
	cout << "1. Earth Attack: " << p1.earthAC << endl;
	cout << "2. Metal Attack: " << p1.metalAC << endl;
	cout << "3. Water Attack: " << p1.waterAC << endl;
	cout << "4. Wood Attack: " << p1.woodAC << endl;
	cout << "5. Fire Attack: " << p1.fireAC << endl;
	cout << "0. Other Options" << endl;
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
	choice = static_cast<Element>(choice);
	switch (choice) {
	case EARTH:
		if (p1.earthAC > 0) {
			p1.earthAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return EARTH;
	case METAL:
		if (p1.metalAC > 0) {
			p1.metalAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return METAL;
	case WATER:
		if (p1.waterAC > 0) {
			p1.waterAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return WATER;
	case WOOD:
		if (p1.woodAC > 0) {
			p1.woodAC -= 1;
		}
		else {
			cout << "No moves left." << endl;
			return NOPE;
		}
		return WOOD;
	case FIRE:
		if (p1.fireAC > 0) {
			p1.fireAC -= 1;
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

Element printOtherMenu() {
	cout << "1. Move Conversion (2:1)" << endl;
	cout << "2. Heal (1:1:1:1:1)" << endl;
	cout << "3. Quit" << endl;
	return NOPE;
}

void Player::introspection() {
	cout << "Your health: " << health << endl;
	return;
}

int Player::moveConversion(Element from, Element to) {
	return 0;
}