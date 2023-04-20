#pragma once

#include <iostream>
#include <string>

using namespace std;


class creature // creature parent class for character and monsters
{
protected:
	int health;
	int armor;
	int weaponMaxDamage;

public:
	creature()
	{}
	creature(int h, int a, int wmd)
	{
		health = h;
		armor = a;
		weaponMaxDamage = wmd;
	}
	void setName(string);
	void setHealth(int h);
	void setArmor(int a);
	void setWeaponMaxDamage(int wmd);
	string getName();
	int getHealth();
	int getArmor();
	int getWeaponMaxDamage();
	void displayStats();
};

class PlayerCharacter : public creature // child class for player character
{
protected:
	string creatureType;
	// inventory array

public:
	PlayerCharacter()
	{}

	PlayerCharacter(int h, int a, int wmd) : creature(h, a, wmd)
	{
		if (armor == 2)
		{
			health = h - 8;
		}
		else if (armor == 1)
		{
			health = h - 4;
		}
		else
		{
			health = h;
		}
		armor = a;
		weaponMaxDamage = wmd;
	}
	void setCreatureType()
	{
		creatureType = "Human";
	}
	string getCreatureType()
	{
		return creatureType;
	}

};

class Goblin : public creature // child class for goblin enemy
{ 
protected:
	string creatureType;

public:
	Goblin()
	{}

	Goblin(int h, int a, int wmd) : creature(h, a, wmd)
	{
		health = h;
		armor = a;
		weaponMaxDamage = wmd;
	}
	void setCreatureType()
	{
		creatureType = "Goblin";
	}
	string getCreatureType()
	{
		return creatureType;
	}
};

class SlimeBoss : public creature // child class for slimeboss enemy
{
protected:
	string creatureType;

public:
	SlimeBoss()
	{}

	SlimeBoss(int h, int a, int wmd) : creature(h, a, wmd)
	{
		health = h;
		armor = a;
		weaponMaxDamage = wmd;
	}
	void setCreatureType()
	{
		creatureType = "Slime";
	}
	string getCreatureType()
	{
		return creatureType;
	}
};
