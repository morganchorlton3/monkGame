#include <iostream>
#include <String>
#include "Character/Player.h"
#include "Dungon/Room.h"
#include "Tools/Weapon.h"
#include "DrawingRooms/Draw.h"
#include "DrawingRooms/MonsterDraw.h"
#include "DrawingRooms/TreasureDraw.h"
#include "Character/Monster.h"
#include "Dungon/Coordinates.h"
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

void endGame();

void movePlayer(Player *monk);

void printCurrentRoomCo(const Player * monk);

void runGame(vector<vector<Room>> dungeon, Player * monk);

void playerCombat(Player * monk, Monster currentMonster);

int main() {
    srand((unsigned)time(NULL));//Sets seed for random generator
    Player *monk = new Player(Welcome());
    cout << "---  Monk Created  ---" << endl;
    cout << "---  Generating Dungeon  ---" << endl;
    vector <vector <Room> >  dungeon  = generateDungeon();// Generated the dungeon's rooms
    vector<Coordinates> coordsPath;
    printDungeon(dungeon);
    cout << "---  Dungeon Complete  ---" << endl;
    cout << "---  Starting Game  ---" << endl;
    Room currentRoom = dungeon[0][0];
    printCurrentMonsterRoom(currentRoom);
    runGame(dungeon, monk);
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
        monk.setMaxHealth(20);
    }else if (monk.getDifficulty() == 2){
        monk.setHealth(15);
        monk.setMaxHealth(15);
    }else if (monk.getDifficulty() == 3){
        monk.setHealth(10);
        monk.setMaxHealth(10);
    }
    monk.setAttackDamage(6);
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
            Room room = Room("name", randNum(1, 2), i, j, false);
            temp.push_back(room);
        }
        dungeon.push_back(temp);
    }
    vector<Room>temp;
    for (int k = 0; k < 5; k++){
        int decider = randNum(1, 2);
        if (decider == 1) {
            Room room = Room("name", 3, 6, k, false);
            temp.push_back(room);
        } else {
            Room room = Room("Treasure name", randNum(1, 2), 6, k, false);
            temp.push_back(room);
        }
    }
    dungeon.push_back(temp);

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
    }else if (x == 0 & y == 6){
        Drawer.eTopLeft();
    }else if (x == 0){
        Drawer.eTopLeftRight();
    }else if (x == 1 & y == 0 || x == 2 & y == 0 || x == 3 & y == 0 || x == 4 & y == 0 || x == 5 & y == 0){
        Drawer.eRight();
    }else if(x == 6 & y == 0){
        Drawer.eBottomRight();
    }else if (x == 6 & y == 1 || x == 6 & y == 2 || x == 6 & y == 3 || x == 6 & y == 4 || x == 6 & y == 5 ){
        Drawer.eBottomBoth();
    }else if (x == 6 & y == 5){
        Drawer.eBottomLeft();
    }else if (x == 1 & y == 6 || x == 2 & y == 6 || x == 3 & y == 6 || x == 4 & y == 6|| x == 5 & y == 6){
        Drawer.eLeft();
    }else{
        Drawer.eCenterRoom();
    }
    currentRoom.setVisited(true);
}

