#include <iostream>
#pragma once
using namespace std;

enum class Race {Human, Elf, Dwarf, Orc};

class Character
{
protected:
	Race race;
	float health = 100.0f;
	float mana = 100.0f;
	float damage = 0.0f;

	int strength;
	int agility;
	int intelligence;

public:
	Character(Race race);
	~Character();

	void printStatistics();
	float getHealth();
	float getMana();
	float getDamage();

	void reduceHealth(int damage);
	void increasHealth(int amount);


	virtual void attack() = 0;
	virtual void chargedAttack() = 0;
	virtual void superAttack() = 0;
	virtual void rest() = 0;
};

