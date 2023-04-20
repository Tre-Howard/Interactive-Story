#include "Creatures.h" // add all of the headers and io stream/std to make it work
#include "Story.h"
#include <iostream>

using namespace std;

int main()
{
	string playerName;

	cout << "Welcome Adventurer. You have been handed a contract from the Guild's Hall to deal with a problem in the basement of the local Tavern. Word from "
		"the tavern owner is that some monsters have dug a tunnel and opened the walls in his basement. Go there and clear out anything you see. The owner said"
		" that you mean take anything you need while on this contract." << endl; // game definition/how-to
	cout << "-------------------------------------------" << endl << endl;

	askName(playerName); // asks for players name
	cout << "\nWelcome " << playerName; // produces players name

    GameplayLoop(); // plays the game, selects setup, displays it, gameplay loop for 3 sections, win/lose condition
}