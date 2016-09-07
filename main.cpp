

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Animal {
public:
	Animal() {
		position = 1;
	}
	virtual void Move() {}
	int GetPosition() {
		return position;
	}
	void Reset() {
		position = 1;
	}
protected:
	int position;
};

class Tortoise : public Animal {
public:
	void Move() {
		int moveProbability = rand() % 10 + 1;

		if (moveProbability >= 1 && moveProbability <= 5) { // Fast Plod
			position += 3;
		}
		else if (moveProbability >= 6 && moveProbability <= 7) { // Slip
			position -= 6;
		}
		else if (moveProbability >= 8 && moveProbability <= 10) { // Slow Plod
			position += 1;
		}

		if (position < 1) { // Prevent falling off the beginning of the racetrack
			position = 1;
		}
		else if (position > 70) { // Prevent falling off the end of the racetrack
			position = 70;
		}
	}
};

class Hare : public Animal {
public:
	void Move() {
		int moveProbability = rand() % 10 + 1; // Make a random number from 1-10

		if (moveProbability >= 1 && moveProbability <= 2) { // Sleep
			// No move made.
		}
		else if (moveProbability >= 3 && moveProbability <= 4) { // Big Hop
			position += 9;
		}
		else if (moveProbability == 5) { // Big Slip
			position -= 12;
		}
		else if (moveProbability >= 6 && moveProbability <= 8) { // Small Hop
			position += 1;
		}
		else if (moveProbability >= 9 && moveProbability <= 10) { // Small Slip
			position -= 2;
		}

		if (position < 1) {
			position = 1;
		}
		else if (position > 70) {
			position = 70;
		}
	}
};


string Race(Tortoise tortoise, Hare hare);

int main() {
	srand(unsigned int(time(NULL)));
	Tortoise tortoise;
	Hare hare;
	std::string winner;

	winner = Race(tortoise, hare);

	char dummy; // Make the window not disappear.
	cout << "Enter a character and press enter to exit.\n";
	fflush(stdin);
	cin >> dummy;
}


string Race(Tortoise tortoise, Hare hare) {
	string winner = "no one"; // No one;
	string printingLine(76, ' '); // Zero index is not used, which means one extra element, plus another five in case they bump (tie) at the finish line.
	string bump = "BUMP!";
	int i;

	cout << "Bang! Off they go!\n";

	while(winner == "no one") {
		tortoise.Move();
		hare.Move();

		// Prepare the line for printing
		if (tortoise.GetPosition() == hare.GetPosition()) { // They are on in the same position
			for (i = 0; i < 5; i++) {
				printingLine.at(tortoise.GetPosition() + i) = bump.at(i); // Print BUMP! in their position
			}
		}
		else { // Print T for tortoise and H for hare in their positions on the printingLine
			printingLine.at(tortoise.GetPosition()) = 'T';
			printingLine.at(hare.GetPosition()) = 'H';
		}

		cout << printingLine << endl;

		if (tortoise.GetPosition() == 70 && hare.GetPosition() == 70) { // A tie.
			cout << "Tie score--no winner! Want to race again?\n";
			return "tie";
		}
		else if (tortoise.GetPosition() == 70) { // Tortoise wins.
			cout << "Woo-hooo! Slow and steady wins the race! Congratulations, turtle!\n";
			return "tortoise";
		}
		else if (hare.GetPosition() == 70) { // Hare wins.
			cout << "Yay! The rabbit won! He hops the fastest!\n";
			return "rabbit";
		}

		// return printingString to previous state in preparation for next loop.
		for (i = 0; i < 75; ++i) {
			printingLine.at(i) = ' ';
		}

		Sleep(200); // Wait a bit so the user can watch the race as it progresses. I chose a quarter of a second because I got 
		            // impatient waiting a full second for each round.
	}
	return "error";

}