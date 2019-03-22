//
// Created by Morgan on 12/03/2019.
//

#include "draw.h"
#include "../Dungon/Room.h"
#include "../Character/Player.h"
#include <iostream>
#include <string>

using namespace std;

void Draw::topWallSolid(){
    for (int column = 0; column < 30; ++column)
    {
        cout << "*";
    }
    cout << endl;
}

void Draw::topWallEntrance(){
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

void Draw::sideWallEntranceLeft(){
    for (int row = 0; row < 2; ++row){
        cout << " ";
        for (int column = 0; column < 28; ++column)
            cout << " ";
        cout << "*" << endl;
    }
}

void Draw::sideWallEntranceRight(){
    for (int row = 0; row < 2; ++row){
        cout << "*";
        for (int column = 0; column < 28; ++column)
            cout << " ";
        cout << " " << endl;
    }
}

void Draw::sideWallEntranceBoth(){
    for (int row = 0; row < 2; ++row){
        for (int column = 0; column < 22; ++column)
            cout << " ";
    }
    cout << endl;
}

void Draw::sideWallWithPlayer(){
    cout << "*";
    for (int column = 0; column < 14; ++column)
        cout << " ";
    cout << "P";
    for (int column = 0; column < 13; ++column)
        cout << " ";
    cout << "*" << endl;
}

void Draw::sideWallWithObject(string letter){
    cout << "*";
    for (int column = 0; column < 14; ++column)
        cout << " ";
    cout << letter;
    for (int column = 0; column < 13; ++column)
        cout << " ";
    cout << "*" << endl;
}

void Draw::eTopLeft(string letter) {
    topWallEntrance();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceLeft();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallSolid();
}

void Draw::eTopRight(string letter){
    topWallEntrance();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceRight();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallSolid();
}

void Draw::eTopLeftRight(string letter) {
    topWallEntrance();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceBoth();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallSolid();
}

void Draw::eTopRightBottom(string letter){
    topWallEntrance();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceRight();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallEntrance();
}

void Draw::eCenterRoom(string letter) {
    topWallEntrance();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceBoth();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallEntrance();
}

void Draw::eBottomRight(string letter){
    topWallSolid();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceRight();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallEntrance();
}

void Draw::eBottomLeft(string letter){
    topWallSolid();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceLeft();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallEntrance();
}

void Draw::eBottomBoth(string letter){
    topWallSolid();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceBoth();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallEntrance();
}
void Draw::eTopLeftBottom(string letter){
    topWallEntrance();
    sideWall(1);
    sideWallWithObject(letter);
    sideWall(2);
    sideWallEntranceLeft();
    sideWall(2);
    sideWallWithPlayer();
    sideWall(1);
    topWallEntrance();
}

void Draw::printRoom(Room currentRoom, Player * monk, string letter){
    int x,y;
    x = monk->getX();
    y = monk->getY();
    if (x == 0 & y == 0){
        eBottomRight(letter);
    }else if (x == 0 & y == 1 || x == 0 & y == 2 || x == 0 & y == 3 || x == 0 & y == 4) {
        eTopRightBottom(letter);
    }else if(x == 0 & y == 5){
        eTopRight(letter);
    }else if(x == 1 & y == 5 || x == 2 & y == 5 || x == 3 & y == 5 || x == 4 & y == 5 || x == 4 & y == 5){
        eTopLeftRight(letter);
    }else if(x == 5 & y == 1 || x == 5 & y == 2 || x == 5 & y == 3 || x == 5 & y == 4){
        eTopLeftBottom(letter);
    }else if(x == 5 & y == 5) {
        eTopLeft(letter);
    }else if(x == 5 & y == 0) {
        eBottomLeft(letter);
    }else if(x == 1 & y == 0 || x == 2 & y == 0 || x == 3 & y == 0 || x == 4 & y == 0){
        eBottomBoth(letter);
    }else{
        eCenterRoom(letter);
    }
}
void Draw::printRoomWithObject(Room currentRoom, Player * monk, string letter){
    int x,y;
    x = monk->getX();
    y = monk->getY();
    if (x == 0 & y == 0){
        eBottomRight(letter);
    }else if (x == 0 & y == 1 || x == 0 & y == 2 || x == 0 & y == 3 || x == 0 & y == 4) {
        eTopRightBottom(letter);
    }else if(x == 0 & y == 5){
        eTopRight(letter);
    }else if(x == 1 & y == 5 || x == 2 & y == 5 || x == 3 & y == 5 || x == 4 & y == 5 || x == 4 & y == 5){
        eTopLeftRight(letter);
    }else if(x == 5 & y == 1 || x == 5 & y == 2 || x == 5 & y == 3 || x == 5 & y == 4){
        eTopLeftBottom(letter);
    }else if(x == 5 & y == 5) {
        eTopLeft(letter);
    }else if(x == 5 & y == 0) {
        eBottomLeft(letter);
    }else if(x == 1 & y == 0 || x == 2 & y == 0 || x == 3 & y == 0 || x == 4 & y == 0){
        eBottomBoth(letter);
    }else{
        eCenterRoom(letter);
    }
}

Draw::Draw() {}

