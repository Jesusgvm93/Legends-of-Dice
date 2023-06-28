#include "Archer.h"
#include "Character.h"
#include <iostream>

Archer::Archer(Race race) : Character(race)
{
	health += (strength * 1.2f);
	mana += (intelligence * 1.5f);
	damage += (strength * 1.2f + agility * 3.0f);
}

void Archer::attack()
{

	cout << "Archer Attacks" << endl;
	mana -= 10.0f;
	int rdmDamage = rand() % 6 + 1;
	damage += rdmDamage;

}

void Archer::chargedAttack()
{

	cout << "Archer Charged Attack" << endl;
	mana -= 20.0f;
	int rdmDamage = (rand() % 6 + 1) * 2.0f;
	damage += rdmDamage;

}

void Archer::superAttack()
{
	cout << "Archer Super Attack" << endl;
	mana -= 30.0f;
	int rdmDamage = (rand() % 6 + 1) * 3.0f;
	damage += rdmDamage;
 

}

void Archer::rest()
{
	cout << "Rest" << endl;
	mana += 10.0;
	if (mana > 100.0)
		mana = 100.0;
}
