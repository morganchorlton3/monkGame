//
// Created by morga on 12/03/2019.
//

#ifndef MONK_DRAW_H
#define MONK_DRAW_H


#include "../Character/Player.h"
#include "../Dungon/Room.h"
#include <iostream>
#include <string>

using namespace std;

class Draw {
public:
    Draw();
    void topWallSolid();
    void topWallEntrance();
    void sideWall(int rowNo);
    void sideWallWithPlayer();
    void sideWallWithObject(string letter);
    void sideWallEntranceLeft();
    void sideWallEntranceRight();
    void sideWallEntranceBoth();
    void eTopLeft(string letter);
    void eTopRight(string letter);
    void eTopRightBottom(string letter);
    void eTopLeftBottom(string letter);
    void eTopLeftRight(string letter);
    void eCenterRoom(string letter);
    void eBottomRight(string letter);
    void eBottomLeft(string letter);
    void eBottomBoth(string letter);
    void printRoom(Room currentRoom, Player * monk, string letter);
    void printRoomWithObject(Room currentRoom, Player * monk, string letter);

};


#endif //MONK_DRAW_H
