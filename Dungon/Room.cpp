//
// Created by morga on 10/03/2019.
//

#include <iostream>
#include "Room.h"

Room::Room(const string &name, int type, int X, int Y, bool visited) : name(name), type(type), X(X), Y(Y), visited(visited) {}

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

int Room::getX() const {
    return X;
}

void Room::setX(int X) {
    Room::X = X;
}

int Room::getY() const {
    return Y;
}

void Room::setY(int Y) {
    Room::Y = Y;
}

bool Room::isVisited() const {
    return visited;
}

void Room::setVisited(bool visited) {
    Room::visited = visited;
}
