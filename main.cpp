#include <iostream>
#include <String>
#include "Character/Player.h"
#include "Dungon/Room.h"
#include "Tools/Weapon.h"
#include "DrawingRooms/Draw.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int randNum(int min, int max);
Player Welcome();
void createWeapons(vector<Weapon> weaponList);
void setPlayerWeapon(const vector<Weapon>& weaponList,Player monk);
vector < vector <Room> > generateDungeon();
void printDungeon(vector< vector<Room> > &dungeon);
void printRoomEmpty();
void printCurrentRoom(int x, int y);
void startGame(const vector<Room>&, Player monk);

int main() {
    srand((unsigned)time(NULL));//Sets seed for random generator
    //Player *monk = new Player(Welcome());
    cout << "---  Monk Created  ---" << endl;
    cout << "---  Generating Dungeon  ---" << endl;
    vector <vector <Room> >  dungeon  = generateDungeon();// Generated the dungeon's rooms
    printDungeon(dungeon);
    cout << "---  Dungeon Complete  ---" << endl;
    int x, y;
    x = 4;
    y = 0;
    printCurrentRoom(x,y);
    //startGame(dungeon, *monk);
    return 0;
}
int randNum(int min, int max){
    return rand() % (max - min + 1) + min;
}
Player Welcome(){
    string input;
    int diff;
    cout << "Welcome to Monk the dungeon survival game" << endl;
    cout << "---  Creating Monk  ---" << endl;
    cout << "Player Name: ";
    getline(cin, input);
    Player monk = Player(); /* Create the player */
    monk.setName(input); /* set player name */
    cout << "Please enter your difficulty 1 = easy, 2 = medium, 3 = hard ";
    getline(cin,input);
    stringstream myStream(input);
    if (myStream >> diff)
        monk.setDifficulty(diff);
    if (monk.getDifficulty() == 1){
        monk.setHealth(20);
    }else if (monk.getDifficulty() == 2){
        monk.setHealth(15);
    }else if (monk.getDifficulty() == 3){
        monk.setHealth(10);
    }
    cout << "Welcome to the Game " << monk.getName() << ", You have chose to play with a difficulty level of " << monk.getDifficulty() << endl;
    return monk;
}

void createWeapons(vector<Weapon> weaponList) {
    Weapon w1 = Weapon(0,"Blue Thunder", "Sword", 2);
    weaponList.push_back(w1);
    Weapon w2 = Weapon(1,"Walking stick","Stick", 4);
    weaponList.push_back(w2);
    Weapon w3 = Weapon(2,"Splitting Pain","Battle Axe", 3);
    weaponList.push_back(w3);
    Weapon w4 = Weapon(3,"Ramming rampage","Hammer", 2);
    weaponList.push_back(w3);
    Weapon w5 = Weapon(4,"Ninja Crazy","Nunchucks", 1);
    weaponList.push_back(w4);

};

void setPlayerWeapon(const vector<Weapon>& weaponList, Player monk) {
    int weaponChance = 100;
    if (monk.getDifficulty() == 2) {
        weaponChance = 75;
    } else if (monk.getDifficulty() == 3) {
        weaponChance = 50;
    }
    int loadWeapon = randNum(0, weaponChance);
    const int weaponID = loadWeapon / 10;
}


vector < vector <Room> > generateDungeon(){
    vector< vector<Room> > dungeon;// Created the dungeon vector
    for (int i = 0; i < 5; i++){
        vector<Room>temp;
        for (int j = 0; j < 5; j++){
            Room room = Room("name", randNum(1,2) ,i,j);
            temp.push_back(room);
        }
        dungeon.push_back(temp);
    }
    return dungeon;
}
void printDungeon(vector< vector<Room> > & dungeon){
    int roomCount = 0;
    cout << "---------  Dungeon  ---------" << endl;
    for(int i = 0; i < dungeon.size(); i++){
        roomCount =  roomCount + dungeon[i].size();
        for(int j = 0; j<dungeon[i].size(); j++){
            cout << "(" << dungeon[i][j].getX() << "," << dungeon[i][j].getY() << ") ";
        }
        cout << endl;
    }
    cout << "-----  Number of Rooms  -----" << endl;
    cout << "Room count: " << roomCount << endl;
    cout << "---------  Dungeon  ---------" << endl;
}
void startGame(const vector<Room>& dungeon, Player monk) {
    string name;
    int health;
    bool endGame;
    name = monk.getName();
    health = monk.getHealth();
    monk.setX(0);
    monk.setY(0);
    while (!endGame){
        //Check if monster Room
        printCurrentRoom(monk.getX(), monk.getY());
        cout << "Choose your direction" << endl;
    }
}
void printCurrentRoom(int x, int y){
    Draw Drawer = Draw();
    if(x == 0 & y == 0){
        Drawer.eTopRight();
    }else if (x == 0 & y == 4){
        Drawer.eTopLeft();
    }else if (x == 0){
        Drawer.eTopLeftRight();
    }else if (x == 1 & y == 0 || x == 2 & y == 0 || x == 3 & y == 0){
        Drawer.eRight();
    }else if(x == 4 & y == 0){
        Drawer.eBottomRight();
    }else if (x == 4 & y == 1 || x == 4 & y == 2 || x == 4 & y == 3){
        Drawer.eBottomBoth();
    }else if (x == 4 & y == 4){
        Drawer.eBottomLeft();
    }else if (x == 1 & y == 4 || x == 2 & y == 4 || x == 3 & y == 4){
        Drawer.eLeft();
    }else{
        Drawer.eCenterRoom();
    }
}