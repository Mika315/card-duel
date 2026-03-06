#include "Warrior.h"

Warrior::Warrior() : Character(60, 6, "Warrior", 'C') {}

int Warrior::calculateAttack(const Set& played) const {
    int base = played.totalValue();
    if (played.leadSuit() == _affinitySuit)
        base += 5;
    return base;
}