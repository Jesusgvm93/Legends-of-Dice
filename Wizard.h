#include <iostream>
#include "Character.h"
#pragma once

class Wizard : public Character
{
public:
	Wizard(Race race);
    void attack() override;
    void chargedAttack() override;
    void superAttack() override;
    void rest() override;
};

