//
// Created by Morgan on 10/03/2019.
//

#include "Monster.h"


int Monster::getHealth() const {
    return health;
}

void Monster::setHealth(int health) {
    Monster::health = health;
}

const std::string &Monster::getName() const {
    return name;
}

void Monster::setName(const std::string &name) {
    Monster::name = name;
}

const Weapon &Monster::getWeapon() const {
    return weapon;
}

void Monster::setWeapon(const Weapon &weapon) {
    Monster::weapon = weapon;
}

Monster::Monster() {}

int Monster::getAttackDamage() const {
    return attackDamage;
}

void Monster::setAttackDamage(int attackDamage) {
    Monster::attackDamage = attackDamage;
}

bool Monster::isAlive() const {
    return alive;
}

void Monster::setAlive(bool alive) {
    Monster::alive = alive;
}
