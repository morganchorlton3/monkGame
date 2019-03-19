//
// Created by morgan on 08/03/2019.
//

#ifndef MONK_PLAYER_H
#define MONK_PLAYER_H
#include <string>
#include <vector>
#include "../Tools/Weapon.h"

class Player {
    std::string Name, WeaponName;
    int difficulty, health, maxHealth, attackDamage, dungeonSize,  x, y, roomCounter, killCounter;
    bool alive;
    Weapon weapon;
    vector <string> PlayerLog;
public:
    bool isAlive() const;

    void setAlive(bool alive);

    Player();

    const std::string &getName() const;

    void setName(const std::string &Name);

    int getDifficulty() const;

    void setDifficulty(int difficulty);

    int getHealth() const;

    int getAttackDamage() const;

    void setAttackDamage(int attackDamage);

    void setHealth(int health);

    int getMaxHealth() const;

    void setMaxHealth(int macHealth);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    const string &getWeaponName() const;

    void setWeaponName(const string &WeaponName);

    void print();

    const Weapon &getWeapon() const;

    void setWeapon(const Weapon &weapon);

    const vector<string> &getPlayerLog() const;

    void setPlayerLog(const vector<string> &PlayerLog);

    int getRoomCounter() const;

    void setRoomCounter(int roomCounter);

    int getKillCounter() const;

    void setKillCounter(int killCounter);

    int getDungeonSize() const;

    void setDungeonSize(int dungeonSize);


};


#endif //MONK_PLAYER_H
