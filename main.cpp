#include <iostream>
#include <String>
#include <fstream>
#include <iterator>
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

Player Welcome();

vector < Weapon > createWeapons();

Weapon getPlayerWeapon(vector<Weapon> weaponList);

vector < vector <Room> > generateDungeon();

void printDungeon(vector< vector<Room> > &dungeon);

void printCurrentRoomCo(Player * monk);

void movePlayer(Player *monk);

void playerCombat(Player * monk, Monster currentMonster);

void runGame(vector<vector<Room>> dungeon, Player * monk);

vector < string > playerLog(Player * monk, string text);

void printWinLog(Player * monk);

void printLoseLog(Player * monk);

void printLog(Player * monk);

void endGame(Player *monk);

bool howToPlay();

int main() {
    srand((unsigned) time(NULL));//Sets seed for random generator
    if (howToPlay()) {
        vector<Weapon> weaponList = createWeapons();
        Player *monk = new Player(Welcome());
        Weapon currentWeapon = getPlayerWeapon(weaponList);
        monk->setWeapon(currentWeapon);
        monk->setWeaponName(currentWeapon.getName());
        monk->setAttackDamage(currentWeapon.getAttackDamage());
        cout << endl << "---  Generating Dungeon  ---" << endl << endl;
        cout << "   Generating";
        pauseConsole(1);
        vector<vector<Room> > dungeon = generateDungeon();// Generated the dungeon's rooms
        monk->setDungeonSize(dungeon.size() * 5);
        //printDungeon(dungeon);
        cout << endl << "---  Dungeon Complete  ---" << endl << endl;;
        cout << "   Welcome to the Game " << monk->getName() << ", You have chose to play on difficulty level "
             << monk->getDifficulty() << endl;
        cout << endl << "---  Starting Game  ---" << endl << endl;;
        Room currentRoom = dungeon[0][0];
        string yorn;
        cout << "   Are you ready to start? Y or N" << endl;
        getline(cin, yorn);
        while (true) {
            if (yorn == "y" || yorn == "Y") {
                cout << "Game Starting in " << endl;
                chrono::seconds duration(1);
                this_thread::sleep_for(duration);
                cout << "3" << endl;
                this_thread::sleep_for(duration);
                cout << "2" << endl;
                this_thread::sleep_for(duration);
                cout << "1" << endl;
                system("cls");
                runGame(dungeon, monk);
                break;
            } else if (yorn == "n" || yorn == "N") {
                cout << "   Thank you for playing Monk!" << endl;
                break;
            } else {
                cout << "   Please either enter Y or N" << endl;
                getline(cin, yorn);
            }
        }
        endGame(monk);
    }else{
        system("pause");
        exit(0);
    }
}

