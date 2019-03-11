//
// Created by morga on 10/03/2019.
//

#include <iostream>
#include "Room.h"

Room::Room(int type, bool monster) : type(type), monster(monster) {}


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
void Room::printRoom(){
    std::cout << " Type: " << type << " Monster: " << monster << "\n";
};
