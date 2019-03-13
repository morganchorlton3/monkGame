#include <iostream>
#include <String>
#include "Character/Player.h"
#include "Dungon/Room.h"
#include "Tools/Weapon.h"
#include "DrawingRooms/Draw.h"
#include "DrawingRooms/MonsterDraw.h"
#include "DrawingRooms/TreasureDraw.h"
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
void printCurrentRoom(Room currentRoom);
void printCurrentMonsterRoom(Room currentRoom);
void printCurrentTreasureRoom(Room currentRoom);
void startGame(const vector< vector <Room> > &, Player monk);

int main() {
    srand((unsigned)time(NULL));//Sets seed for random generator
    Player *monk = new Player(Welcome());
    cout << "---  Monk Created  ---" << endl;
    cout << "---  Generating Dungeon  ---" << endl;
    vector <vector <Room> >  dungeon  = generateDungeon();// Generated the dungeon's rooms
    printDungeon(dungeon);
    cout << "---  Dungeon Complete  ---" << endl;
    cout << "---  Starting Game  ---" << endl;
    startGame(dungeon, *monk);
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
    monk.setX(0);
    monk.setY(0);
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
            int rand = randNum(1,2);
            if(rand == 1) {
                Room room = Room("name", randNum(1, 2), i, j);
                temp.push_back(room);
            }else if(rand == 2){
                Room room2 = Room("No Room", 3 ,i,j);
                temp.push_back(room2);
            }
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
void printCurrentRoom(Room currentRoom){
    Draw Drawer = Draw();
    int x,y;
    x = currentRoom.getX();
    y = currentRoom.getY();
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

void printCurrentMonsterRoom(Room currentRoom){
    MonsterDraw MDrawer = MonsterDraw();
    int x,y;
    x = currentRoom.getX();
    y = currentRoom.getY();
    if(x == 0 & y == 0){
        MDrawer.eTopRight();
    }else if (x == 0 & y == 4){
        MDrawer.eTopLeft();
    }else if (x == 0){
        MDrawer.eTopLeftRight();
    }else if (x == 1 & y == 0 || x == 2 & y == 0 || x == 3 & y == 0){
        MDrawer.eRight();
    }else if(x == 4 & y == 0){
        MDrawer.eBottomRight();
    }else if (x == 4 & y == 1 || x == 4 & y == 2 || x == 4 & y == 3){
        MDrawer.eBottomBoth();
    }else if (x == 4 & y == 4){
        MDrawer.eBottomLeft();
    }else if (x == 1 & y == 4 || x == 2 & y == 4 || x == 3 & y == 4){
        MDrawer.eLeft();
    }else{
        MDrawer.eCenterRoom();
    }
}

void printCurrentTreasureRoom(Room currentRoom){
    TreasureDraw TDrawer = TreasureDraw();
    int x,y;
    x = currentRoom.getX();
    y = currentRoom.getY();
    if(x == 0 & y == 0){
        TDrawer.eTopRight();
    }else if (x == 0 & y == 4){
        TDrawer.eTopLeft();
    }else if (x == 0){
        TDrawer.eTopLeftRight();
    }else if (x == 1 & y == 0 || x == 2 & y == 0 || x == 3 & y == 0){
        TDrawer.eRight();
    }else if(x == 4 & y == 0){
        TDrawer.eBottomRight();
    }else if (x == 4 & y == 1 || x == 4 & y == 2 || x == 4 & y == 3){
        TDrawer.eBottomBoth();
    }else if (x == 4 & y == 4){
        TDrawer.eBottomLeft();
    }else if (x == 1 & y == 4 || x == 2 & y == 4 || x == 3 & y == 4){
        TDrawer.eLeft();
    }else{
        TDrawer.eCenterRoom();
    }
}

void startGame(const vector< vector <Room> > & dungeon, Player monk) {
    string name;
    int health;
    bool runGame = true;
    name = monk.getName();
    health = monk.getHealth();
    while (runGame) {
        int x = monk.getX();
        int y = monk.getY();
        cout << monk.getX() << ", " << monk.getY() << endl;
        Room currentRoom = dungeon[x][y]; // sets start room to X=0 , Y=0
        switch (currentRoom.getType()) {
            case 1:
                printCurrentRoom(currentRoom);
                break;
            case 2:
                printCurrentMonsterRoom(currentRoom);
                break;
            case 3:
                printCurrentTreasureRoom(currentRoom);
                cout << endl << "---  Congratulations You Won!  ---" << endl;
                break;
            default:
                cout << "Error Printing room Invalid room type" << endl;
                break;
        }
        cout << "Your Move: " << endl;
        string move;
        bool moveBool = true;
        cin >> move;
        while(moveBool){
           if(move == "w" || move == "W" ){
               int x = monk.getX();
               switch (x){
                   case 0:
                       cout << "You can't move up" << endl;
                       break;
                   default:
                       monk.setX(x-1);
                       moveBool = false;
                       break;
               }
            }else if(move == "s" || move == "S" ){
               int x = monk.getX();
               switch (x){
                   case 5:
                       cout << "You can't move down" << endl;
                       break;
                   default:
                       monk.setX(x+1);
                       moveBool = false;
                       break;
               }
           }else if(move == "a" || move == "A" ){
               int y = monk.getY();
               switch (y){
                   case 0:
                       cout << "You can't move left" << endl;
                       break;
                   default:
                       monk.setX(y-1);
                       moveBool = false;
                       break;
               }
           }else if(move == "d" || move == "D" ){
               int y = monk.getY();
               switch (y){
                   case 5:
                       cout << "You can't move right" << endl;
                       break;
                   default:
                       monk.setY(y+1);
                       moveBool = false;
                       break;
               }
           }
        }
    }
}