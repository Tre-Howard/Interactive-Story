#pragma once

// intialization of all my functions under Story.cpp
#include <iostream>
using namespace std;


void GameplayLoop();
void weaponChoice(int &a); 
void armorChoice(int &a);
int WeaponDamage(int a, int &b); 
string askName(string &a);
int EnemyWeaponDamage(const int &a, int &b);
void healthChecker(int& a, int& b);