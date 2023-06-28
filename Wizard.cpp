#include "Wizard.h"
#include "Character.h"
#include <iostream>

Wizard::Wizard(Race race) : Character(race)
{
	health += (strength * 1.1f);
	mana += (intelligence * 4.0f);
	damage += (strength * 2.0f + agility * 2.0f);

}

void Wizard::attack()
{

		cout << "Wizard Attacks" << endl;
		mana -= 10.0f;
		int rdmDamage = rand() % 6 + 1;
		damage += rdmDamage;

}

void Wizard::chargedAttack()
{

		cout << "Wizard Charged Attack" << endl;
		mana -= 20.0f;
		int rdmDamage = 2.0f * (rand() % 6 + 1);
		damage += rdmDamage;
	

}

void Wizard::superAttack()
{

		cout << "Wizard Super Attack" << endl;
		mana -= 30.0f;
		int rdmDamage = 3.0f * (rand() % 6 + 1);
		damage += rdmDamage;

}

void Wizard::rest()
{
	cout << "Rest" << endl;
	mana += 10.0;
	if (mana > 100.0)
		mana = 100.0;
}
