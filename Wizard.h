#pragma once
#include "Character.h"

// Wizard – moderate HP, heart affinity (+8 bonus when all cards are hearts)
class Wizard : public Character {
public:
    Wizard();
    int calculateAttack(const Set& played) const override;
};