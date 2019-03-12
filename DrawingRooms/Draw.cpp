//
// Created by morga on 12/03/2019.
//

#include "Draw.h"
#include <iostream>

using namespace std;

void Draw::topWallSolid(){
    for (int column = 0; column < 52; ++column)
    {
        cout << "*";
    }
    cout << endl;
}

void Draw::topWallEnterance(){
    for (int column = 0; column < 24; ++column)
    {
        cout << "*";
    }
    for (int column = 0; column < 4; ++column)
    {
        cout << " ";
    }
    for (int column = 0; column < 24; ++column)
    {
        cout << "*";
    }
    cout << endl;
}

void Draw::sideWall(int rowNo){
    for (int row = 0; row < rowNo; ++row){
        cout << "*";
        for (int column = 0; column < 50; ++column)
            cout << " ";
        cout << "*" << endl;
    }
}

void Draw::sideWallEnteranceLeft(){
    for (int row = 0; row < 2; ++row){
        cout << " ";
        for (int column = 0; column < 50; ++column)
            cout << " ";
        cout << "*" << endl;
    }
}

void Draw::sideWallEnteranceRight(){
    for (int row = 0; row < 2; ++row){
        cout << "*";
        for (int column = 0; column < 50; ++column)
            cout << " ";
        cout << " " << endl;
    }
}

void Draw::sideWallEnteranceBoth(){
    for (int row = 0; row < 2; ++row){
        for (int column = 0; column < 52; ++column)
            cout << " ";
    }
    cout << endl;
}

void Draw::sideWallwithPlayer(){
    cout << "*";
    for (int column = 0; column < 25; ++column)
        cout << " ";
    cout << "M";
    for (int column = 0; column < 24; ++column)
        cout << " ";
    cout << "*" << endl;
}

void Draw::eTopLeft() {
    topWallEnterance();
    sideWall(4);
    sideWallEnteranceLeft();
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
    topWallSolid();
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

void Draw::eLeftRight() {
    topWallSolid();
    sideWall(4);
    sideWallEnteranceBoth();
    sideWall(2);
    sideWallwithPlayer();
    sideWall(1);
    topWallEnterance();
}

Draw::Draw() {}

