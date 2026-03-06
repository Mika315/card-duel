#include "Archer.h"

Archer::Archer() : Character(35, 7, "Archer", 'S') {}

int Archer::calculateAttack(const Set& played) const {
    int base = played.totalValue();
    if (played.leadSuit() == _affinitySuit)
        base += 3 * played.cardCount();
    return base;
}