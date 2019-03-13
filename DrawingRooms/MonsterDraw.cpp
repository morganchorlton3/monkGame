//
// Created by Morgan on 13/03/2019.
//

#include "MonsterDraw.h"
#include "Draw.h"

Draw draw = Draw();

void MonsterDraw::eTopLeft() {
    draw.topWallSolid();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceLeft();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallEnterance();
}

void MonsterDraw::eTopRight(){
    draw.topWallSolid();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceRight();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallEnterance();
}

void MonsterDraw::eTopLeftRight() {
    draw.topWallSolid();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceBoth();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallEnterance();
}

void MonsterDraw::eLeft() {
    draw.topWallEnterance();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceLeft();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallEnterance();
}

void MonsterDraw::eRight(){
    draw.topWallSolid();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceRight();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallEnterance();
}

void MonsterDraw::eCenterRoom() {
    draw.topWallEnterance();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceBoth();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallEnterance();
}
void MonsterDraw::eBottomRight(){
    draw.topWallEnterance();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceRight();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallSolid();
}

void MonsterDraw::eBottomLeft(){
    draw.topWallEnterance();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceLeft();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallSolid();
}

void MonsterDraw::eBottomBoth(){
    draw.topWallEnterance();
    draw.sideWall(1);
    draw.sideWallwithMonster();
    draw.sideWall(2);
    draw.sideWallEnteranceBoth();
    draw.sideWall(2);
    draw.sideWallwithPlayer();
    draw.sideWall(1);
    draw.topWallSolid();
}

MonsterDraw::MonsterDraw() {}
