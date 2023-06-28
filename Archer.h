#include <iostream>
#include "Character.h"
#pragma once

class Archer : public Character
{
public:
    Archer(Race race);
    void attack() override;
    void chargedAttack() override;
    void superAttack() override;
    void rest() override;

};

