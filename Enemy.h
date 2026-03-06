#pragma once

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int hp, int attackPower);

    void        takeDamage(int dmg);
    bool        isAlive()     const;
    int         hp()          const;
    int         attackPower() const;
    std::string name()        const;

    void printStatus() const;

private:
    std::string _name;
    int         _hp;
    int         _maxHp;
    int         _attackPower;
};