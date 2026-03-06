#pragma once

#include <string>
#include "Set.h"

class Character {
public:
    Character(int hp, int maxHandSize, const std::string& name, char affinitySuit);
    virtual ~Character() = default;

    // Each subclass defines how a played set maps to final attack damage.
    virtual int  calculateAttack(const Set& played) const = 0;
    virtual void takeDamage(int dmg);
    virtual void heal(int amount);

    bool        isAlive()      const;
    int         hp()           const;
    int         maxHandSize()  const;
    std::string name()         const;
    char        affinitySuit() const;

    void printStatus() const;

protected:
    int         _hp;
    int         _maxHp;
    int         _maxHandSize;
    std::string _name;
    char        _affinitySuit;  // 'C', 'S', 'H', or 'D'
};