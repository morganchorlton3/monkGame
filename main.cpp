#include <iostream>
#include <String>
#include "Character/Player.h"
#include "Dungon/Room.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
Player Welcome();
int randNum(int min, int max);
void fillDungeon(vector<Room>&, Player monk);
void printDungeon(const vector<Room>&);
void startGame(const vector<Room>&, Player monk);

int main() {
    srand((unsigned)time(NULL));
    Player *monk = new Player(Welcome());
    cout << "---  Generating Dungeon  ---" << endl;
    vector<Room> dungeon;/* Created the dungeon vector */
    fillDungeon(dungeon, *monk);/* Generated the dungeon's rooms */
    cout << "---  Dungeon Complete  ---" << endl;
    printDungeon(dungeon);
    startGame(dungeon, *monk);
    return 0;
}
Player Welcome(){
    string input;
    int diff;
    cout << "Welcome to Monk the dungeon survival game" << endl;
    cout << "---  Setup  ---" << endl;
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
int randNum(int min, int max)
{
    return rand() % (max - min + 1) + min;


}
void startGame(const vector<Room>&, Player monk) {
    string name;
    int health;
    name = monk.getName();
    health = monk.getHealth();
}

void fillDungeon(vector<Room>& newDungeon, Player monk){
    int dungeonSize;
    int roomCounter = 0;
    if (monk.getDifficulty() == 1){
        dungeonSize = 10;
    }else if (monk.getDifficulty() == 2){
        dungeonSize = 15;
    }else if (monk.getDifficulty() == 3){
        dungeonSize = 20;
    }
    for(int i=1; i<=dungeonSize; i++){
        int monsterSpawn = randNum(1,10);
        bool monster;
        if(monsterSpawn <= 5){
            monster = true;
        }else if(monsterSpawn > 5){
            monster = false;
        }
        string roomName = "Room ";
        roomName += std::to_string(roomCounter);
        roomCounter++;
        Room room(roomName,randNum(1,3), monster);
        newDungeon.push_back(room);
    }
    /* Adds Treasure Room at the end */
    Room room("Treasure Room",4, false);
    newDungeon.push_back(room);
}
void printDungeon(const vector<Room>& newDungeon){
    for(unsigned int i=0; i < newDungeon.size(); i++){
        cout << "Dungeon:" << endl;
        cout << "Room name: " << newDungeon[i].getName() << " Room Type: " << newDungeon[i].getType() << " Has Monsters: " << newDungeon[i].isMonster() << endl;
    }
}
