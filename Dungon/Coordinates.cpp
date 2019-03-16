//
// Created by morga on 14/03/2019.
//

#include "Coordinates.h"

int Coordinates::getX() const {
    return x;
}

Coordinates::Coordinates(int x, int y) : x(x), y(y) {}

Coordinates::Coordinates() {}

void Coordinates::setX(int x) {
    Coordinates::x = x;
}

int Coordinates::getY() const {
    return y;
}

void Coordinates::setY(int y) {
    Coordinates::y = y;
}
