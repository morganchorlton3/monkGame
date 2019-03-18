#include <iostream>
#include <String>
#include "Character/Player.h"
#include "Dungon/Room.h"
#include "Tools/Weapon.h"
#include "DrawingRooms/Draw.h"
#include "Character/Monster.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

int randNum(int min, int max);

void pauseConsole(int length);

Player Welcome(vector < Weapon > weaponList);

vector < Weapon > createWeapons();

void setPlayerWeapon(vector<Weapon> weaponList,Player monk);

vector < vector <Room> > generateDungeon();

void printDungeon(vector< vector<Room> > &dungeon);

void printCurrentRoomCo(Player * monk);

void movePlayer(Player *monk);

void playerCombat(Player * monk, Monster currentMonster);

void runGame(vector<vector<Room>> dungeon, Player * monk);

void endGame();

int main() {
    srand((unsigned)time(NULL));//Sets seed for random generator
    vector < Weapon > weaponList = createWeapons();
    Player *monk = new Player(Welcome(weaponList));
    cout << endl << "---  Generating Dungeon  ---" << endl << endl;
    cout << "   Generating";
    pauseConsole(1);
    vector <vector <Room> >  dungeon  = generateDungeon();// Generated the dungeon's rooms
    //printDungeon(dungeon);
    cout << endl << "---  Dungeon Complete  ---" << endl << endl;;
    cout << "   Welcome to the Game " << monk->getName() << ", You have chose to play with a difficulty level of " << monk->getDifficulty() << endl;
    cout << endl << "---  Starting Game  ---" << endl << endl;;
    Room currentRoom = dungeon[0][0];
    string yorn;
    cout << "   Are you ready to start? Y or N" << endl;
    getline(cin, yorn);
    while (true){
        if (yorn == "y" || yorn == "Y"){
            cout << "Game Starting in " << endl;
            chrono::seconds duration(1);
            this_thread::sleep_for( duration );
            cout << "3" << endl;
            this_thread::sleep_for( duration );
            cout << "2" << endl;
            this_thread::sleep_for( duration );
            cout << "1" << endl;
            system("cls");
            runGame(dungeon, monk);
            break;
        }else if(yorn == "n" || yorn == "N") {
            cout << "   Thank you for playing Monk!" << endl;
            break;
        }else{
            cout << "   Please either enter Y or N" << endl;
            getline(cin, yorn);
        }
    }
    return 0;
}
// generates a random number withing a given range
int randNum(int min, int max){
    return rand() % (max - min + 1) + min;
}

// Pauses the console for a given length of seconds
void pauseConsole(int length){
    chrono::seconds duration(length);
    this_thread::sleep_for( duration );
    cout << ".";
    this_thread::sleep_for( duration );
    cout << ".";
    this_thread::sleep_for( duration );
    cout << "." << endl;
}

Player Welcome(vector < Weapon > weaponList){
    string input;
    int diff;
    cout << "   Welcome to Monk the dungeon survival game" << endl;
    cout << "---  Player Creation  ---" << endl;
    cout << "   Player Name: ";
    getline(cin, input);
    Player monk = Player(); /* Create the player */
    monk.setName(input); /* set player name */
    cout << "   Please enter your difficulty 1 = easy, 2 = medium, 3 = hard ";
    getline(cin,input);
    while (true){
        stringstream myStream(input);
        myStream >> diff;
            if(diff == 1 || diff == 2 || diff == 3) {
                monk.setDifficulty(diff);
                break;
            }else {
            cout << "   Please enter a correct level value ( 1, 2 ,3 )" << endl;
            getline(cin,input);
        }
    }
    cout << "   Creating your player" << endl;
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
    monk.setX(0);
    monk.setY(0);
    setPlayerWeapon(weaponList, monk);
    monk.print();
    return monk;
}

vector < Weapon > createWeapons() {
    vector <Weapon> weaponList;
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
    return weaponList;
};

void setPlayerWeapon( vector<Weapon>weaponList, Player  monk) {
    cout << "   Randomly Choosing your weapon";
    pauseConsole(1);
    int choice = randNum(0,4);
    Weapon currentWeapon = weaponList[choice];
    int weaponAttack = currentWeapon.getAttackDamage();
    monk.setWeaponName(currentWeapon.getName());
    monk.setAttackDamage(weaponAttack);
    cout << "   Your weapon has been selected: " << endl;
    cout << "   Name: " << currentWeapon.getName() << endl;
    cout << "   Type: " << currentWeapon.getType() << endl;
    cout << "   Attack Damage: " << currentWeapon.getAttackDamage() << endl;
}

