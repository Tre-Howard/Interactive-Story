#include "Creatures.h"

void creature::setHealth(int h)
{
	health = h;
}
void creature::setArmor(int a)
{
	armor = a;
}
void creature::setWeaponMaxDamage(int wmd)
{
	weaponMaxDamage = wmd;
}
int creature::getHealth()
{
	return health;
}
int creature::getArmor()
{
	return armor;
}
int creature::getWeaponMaxDamage()
{
	return weaponMaxDamage;
}
void creature::displayStats()
{
	cout << "Stats: " << endl;
	cout << "------------------------" << endl;
	cout << "Health: " << health;
	cout << "\nArmor: " << armor;
	cout << "\nWeapon Damage: " << weaponMaxDamage;
}


