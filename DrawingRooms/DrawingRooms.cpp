//
// Created by Morgan on 12/03/2019.
//
#include <iostream>

using namespace std;

void topWallSolid();
void topWallEnterance();
void sideWall(int rowNo);
void sideWallwithPlayer();
void sideWallEnteranceleft();
void sideWallEnteranceRight();
void sideWallEnteranceBoth();


void topWallSolid(){
    for (int column = 0; column < 52; ++column)
    {
        cout << "*";
    }
}

void topWallEnterance(){
    topWallSolid();
    for (int column = 0; column < 4; ++column)
    {
        cout << " ";
    }
    topWallSolid();
}

void sideWall(int rowNo){
    for (int row = 0; row < rowNo; ++row){
        cout << "*";
        for (int column = 0; column < 50; ++column)
            cout << " ";
        cout << "*" << endl;
    }
}

void sideWallEnteranceLeft(){
    sideWall(4);
    for (int row = 0; row < 2; ++row){
        cout << " ";
        for (int column = 0; column < 50; ++column)
            cout << " ";
        cout << "*" << endl;
    }
    sideWall(4);
}

void sideWallEnteranceRight(){
    sideWall(4);
    for (int row = 0; row < 2; ++row){
        cout << "*";
        for (int column = 0; column < 50; ++column)
            cout << " ";
        cout << " " << endl;
    }
    sideWall(4);
}

void sideWallEnteranceBoth(){
    for (int row = 0; row < 2; ++row){
        for (int column = 0; column < 52; ++column)
            cout << " ";
    }
}

void sideWallwithPlayer(){
    cout << "*";
    for (int column = 0; column < 24; ++column)
        cout << " ";
    cout << "*" << endl;
    for (int column = 0; column < 24; ++column)
        cout << "M";
    cout << "*";
}

void eRight(){
    topWallSolid();
    sideWall(8);
    topWallEnterance();
}
