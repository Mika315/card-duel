#include "Wizard.h"

Wizard::Wizard() : Character(45, 5, "Wizard", 'H') {}

int Wizard::calculateAttack(const Set& played) const {
    int base = played.totalValue();
    if (played.leadSuit() == _affinitySuit)
        base += 8;
    return base;
}