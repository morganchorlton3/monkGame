//
// Created by morga on 12/03/2019.
//

#include "Draw.h"
#include <iostream>

using namespace std;

void Draw::topWallSolid(){
    for (int column = 0; column < 30; ++column)
    {
        cout << "*";
    }
    cout << endl;
}

void Draw::topWallEnterance(){
    for (int column = 0; column < 12; ++column)
    {
        cout << "*";
    }
    for (int column = 0; column < 6; ++column)
    {
        cout << " ";
    }
    for (int column = 0; column < 12; ++column)
    {
        cout << "*";
    }
    cout << endl;
}

void Draw::sideWall(int rowNo){
    for (int row = 0; row < rowNo; ++row){
        cout << "*";
        for (int column = 0; column < 28; ++column)
            cout << " ";
        cout << "*" << endl;
    }
}

void Draw::sideWallEnteranceLeft(){
    for (int row = 0; row < 2; ++row){
        cout << " ";
        for (int column = 0; column < 28; ++column)
            cout << " ";
        cout << "*" << endl;
    }
}

void Draw::sideWallEnteranceRight(){
    for (int row = 0; row < 2; ++row){
        cout << "*";
        for (int column = 0; column < 28; ++column)
            cout << " ";
        cout << " " << endl;
    }
}

void Draw::sideWallEnteranceBoth(){
    for (int row = 0; row < 2; ++row){
        for (int column = 0; column < 22; ++column)
            cout << " ";
    }
    cout << endl;
}

void Draw::sideWallwithPlayer(){
    cout << "*";
    for (int column = 0; column < 13; ++column)
        cout << " ";
    cout << "P";
    for (int column = 0; column < 14; ++column)
        cout << " ";
    cout << "*" << endl;
}

void Draw::sideWallwithMonster(){
    cout << "*";
    for (int column = 0; column < 13; ++column)
        cout << " ";
    cout << "M";
    for (int column = 0; column < 14; ++column)
        cout << " ";
    cout << "*" << endl;
}
void Draw::sideWallwithTreasure(){
    cout << "*";
    for (int column = 0; column < 13; ++column)
        cout << " ";
    cout << "T";
    for (int column = 0; column < 14; ++column)
        cout << " ";
    cout << "*" << endl;
}

void Draw::eTopLeft() {
    topWallSolid();
    sideWall(4);
    sideWallEnteranceLeft();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallEnterance();
}

void Draw::eTopRight(){
    topWallSolid();
    sideWall(4);
    sideWallEnteranceRight();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallEnterance();
}

void Draw::eTopLeftRight() {
    topWallSolid();
    sideWall(4);
    sideWallEnteranceBoth();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallEnterance();
}

void Draw::eLeft() {
    topWallEnterance();
    sideWall(4);
    sideWallEnteranceLeft();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallEnterance();
}

void Draw::eRight(){
    topWallSolid();
    sideWall(4);
    sideWallEnteranceRight();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallEnterance();
}

void Draw::eCenterRoom() {
    topWallEnterance();
    sideWall(4);
    sideWallEnteranceBoth();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallEnterance();
}
void Draw::eBottomRight(){
    topWallEnterance();
    sideWall(4);
    sideWallEnteranceRight();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallSolid();
}

void Draw::eBottomLeft(){
    topWallEnterance();
    sideWall(4);
    sideWallEnteranceLeft();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallSolid();
}

void Draw::eBottomBoth(){
    topWallEnterance();
    sideWall(4);
    sideWallEnteranceBoth();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallSolid();
}

Draw::Draw() {}

