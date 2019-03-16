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

int Player::getMaxHealth() const {
    return maxHealth;
}

void Player::setMaxHealth(int macHealth) {
    Player::maxHealth = maxHealth;
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

int Player::getAttackDamage() const {
    return attackDamage;
}

void Player::setAttackDamage(int attackDamage) {
    Player::attackDamage = attackDamage;
}

void Player::movePlayer(Player monk) {
    cout << "Your Move: " << endl;
    string move;
    cin >> move;
    if (move == "w" || move == "W") {
        int x = monk.getX();
        switch (x) {
            case 0:
                cout << "You can't move up" << endl;
                break;
            default:
                monk.setX(x - 1);
                break;
        }
    } else if (move == "s" || move == "S") {
        int x = monk.getX();
        switch (x) {
            case 5:
                cout << "You can't move down" << endl;
                break;
            default:
                monk.setX(x + 1);
                break;
        }
    } else if (move == "a" || move == "A") {
        int y = monk.getY();
        switch (y) {
            case 0:
                cout << "You can't move left" << endl;
                break;
            default:
                monk.setX(y - 1);
                break;
        }
    } else if (move == "d" || move == "D") {
        int y = monk.getY();
        switch (y) {
            case 5:
                cout << "You can't move right" << endl;
                break;
            default:
                monk.setY(y + 1);
                break;
        }
    }
}

bool Player::isAlive() const {
    return alive;
}

void Player::setAlive(bool alive) {
    Player::alive = alive;
}


