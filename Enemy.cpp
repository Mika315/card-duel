#include "Enemy.h"

#include <algorithm>
#include <iostream>

Enemy::Enemy(const std::string& name, int hp, int atk)
    : _name(name), _hp(hp), _maxHp(hp), _attackPower(atk) {}

void Enemy::takeDamage(int dmg) {
    _hp = std::max(0, _hp - dmg);
}

bool        Enemy::isAlive()     const { return _hp > 0; }
int         Enemy::hp()          const { return _hp; }
int         Enemy::attackPower() const { return _attackPower; }
std::string Enemy::name()        const { return _name; }

void Enemy::printStatus() const {
    std::cout << "[" << _name << "]  HP: " << _hp << " / " << _maxHp << "\n";
}