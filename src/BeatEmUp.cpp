#include "BeatEmUp.h"
#include "Earth.h"

int main() {
	int rounds = 0;
	bool play = true;

	do {
		Element attack = printMenu();
		play = false;
	} while (play);

	return 0;
}