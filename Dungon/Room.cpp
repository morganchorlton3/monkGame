//
// Created by morga on 10/03/2019.
//

#include <iostream>
#include "Room.h"


Room::Room(const string &name, int type, bool monster) : name(name), type(type), monster(monster) {}

const string &Room::getName() const {
    return name;
}

void Room::setName(const string &name) {
    Room::name = name;
}

int Room::getType() const {
    return type;
}

void Room::setType(int type) {
    Room::type = type;
}

bool Room::isMonster() const {
    return monster;
}

void Room::setMonster(bool monster) {
    Room::monster = monster;
}
