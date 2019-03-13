//
// Created by morga on 13/03/2019.
//

#include "TreasureDraw.h"
#include "draw.h"

Draw drawer = Draw();

void TreasureDraw::eTopLeft() {
    drawer.topWallSolid();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceLeft();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallEnterance();
}

void TreasureDraw::eTopRight(){
    drawer.topWallSolid();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceRight();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallEnterance();
}

void TreasureDraw::eTopLeftRight() {
    drawer.topWallSolid();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceBoth();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallEnterance();
}

void TreasureDraw::eLeft() {
    drawer.topWallEnterance();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceLeft();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallEnterance();
}

void TreasureDraw::eRight(){
    drawer.topWallSolid();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceRight();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallEnterance();
}

void TreasureDraw::eCenterRoom() {
    drawer.topWallEnterance();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceBoth();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallEnterance();
}
void TreasureDraw::eBottomRight(){
    drawer.topWallEnterance();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceRight();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallSolid();
}

void TreasureDraw::eBottomLeft(){
    drawer.topWallEnterance();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceLeft();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallSolid();
}

void TreasureDraw::eBottomBoth(){
    drawer.topWallEnterance();
    drawer.sideWall(1);
    drawer.sideWallwithTreasure();
    drawer.sideWall(2);
    drawer.sideWallEnteranceBoth();
    drawer.sideWall(2);
    drawer.sideWallwithPlayer();
    drawer.sideWall(1);
    drawer.topWallSolid();
}

TreasureDraw::TreasureDraw(){}
