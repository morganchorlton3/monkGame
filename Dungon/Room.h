//
// Created by morgan on 10/03/2019.
//

#ifndef MONK_ROOM_H
#define MONK_ROOM_H
#include <string>

class Room {
public:
    Room( int type, bool monster);

    int getType() const;

    void setType(int type);

    bool isMonster() const;

    void setMonster(bool monster);

    void printRoom();

public:


private:
    int name,type;
    bool monster;
};


#endif //MONK_ROOM_H
