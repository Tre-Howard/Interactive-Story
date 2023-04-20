#include "Story.h" // includes all the headers and vector/algorithm so i can use array stuff for the inventory
#include "Creatures.h"
#include <vector>
#include <algorithm>

void GameplayLoop() // main game right here, see main.cpp for description
{
	int weapon; // weapon choice selector/damage variable
	int armor; // type of armor
	int health = 40; // health for your adventurer
	

	vector<string> inventory; // vector string array to hold the potion in the adventurers backpack
	inventory.push_back("Potion"); // add the potion to the list

	vector<string>::iterator myIterator; // these two are used to point to the inventory and display it for option 3
	vector<string>::const_iterator iter;

	weaponChoice(weapon); // this picks the weapon and store it for different setups on each playthrough on player class creation
	armorChoice(armor); // this picks the armor type and store it for different setups on each playthrough on player class creation

	PlayerCharacter PC(health, armor, weapon); // creates the player character with stats
	cout << "\nHere are your stats based off your decisions";
	PC.displayStats(); // displays all the choices the player picked
	
	int getH; // initialize var for player health
	int &currentHealth = getH; // reference to pointer so it can change through the program
	currentHealth = PC.getHealth(); // make currentHealth variable that will be referenced to the class health above (40)

	do // runs until game is over, if player dies, ends game
	{
		for (int i = 0; i < 3; i++) // runs three scenarios
		{	
			if (i == 0) // scenario one, a goblin enemy using the same people class that also was used to create player character
			{
				cout << "\nCOMBAT!";
				Goblin Gob(10, 0, 4); // goblin person child class
				int getEnH; // same currentHealth for player, this is for getEnemyHealth and attach reference so it can be used in functions 
				int &gobCurrentHealth = getEnH;
				gobCurrentHealth = Gob.getHealth();
				cout << "\nA goblin has appeared! Defend yourself!" << endl;

				do // do this until someone dies
				{
					cout << "\nWhat will you do?" << endl << "1. Attack" << endl << "2. Heal" << endl << "3. Check Inventory" << endl << "4. Quit" << endl << endl;
					int playerChoice;
					cin >> playerChoice; // get input for what u want to do with the menu

					switch (playerChoice) // list of choices
					{
					case 1: // attack, player attacks first with child class PC or playercharacter max weapon damage and returns value for gob health to damage, then 
						// repeats for players health for enemy damage, check to see if game ends or moves on
						WeaponDamage(PC.getWeaponMaxDamage(), gobCurrentHealth);						
						EnemyWeaponDamage(Gob.getWeaponMaxDamage(), currentHealth);
						healthChecker(currentHealth, gobCurrentHealth);

						break;
					case 2: // heal with a potion from your inventory
						if (find(inventory.begin(), inventory.end(), "Potion") != inventory.end())
						{
							cout << "\nYou drink a potion for 10 health. Your new health is: " << PC.getHealth() + 10;
							PC.setHealth(PC.getHealth() + 10);
						}
						else
						{
							cout << "You do not have any potions in your inventory";
						}
						break;

					case 3: // check inventory for potions
						for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
							cout << *iter << endl;
							break;
					case 4: // quit the game
						cout << "\nThanks for playing! Closing Game.";
						exit(0);
						break;
						}
					} 
				} while ((gobCurrentHealth > 0) && (currentHealth > 0)); // keeps going until someone dies
			}
		
			else if (i == 1) // exploration
			{
				int playerChoice;

				cout << "\nYou look around the room and don't seem to find anything else. What would you like to do?" << endl << endl;;
				cout << "\nWhat will you do?" << endl << "1. Explore" << endl << "2. Heal" << endl << "3. Check Inventory" << endl << "4. Quit" << endl << endl;
				cin >> playerChoice;

				switch (playerChoice)
				{
				case 1: // do nothing and continue exploring
					break;

				case 2: // heal with a potion from your inventory
					if (find(inventory.begin(), inventory.end(), "Potion") != inventory.end())
					{
						cout << "\nYou drink a potion for 10 health. Your new health is: " << PC.getHealth() + 10;
						PC.setHealth(PC.getHealth() + 10);
					}
					else
					{
						cout << "\nYou do not have any potions in your inventory";
					}
					break;

				case 3:// check inventory for potions
					for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
						cout << *iter << endl;
						break;

				case 4: // quit the game
					cout << "\nThanks for playing! Closing Game.";
					exit(0);
					break;

					}
				}
			}
			if (i == 2) // boss section, new child class from people
			{
				cout << "\nCOMBAT! A boss appeared!"; // same as before, intialize enemy health and reference it through the program to update constantly
				SlimeBoss Slime(20, 1, 4);
				int getEnH;
				int& SlimeCurrentHealth = getEnH;
				SlimeCurrentHealth = Slime.getHealth();
				cout << "\nA slime boss has appeared! Defend yourself!" << endl;

				do // repeat until someone dies
				{
					cout << "\nWhat will you do?" << endl << "1. Attack" << endl << "2. Heal" << endl << "3. Check Inventory" << endl << "4. Quit" << endl << endl;
					int playerChoice;
					cin >> playerChoice; // take choice from player on menu

					switch (playerChoice) // list of scenarios
					{
					case 1: // attack, player attacks first with child class PC or playercharacter max weapon damage and returns value for gob health to damage, then 
						// repeats for players health for enemy damage, check to see if game ends or moves on
						WeaponDamage(PC.getWeaponMaxDamage(), SlimeCurrentHealth);						
						EnemyWeaponDamage(Slime.getWeaponMaxDamage(), currentHealth);
						healthChecker(currentHealth, SlimeCurrentHealth);
						break;

					case 2:// heal with a potion from your inventory
						if (find(inventory.begin(), inventory.end(), "Potion") != inventory.end())
						{
							cout << "\nYou drink a potion for 10 health. Your new health is: " << PC.getHealth() + 10;
							PC.setHealth(PC.getHealth() + 10);
						}
						else
						{
							cout << "You do not have any potions in your inventory";
						}
						break;

					case 3: // check inventory for potions
						for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
							cout << *iter << endl
								;
							break;

					case 4: // quit the game
						cout << "\nThanks for playing! Closing Game.";
						exit(0);
						break;

						}
					}
				} while ((SlimeCurrentHealth > 0) && (currentHealth > 0)); // keeps going until someone dies

				if (SlimeCurrentHealth <= 0) // after section 3 goes, this will determine if you win or lose depending on slime boss health and ur health
				{
					cout << "\n\nYou Win! Congrats!"; // yayyyy
					exit(0);
				}
				else
				{
					cout << "\n\nYou Lose! Game Over. Try Again."; // awwww
					exit(0);
				}
			} 			
		} 
	} while (PC.getHealth() > 0);  // catch/game over if you die during section 1 or 2

	cout << "Game Over! Try again."; // catch/game over if you die during section 1 or 2
	exit(0);
}