void printCurrentMonsterRoom(Room currentRoom){
    MonsterDraw MDrawer = MonsterDraw();
    int x,y;
    x = currentRoom.getX();
    y = currentRoom.getY();
    if(x == 0 & y == 0){
        MDrawer.eTopRight();
    }else if (x == 0 & y == 6){
        MDrawer.eTopLeft();
    }else if (x == 0){
        MDrawer.eTopLeftRight();
    }else if (x == 1 & y == 0 || x == 2 & y == 0 || x == 3 & y == 0 || x == 4 & y == 0 || x == 5 & y == 0){
        MDrawer.eRight();
    }else if(x == 6 & y == 0){
        MDrawer.eBottomRight();
    }else if (x == 6 & y == 1 || x == 6 & y == 2 || x == 6 & y == 3 || x == 6 & y == 4 || x == 6 & y == 5 || x == 6 & y == 6 ){
        MDrawer.eBottomBoth();
    }else if (x == 6 & y == 4){
        MDrawer.eBottomLeft();
    }else if (x == 1 & y == 6 || x == 2 & y == 6 || x == 3 & y == 6 || x == 4 & y == 6|| x == 5 & y == 6 || x == 5 & y == 7){
        MDrawer.eLeft();
    }else{
        MDrawer.eCenterRoom();
    }
    currentRoom.setVisited(true);
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

void printCurrentRoomCo(Player * monk) {
    cout << " Coordinates: ( X " << monk->getX() << ", Y " << monk->getY() << " )" << endl;
}
void runGame(vector<vector<Room>> dungeon, Player * monk){
    Monster currentMonster = Monster();
    currentMonster.setHealth(10);
    currentMonster.setAttackDamage(randNum(1,4));
    while (monk->isAlive()) {
        movePlayer(monk);
        Room currentRoom = dungeon[monk->getX()][monk->getY()];
        if (currentRoom.isVisited()){
            cout << "You have already visited that room" << endl;
            movePlayer(monk);
            currentRoom = dungeon[monk->getX()][monk->getY()];
        }
        if (currentRoom.getType() == 1) {
            printCurrentRoomCo(monk);
            printCurrentRoom(currentRoom);
        } else if (currentRoom.getType() == 2) {
            printCurrentRoomCo(monk);
            printCurrentMonsterRoom(currentRoom);
            playerCombat(monk, currentMonster);
        }else if (currentRoom.getType() == 3) {
            printCurrentRoomCo(monk);
            printCurrentTreasureRoom(currentRoom);
            cout << "Congratulations You won the game!" << endl;
            endGame();
        }
    }
    cout << "You have died!" << endl;
    endGame();
}

void playerCombat(Player * monk, Monster currentMonster) {
    while (currentMonster.isAlive()) {
        cout << "There is a monster in the room" << endl;
        cout << "Your Health: " << monk->getHealth() << " HP." << endl;
        cout << "Monster's health: " << currentMonster.getHealth() << " HP." << endl;
        cout << "would you like to attack a or defend d :" << endl;
        string move;
        cin >> move;
        if (move == "a") {
            int WorL = randNum(0, 1);
            if (WorL == 0) {
                //int attack = randNum(1, monk.getAttackDamage());
                int attack = monk->getAttackDamage();
                cout << "You attacked the monster, you dealt " << attack << " points of damage to it." << endl;
                int monsterHp = currentMonster.getHealth() - attack;
                currentMonster.setHealth(monsterHp);
                if (currentMonster.getHealth() - attack <= 0) {
                    cout << "You Killed the Monster, You may progress" << endl;
                    currentMonster.setAlive(false);
                    break;
                }
                break;
            } else if (WorL == 1) {
                int attack = randNum(1, currentMonster.getAttackDamage());
                if (monk->getHealth() - attack <= 0) {
                    cout << "You Died" << endl;
                    endGame();
                }
                cout << "the monster attacked you and dealt " << attack << " points of damage." << endl;
                monk->setHealth(monk->getHealth() - attack);
                break;
            }
        }
    }
}

void movePlayer(Player * monk) {
    cout << "Choose what direction you want to move in : " << endl;
    string move;
    cin >> move;
    if (move == "w" || move == "W") {
        int x = monk->getX();
        switch (x) {
            case 0:
                cout << "You can't move up" << endl;
                break;
            default:
                monk->setX(x - 1);
                break;
        }
    } else if (move == "s" || move == "S") {
        int x = monk->getX();
        switch (x) {
            case 6:
                cout << "You can't move left" << endl;
                break;
            default:
                monk->setX(x + 1);
                break;
        }
    } else if (move == "a" || move == "A") {
        int y = monk->getY();
        switch (y) {
            case 0:
                cout << "You can't move left" << endl;
                break;
            default:
                monk->setX(y - 1);
                break;
        }
    } else if (move == "d" || move == "D") {
        int y = monk->getY();
        switch (y) {
            case 6:
                cout << "You can't move right" << endl;
                break;
            default:
                monk->setY(y + 1);
                break;
        }
    }
}

void endGame() {
    exit(1);
}