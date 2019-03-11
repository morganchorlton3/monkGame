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
    Monster(int health, std::string name, const Weapon &weapon);

    int getHealth() const;

    void setHealth(int health);

    const std::string &getName() const;

    void setName(const std::string &name);

    const Weapon &getWeapon() const;

    void setWeapon(const Weapon &weapon);

private:
    int health;
    std::string name;
    Weapon weapon;
};
#endif //MONK_MONSTER_H