int WeaponDamage(int a, int &b) // player weapon damage, changes based on weapon selected, update enemy health
{
	int attack;
	int min = 1;
	int max = a;

	attack = rand() % (max - min + 1) + min;
	cout << "You did " << attack << " damage!" << endl;
	b -= attack;
	return b;
}


int EnemyWeaponDamage(const int &a, int &b) // enemy damage function and never changes so placed it as void and didnt initialize it at the top, update player health
{
	int attack;

	int min = 1;
	int max = a;

	attack = rand() % (max - min + 1) + min;
	cout << "The enemy did " << attack << " damage!" << endl;
	b -= attack;
	cout << "Your current health is " << b << endl;
	return b;
}

void healthChecker(int &a, int &b) // everytime damage is dealt, check to see if player or enemey health is <= 0, then end the game
{
	if (a <= 0)
	{
		cout << "Game Over! You died.";
		exit(0);
	}
	else if (b <= 0)
	{
		cout << "The enemy has fallen.";
		return;
	}
	else
	{
		return;
	}
}

void weaponChoice(int &a) // function that changes based on the weapon you picked (max damage chance)
{
	int weaponChoice;
	cout << "\n\nNext, what is your weapon of choice?";
	cout << "\nWeapons: " << endl << "1. Sword" << endl << "2. Bow" << endl << "3. Wand" << endl;
	cin >> weaponChoice;

	if (weaponChoice == 1)
	{
		a = 6;
	}
	else if (weaponChoice == 2)
	{		
		a = 8;
	}
	else
	{
		a = 10;
	}
}
void armorChoice(int& a) // this function determines the armor type with a number
{
	int armorChoice;
	cout << "\n\nNext, what is your armor of choice? The heavier armor will protect you more but reduce your health slightly.";
	cout << "\nArmor: " << endl << "1. Plate" << endl << "2. Leather" << endl << "3. Cloth" << endl;
	cin >> armorChoice;

	if (armorChoice == 1)
	{
		a = 2;
	}
	else if (armorChoice == 2)
	{
		a = 1;
	}
	else
	{
		cout << "Invalid choice -- defaulting to Cloth";
		a = 0;
	}
}

string askName(string &a) // function to return to main for input of player name
{
	cout << "Before you go, let's setup your Adventurer!" << endl;
	cout << "What is your name?" << endl;
	cin >> a;
	return a;
}