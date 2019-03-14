//
// Created by morgan on 08/03/2019.
//

#ifndef MONK_PLAYER_H
#define MONK_PLAYER_H
#include <string>
#include "../Tools/Weapon.h"

class Player {
    std::string Name;
    int difficulty, health, maxHealth, attackDamage, x, y;


public:
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

    void movePlayer(Player monk);

};


#endif //MONK_PLAYER_H
