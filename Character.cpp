#include "Character.h"
#include <iostream>
#include <algorithm>

Character::Character(int hp, int maxHandSize, const std::string& name, char affinitySuit)
    : _hp(hp), _maxHp(hp), _maxHandSize(maxHandSize),
      _name(name), _affinitySuit(affinitySuit) {}

void Character::takeDamage(int dmg) {
    _hp = std::max(0, _hp - dmg);
}

void Character::heal(int amount) {
    _hp = std::min(_maxHp, _hp + amount);
}

bool        Character::isAlive()      const { return _hp > 0; }
int         Character::hp()           const { return _hp; }
int         Character::maxHandSize()  const { return _maxHandSize; }
std::string Character::name()         const { return _name; }
char        Character::affinitySuit() const { return _affinitySuit; }

void Character::printStatus() const {
    std::cout << "[" << _name << "]  HP: " << _hp << " / " << _maxHp << "\n";
}