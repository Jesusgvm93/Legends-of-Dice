#include <iostream>
#include "Character.h"
using namespace std;

Character::Character(Race race) 
{
	switch (race)
	{
	case Race::Human: //Atributos por raza
		strength = 4;
		agility = 3;
		intelligence = 3;
		break;
	case Race::Elf:
		strength = 2;
		agility = 4;
		intelligence = 4;
		break;
	case Race::Dwarf:
		strength = 5;
		agility = 2;
		intelligence = 3;
		break;
	case Race::Orc:
		strength = 6;
		agility = 2;
		intelligence = 2;
		break;
	}
}

Character::~Character()
{
}

void Character::printStatistics()
{
	string playerStatistics; //función para imprimir estadisticas dependiendo de la raza

	switch (race)
	{
	case Race::Human:
		playerStatistics = "Human";
		break;
	case Race::Elf:
		playerStatistics = "Elf";
		break;
	case Race::Dwarf:
		playerStatistics = "Dwarf";
		break;
	case Race::Orc:
		playerStatistics = "Orc";
		break;
	}

	cout << "Strength: " << strength << endl;
	cout << "Agility: " << agility << endl;
	cout << "Intelligence: " << intelligence << endl;
	cout << "Health: " << health << endl;
	cout << "Mana: " << mana << endl;
	cout << "Damage: " << damage << endl;

} 

void Character::reduceHealth(int damage)
{
	health -= damage; //Verificación de salud
	if (health < 0)
	{
		health = 0;
	}
}

void Character::increasHealth(int amount)
{
	health += amount; //incremento de vida por ganar combate
}


float Character::getHealth()
{
	return health;
}

float Character::getMana()
{
	return mana;
}

float Character::getDamage()
{
	return damage;
}


