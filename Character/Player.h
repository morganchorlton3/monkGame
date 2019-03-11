//
// Created by morgan on 08/03/2019.
//

#ifndef MONK_PLAYER_H
#define MONK_PLAYER_H
#include <string>

class Player {
    std::string Name;
    int difficulty, health;

public:
    Player();

    Player(const std::string &Name, int difficulty, int health);

public:
    const std::string &getName() const;

    void setName(const std::string &Name);

    int getDifficulty() const;

    void setDifficulty(int difficulty);

    int getHealth() const;

    void setHealth(int health);
};


#endif //MONK_PLAYER_H
