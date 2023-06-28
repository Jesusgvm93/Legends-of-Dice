#include "Warrior.h"
#include "Character.h"
#include <iostream>


Warrior::Warrior(Race race) : Character (race)
{
	health += (strength * 3.0f); //Variables que modifican a las razas aplica para las 3 clases
	mana += (intelligence * 1.5f);
	damage += (strength * 2.0f + agility * 1.5f);
}

void Warrior::attack()
{

	cout << "Warrior Attacks" << endl; //funcion de ataques aplica para las 3 clases
	mana -= 10.0f;
	int rdmDamage = rand() % 6 + 1;
	damage += rdmDamage;

}

void Warrior::chargedAttack()
{
	cout << "Warrior Charged Attack" << endl;
	mana -= 20.0f;
	int rdmDamage = 2.0f * (rand() % 6 + 1);
	damage += rdmDamage;
}

void Warrior::superAttack()
{
	cout << "Warrior Super Attack" << endl;
	mana -= 30.0f;
	int rdmDamage = 3.0f * (rand() % 6 + 1);
	damage += rdmDamage;

}

void Warrior::rest()
{
	cout << "Rest" << endl;
	mana += 10.0;
	if (mana > 100.0)
		mana = 100.0;
}
