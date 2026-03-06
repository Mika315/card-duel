#pragma once
#include "Character.h"

// Archer – lower HP, spade affinity (+3 per card in set when all spades)
class Archer : public Character {
public:
    Archer();
    int calculateAttack(const Set& played) const override;
};