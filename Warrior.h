#pragma once
#include "Character.h"

// Warrior – high HP, club affinity (+5 flat bonus when all cards are clubs)
class Warrior : public Character {
public:
    Warrior();
    int calculateAttack(const Set& played) const override;
};