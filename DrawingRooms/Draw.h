//
// Created by morga on 12/03/2019.
//

#ifndef MONK_DRAW_H
#define MONK_DRAW_H


class Draw {
public:
    Draw();
    void topWallSolid();
    void topWallEnterance();
    void sideWall(int rowNo);
    void sideWallwithPlayer();
    void sideWallwithMonster();
    void sideWallwithTreasure();
    void sideWallEnteranceLeft();
    void sideWallEnteranceRight();
    void sideWallEnteranceBoth();
    void eTopLeft();
    void eTopRight();
    void eTopLeftRight();
    void eLeft();
    void eRight();
    void eCenterRoom();
    void eBottomRight();
    void eBottomLeft();
    void eBottomBoth();

};


#endif //MONK_DRAW_H
