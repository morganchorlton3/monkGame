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

void Player::setMaxHealth(int maxHealth) {
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

bool Player::isAlive() const {
    return alive;
}

void Player::setAlive(bool alive) {
    Player::alive = alive;
}

const string &Player::getWeaponName() const {
    return WeaponName;
}

void Player::setWeaponName(const string &WeaponName) {
    Player::WeaponName = WeaponName;
}

void Player::print(){
    cout << "name: " << Name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Damage: " << attackDamage << endl;
}

const Weapon &Player::getWeapon() const {
    return weapon;
}

void Player::setWeapon(const Weapon &weapon) {
    Player::weapon = weapon;
}

const vector<string> &Player::getPlayerLog() const {
    return PlayerLog;
}

void Player::setPlayerLog(const vector<string> &PlayerLog) {
    Player::PlayerLog = PlayerLog;
}

int Player::getRoomCounter() const {
    return roomCounter;
}

void Player::setRoomCounter(int roomCounter) {
    Player::roomCounter = roomCounter;
}

int Player::getKillCounter() const {
    return killCounter;
}

void Player::setKillCounter(int killCounter) {
    Player::killCounter = killCounter;
}

int Player::getDungeonSize() const {
    return dungeonSize;
}

void Player::setDungeonSize(int dungeonSize) {
    Player::dungeonSize = dungeonSize;
}


