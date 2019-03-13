//
// Created by morgan on 08/03/2019.
//

#include <iostream>
#include "Player.h"

const std::string &Player::getName() const {
    return Name;
}

void Player::setName(const std::string &Name) {
    Player::Name = Name;
}

int Player::getDifficulty() const {
    return difficulty;
}

void Player::setDifficulty(int difficulty) {
    Player::difficulty = difficulty;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int health) {
    Player::health = health;
}

int Player::getX() const {
    return x;
}

void Player::setX(int x) {
    Player::x = x;
}

int Player::getY() const {
    return y;
}

void Player::setY(int y) {
    Player::y = y;
}

Player::Player() {}

