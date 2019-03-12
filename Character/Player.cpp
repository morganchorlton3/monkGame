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
void Player::print_()
{
    cout << "---  Player  ---" << endl;
    cout << "Health: " << health << endl;
}

Player::Player() {}