bool howToPlay() {
    cout << "How to Play: " << endl << endl;
    cout << "   The aim of the game is to reach the treasure room alive along the way you will enter rooms with monster in that you have to defeat." << endl;
    cout << "Player Movement: " << endl << endl;
    cout << "   Move around the dungeon by using W,A,S and D." << endl;
    cout << "   If you are in an empty room you can heal with H." << endl << endl;
    cout << "Player Combat: " << endl << endl;
    cout << "   You can attack with A and there will there is a 50/50 chance your attack will be successful." << endl;
    cout << "   You can defend with D and there will be a 50% chance you will heal a random amount between 1 and 3." << endl << endl;
    cout << "The Dungeon: " << endl << endl;
    cout << "   Once you enter a room with a monster you must defeat the monster to progress." << endl;
    cout << "   Once you reach the treasure room you will win the game. " << endl << endl;
    string yorn;
    cout << "Do you understand how to play? Y or N" << endl;
    getline(cin, yorn);
    while (true){
        if(yorn == "Y" || yorn == "y"){
            system("cls");
            return true;
        }else if (yorn == "N" || yorn == "n"){
            return false;
        }else{
            cout << "Please wither enter Y or N." << endl;
            getline(cin,yorn);
        }
    }
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

Player Welcome(){
    string input;
    int diff;
    cout << "   Welcome to Monk the dungeon survival game" << endl;
    cout << "---  Player Creation  ---" << endl;
    cout << "   Player Name: ";
    getline(cin, input);
    Player monk = Player(); /* Create the player */
    monk.setRoomCounter(0);
    monk.setKillCounter(0);
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
    vector < string > playerLog;
    monk.setPlayerLog(playerLog);
    return monk;
}

vector < Weapon > createWeapons() {
    vector <Weapon> weaponList;
    Weapon w1 = Weapon(0,"Blue Thunder", "Sword", 3);
    weaponList.push_back(w1);
    Weapon w2 = Weapon(1,"Walking stick","Stick", 4);
    weaponList.push_back(w2);
    Weapon w3 = Weapon(2,"Splitting Pain","Battle Axe", 5);
    weaponList.push_back(w3);
    Weapon w4 = Weapon(3,"Ramming rampage","Hammer", 2);
    weaponList.push_back(w3);
    Weapon w5 = Weapon(4,"Ninja Crazy","Nunchucks", 1);
    weaponList.push_back(w4);
    return weaponList;
};

Weapon getPlayerWeapon( vector<Weapon> weaponList) {
    cout << "   Randomly Choosing your weapon";
    pauseConsole(1);
    int choice = randNum(0,4);
    Weapon currentWeapon = weaponList[choice];
    cout << "   Your weapon has been selected: " << endl;
    cout << "   Name: " << currentWeapon.getName() << endl;
    cout << "   Type: " << currentWeapon.getType() << endl;
    cout << "   Attack Damage: " << currentWeapon.getAttackDamage() << endl;
    return currentWeapon;
}

vector < vector <Room> > generateDungeon(){
    vector< vector<Room> > dungeon;// Created the dungeon vector
    for (int i = 0; i < 5; i++){
        vector<Room>temp;
        for (int j = 0; j < 6; j++){
            Room room = Room("name", randNum(1, 2), j, i);
            temp.push_back(room);
        }
        dungeon.push_back(temp);
    }
    vector<Room>temp;
    for (int k = 0; k < 5; k++){
        int decider = randNum(1, 2);
        if (decider == 1) {
            Room room = Room("name", 3, k, 5);
            temp.push_back(room);
        }else {
            Room room = Room("Treasure name", randNum(1, 2), k, 5);
            temp.push_back(room);
        }
    }
    Room room = Room("name", 3, 5, 5);
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
    if (move == "w" || move == "W") {
        int y = monk->getY();
        switch (y) {
            case 0:
                cout << "You can't move up" << endl;
                movePlayer(monk);
                break;
            default:
                monk->setY(y - 1);
                monk->setPlayerLog(playerLog(monk, "moved UP ( X = " + to_string(monk->getX()) + " , Y = " + to_string(monk->getY()) + " )"));
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
                monk->setPlayerLog(playerLog(monk, "moved DOWN ( X = " + to_string(monk->getX()) + " , Y = " + to_string(monk->getY()) + " )"));
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
                monk->setPlayerLog(playerLog(monk, "moved LEFT ( X = " + to_string(monk->getX()) + " , Y = " + to_string(monk->getY()) + " )"));
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
                monk->setPlayerLog(playerLog(monk, "moved RIGHT ( X = " + to_string(monk->getX()) + " , Y = " + to_string(monk->getY()) + " )"));
                break;
        }
    } else if (move == "h" || move == "H"){
        int healthGain = randNum(1,4);
        if(monk->getHealth() + healthGain >= monk->getMaxHealth()){
            monk->setHealth(monk->getMaxHealth());
        }else{
            monk->setHealth(monk->getHealth() + healthGain);
        }
        cout << "You healed " << healthGain << endl;
        cout << "Your current health is " << monk->getHealth() << endl;
        monk->setPlayerLog(playerLog(monk, "  Healed ( X = " + to_string(monk->getX()) + " , Y = " + to_string(monk->getY()) + " )"));
        monk->setPlayerLog(playerLog(monk, "  Monks Health " + to_string(monk->getHealth())));
        movePlayer(monk);
    }else{
        cout << "Please either enter W,A,S or D to move or H to heal" << endl;
        movePlayer(monk);
    }
}

vector < string > playerLog(Player * monk, string text){
    vector < string > playerLog = monk->getPlayerLog();
    playerLog.push_back(text);
    return playerLog;
}

void printWinLog(Player * monk){
    fstream file("PlayerLog.txt", ios::app); //open for output
    file << "Congratulations " << monk->getName() <<" on defeating the dungeon " << endl;
    file << "You completed the dungeon with a difficulty level of " << monk->getDifficulty() << endl;
    file << "Player Statistics: " << endl << endl;
    file << "   Health: " << monk->getHealth() << endl;
    file << "   Weapon: " << monk->getWeaponName() << endl;
    file << "   Attack Damage: " << monk->getAttackDamage() << endl;
    file << "   Rooms Entered: " << monk->getRoomCounter() << endl;
    file << "   Total Room Count: " << monk->getDungeonSize() << endl;
    file << "   Kills: " << monk->getKillCounter() << endl << endl;
    file.close();
    printLog(monk);
}

void printLoseLog(Player * monk){
    fstream file("PlayerLog.txt", ios::app); //open for output
    file << "Commiserations " << monk->getName() <<" You lost the battle" << endl;
    file << "Player Statistics: " << endl << endl;
    file << "   Weapon: " << monk->getWeaponName() << endl;
    file << "   Attack Damage: " << monk->getAttackDamage() << endl;
    file << "   Rooms Entered: " << monk->getRoomCounter() << endl;
    file << "   Total Room Count: " << monk->getDungeonSize() << endl;
    file << "   Kills: " << monk->getKillCounter() << endl << endl;
    printLog(monk);
    file << endl << "   Thank you for Playing Monk!" << endl;
    file.close();

}

void printLog(Player * monk) {
    fstream file("PlayerLog.txt", ios::app); //open for output
    file << "Player moves through dungeon: " << endl << endl;
    vector < string > playerLog = monk->getPlayerLog();
    for(int i = 0; i < playerLog.size(); i++){
        file << "   " << playerLog[i] << endl;
    }
    file.close();
}

void playerCombat(Player * monk, Monster currentMonster) {
    while (currentMonster.isAlive()) {
        cout << "Your Health: " << monk->getHealth() << " HP." << endl;
        cout << "Monsters Health: " << currentMonster.getHealth() << " HP." << endl;
        monk->setPlayerLog(playerLog(monk, "  Monks Health " + to_string(monk->getHealth())));
        monk->setPlayerLog(playerLog(monk, "  Monsters Health " + to_string(currentMonster.getHealth())));
        cout << "would you like to attack a or defend d :" << endl;
        string move;
        cin >> move;
        int WorL = randNum(0, 1);// 50/50 chance that the attack will work
        if (move == "a" || move == "A") {
            if (WorL == 0) {
                int attack = monk->getAttackDamage();
                cout << "You attacked the monster, you dealt " << attack << " points of damage to it." << endl;
                monk->setPlayerLog(playerLog(monk, "  Monk deals " + to_string(attack) + " damage points"));
                int monsterHp = currentMonster.getHealth() - attack; // reduces the monsters HP
                currentMonster.setHealth(monsterHp); //sets the monsters HP
                if (currentMonster.getHealth() <= 0) { //Checks to see if the monster has any HP left
                    cout << "You Killed the Monster, You may progress" << endl;
                    monk->setPlayerLog(playerLog(monk, "  Monster killed"));
                    currentMonster.setAlive(false); // kills the monster
                    monk->setKillCounter(monk->getKillCounter() + 1); //Updates the kill counter for logs
                }
            } else if (WorL == 1) {
                cout << "Your attack failed, you missed the monster" << endl;
                int attack = randNum(1, currentMonster.getAttackDamage());
                if (monk->getHealth() - attack <= 0) {
                    cout << "You Died" << endl;
                    endGame(monk);
                }
                cout << "The monster attacked you and dealt " << attack << " points of damage." << endl;
                monk->setPlayerLog(playerLog(monk, "  Monster deals " + to_string(attack) + " damage points"));
                monk->setHealth(monk->getHealth() - attack);
            }
        } else if (move == "d" || move == "D") {
            if (WorL == 0) {
                int healthGain = randNum(1, 3);
                int maxHealth = monk->getMaxHealth();
                cout << "You gained " << healthGain << " health points" << endl;
                monk->setPlayerLog(playerLog(monk, "  Monk heals " + to_string(healthGain) + " health points"));
                if (monk->getHealth() + healthGain > maxHealth) {
                    monk->setHealth(maxHealth);
                } else {
                    healthGain = monk->getHealth() + healthGain;
                    monk->setHealth(healthGain);
                }
                cout << "Your current health is " << monk->getHealth() << endl;
                monk->setPlayerLog(playerLog(monk, "  Monk's current health " + to_string(monk->getHealth()) + " health points"));
            } else if (WorL == 1) {
                int attack = randNum(1, currentMonster.getAttackDamage());
                if (monk->getHealth() - attack <= 0) {
                    cout << "You Died" << endl;
                    monk->setAlive(false);
                    printLoseLog(monk);
                    endGame(monk);
                }
                cout << "The monster attacked you and dealt " << attack << " points of damage." << endl;
                monk->setPlayerLog(playerLog(monk, "  Monster deals " + to_string(attack) + " damage points"));
                monk->setHealth(monk->getHealth() - attack);
            }
        } else {
            cout << "Please either enter a or d" << endl;
        }
    }
}

void runGame(vector<vector<Room>> dungeon, Player * monk){
    Draw draw = Draw();
    Monster currentMonster = Monster();
    currentMonster.setHealth(randNum(5,10));
    currentMonster.setAttackDamage(randNum(1,4));
    Room currentRoom = dungeon[monk->getX()][monk->getY()];
    printCurrentRoomCo(monk);
    draw.printRoom(currentRoom, monk);
    while (monk->isAlive()) {
        movePlayer(monk);
        currentRoom = dungeon[monk->getX()][monk->getY()];
        monk->setRoomCounter(monk->getRoomCounter() + 1);
        system("cls");
        if (currentRoom.getType() == 1) {
            printCurrentRoomCo(monk);
            draw.printRoom(currentRoom, monk);
            monk->setPlayerLog(playerLog(monk, "*** Empty Room ***"));
            cout << "Your Health: " << monk->getHealth() << " HP." << endl;
        }else if (currentRoom.getType() == 2) {
            printCurrentRoomCo(monk);
            draw.printRoomWithObject(currentRoom, monk,"M");
            monk->setPlayerLog(playerLog(monk, "*** Monster Room ***"));
            playerCombat(monk, currentMonster);
        }else if (currentRoom.getType() == 3) {
            printCurrentRoomCo(monk);
            draw.printRoomWithObject(currentRoom, monk,"T");
            cout << "***   Congratulations!   ***" << endl;
            cout << "Well done " << monk->getName() << ", you survived the dungeon with " << monk->getHealth() << " health points left." << endl;
            cout << "You completed the dungeon with a difficulty level of " << monk->getDifficulty() << endl;
            printWinLog(monk);
            endGame(monk);
        }
    }
    cout << "You have died!" << endl;
    printLoseLog(monk);
    endGame(monk);
}

void endGame(Player *monk) {
    cout << "Dont forget to check you game log located in the same directory as the game, PlayerLog.txt " << endl;
    system("pause");
    exit(1);
}