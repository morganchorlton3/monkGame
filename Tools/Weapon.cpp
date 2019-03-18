//
// Created by morga on 10/03/2019.
//

#include <iostream>
#include "Weapon.h"


Weapon::Weapon() {}

Weapon::Weapon(int id, const string &name, const string &type, int attackDamage) : id(id), name(name), type(type),
                                                                                   attackDamage(attackDamage) {}

int Weapon::getId() const {
    return id;
}

void Weapon::setId(int id) {
    Weapon::id = id;
}

const string &Weapon::getName() const {
    return name;
}

void Weapon::setName(const string &name) {
    Weapon::name = name;
}

const string &Weapon::getType() const {
    return type;
}

void Weapon::setType(const string &type) {
    Weapon::type = type;
}

int Weapon::getAttackDamage() const {
    return attackDamage;
}

void Weapon::setAttackDamage(int attackDamage) {
    Weapon::attackDamage = attackDamage;
}

void Weapon::print(){
    cout << "   Name: " << name << endl;
    cout << "   Type: " << type << endl;
    cout << "   Attack Damage: " << attackDamage << endl;
}
