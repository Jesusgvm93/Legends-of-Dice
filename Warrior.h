#include <iostream>
#include "Character.h"
#pragma once

class Warrior : public Character
{
public:
    Warrior(Race race);
    void attack() override;
    void chargedAttack() override;
    void superAttack() override;
    void rest() override;
};