vector < vector <Room> > generateDungeon(){
    vector< vector<Room> > dungeon;// Created the dungeon vector
    for (int i = 0; i < 5; i++){
        vector<Room>temp;
        for (int j = 0; j < 6; j++){
            Room room = Room("name", randNum(1, 2), j, i, false);
            temp.push_back(room);
        }
        dungeon.push_back(temp);
    }
    vector<Room>temp;
    for (int k = 0; k < 5; k++){
        int decider = randNum(1, 2);
        if (decider == 1) {
            Room room = Room("name", 3, k, 5, false);
            temp.push_back(room);
        }else {
            Room room = Room("Treasure name", randNum(1, 2), k, 5, false);
            temp.push_back(room);
        }
    }
    Room room = Room("name", 3, 5, 5, false);
    temp.push_back(room);
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

void printCurrentRoomCo(Player * monk) {
    cout << " Coordinates: ( X " << monk->getX() << ", Y " << monk->getY() << " )" << endl;
}

void movePlayer(Player * monk) {
    cout << "Choose what direction you want to move in : " << endl;
    string move;
    cin >> move;
    cout << "X : " << monk->getX() << " Y: " << monk->getY() << endl;
    if (move == "w" || move == "W") {
        int y = monk->getY();
        switch (y) {
            case 0:
                cout << "You can't move up" << endl;
                movePlayer(monk);
                break;
            default:
                monk->setY(y - 1);
                break;
        }
    } else if (move == "s" || move == "S") {
        int y = monk->getY();
        switch (y) {
            case 5:
                cout << "You can't move down" << endl;
                movePlayer(monk);
                break;
            default:
                monk->setY(y + 1);
                break;
        }
    } else if (move == "a" || move == "A") {
        int x = monk->getX();
        switch (x) {
            case 0:
                cout << "You can't move left" << endl;
                movePlayer(monk);
                break;
            default:
                monk->setX(x - 1);
                break;
        }
    } else if (move == "d" || move == "D") {
        int x = monk->getX();
        switch (x) {
            case 5:
                cout << "You can't move right" << endl;
                movePlayer(monk);
                break;
            default:
                monk->setX(x + 1);
                break;
        }
    }
}

void playerCombat(Player * monk, Monster currentMonster) {
    while (currentMonster.isAlive()) {
        cout << "There is a monster in the room" << endl;
        cout << "Your Health: " << monk->getHealth() << " HP." << endl;
        cout << "Monster's health: " << currentMonster.getHealth() << " HP." << endl;
        cout << "would you like to attack a or defend d :" << endl;
        string move;
        cin >> move;
        int WorL = randNum(0, 1);
        if (move == "a") {
            if (WorL == 0) {
                //int attack = randNum(1, monk.getAttackDamage());
                int attack = monk->getAttackDamage();
                cout << "You attacked the monster, you dealt " << attack << " points of damage to it." << endl;
                int monsterHp = currentMonster.getHealth() - attack;
                currentMonster.setHealth(monsterHp);
                if (currentMonster.getHealth() - attack <= 0) {
                    cout << "You Killed the Monster, You may progress" << endl;
                    currentMonster.setAlive(false);
                }
            } else if (WorL == 1) {
                int attack = randNum(1, currentMonster.getAttackDamage());
                if (monk->getHealth() - attack <= 0) {
                    cout << "You Died" << endl;
                    endGame();
                }
                cout << "the monster attacked you and dealt " << attack << " points of damage." << endl;
                monk->setHealth(monk->getHealth() - attack);
            }
        }else if(move == "d"){
            if (WorL == 0) {
                int healthGain = randNum(1,3);
                int maxHealth = monk->getMaxHealth();
                cout << "You gained " << healthGain << " health points" << endl;
                if(monk->getHealth() + healthGain > maxHealth){
                    monk->setHealth(maxHealth);
                }else{
                    healthGain = monk->getHealth() + healthGain;
                    monk->setHealth(healthGain);
                }
                cout << "Your current health is " << monk->getHealth() << endl;
            } else if (WorL == 1) {
                int attack = randNum(1, currentMonster.getAttackDamage());
                if (monk->getHealth() - attack <= 0) {
                    cout << "You Died" << endl;
                    endGame();
                }
                cout << "the monster attacked you and dealt " << attack << " points of damage." << endl;
                monk->setHealth(monk->getHealth() - attack);
            }
        }else{
            cout << "Please either enter a or d" << endl;
        }
    }
}

void runGame(vector<vector<Room>> dungeon, Player * monk){
    Draw draw = Draw();
    Monster currentMonster = Monster();
    currentMonster.setHealth(10);
    currentMonster.setAttackDamage(randNum(1,4));
    Room currentRoom = dungeon[monk->getX()][monk->getY()];
    draw.printRoom(currentRoom, monk);
    while (monk->isAlive()) {
        movePlayer(monk);
        currentRoom = dungeon[monk->getX()][monk->getY()];
        system("cls");
        if (currentRoom.isVisited()){
            cout << "You have already visited that room" << endl;
        }else{
            currentRoom.setVisited(true);
            if (currentRoom.getType() == 1) {
                printCurrentRoomCo(monk);
                draw.printRoom(currentRoom, monk);
            }else if (currentRoom.getType() == 2) {
                printCurrentRoomCo(monk);
                draw.printRoomWithObject(currentRoom, monk,"M");
                playerCombat(monk, currentMonster);
            }else if (currentRoom.getType() == 3) {
                printCurrentRoomCo(monk);
                draw.printRoomWithObject(currentRoom, monk,"T");
                cout << "***   Congratulations!   ***" << endl;
                cout << "Well done " << monk->getName() << ", you survived the dungeon with " << monk->getHealth() << " health points left." << endl;
                cout << "You completed the dungeon with a difficulty level of " << monk->getDifficulty() << endl;
                endGame();
            }
        }
    }
    cout << "You have died!" << endl;
    endGame();
}

void endGame() {
    exit(1);
}