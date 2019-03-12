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
    void sideWallEnteranceLeft();
    void sideWallEnteranceRight();
    void sideWallEnteranceBoth();
    void eTopLeft();
    void eTopLeftRight();
    void eLeft();
    void eRight();
    void eLeftRight();

};


#endif //MONK_DRAW_H
