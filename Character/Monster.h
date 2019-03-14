#include <utility>

//
// Created by morgan on 10/03/2019.
//

#ifndef MONK_MONSTER_H
#define MONK_MONSTER_H
#include <string>
#include "../Tools/Weapon.h"

class Monster {
public:

    int health, attackDamage;
    std::string name;
    Weapon weapon;
    bool alive;

    Monster();

    int getHealth() const;

    void setHealth(int health);

    int getAttackDamage() const;

    void setAttackDamage(int attackDamage);

    const std::string &getName() const;

    void setName(const std::string &name);

    bool isAlive() const;

    void setAlive(bool alive);

    const Weapon &getWeapon() const;

    void setWeapon(const Weapon &weapon);
};
#endif //MONK_MONSTER_H
