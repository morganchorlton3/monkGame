#include <iostream>
#include <String>
#include "Character/Player.h"
#include "Dungon/Room.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


void Welcome(){
    string input;
    int diff;
    cout << "Welcome to Monk the dungeon survival game" << endl;
    cout << "---  Setup  ---" << endl;
    cout << "Player Name: ";
    getline(cin, input);
    Player Monk = Player(); /* Create the player */
    Monk.setName(input); /* set player name */
    cout << "Please enter your difficulty 1 = easy, 2 = medium, 3 = hard ";
    getline(cin,input);
    stringstream myStream(input);
    if (myStream >> diff)
        Monk.setDifficulty(diff);
    if (Monk.getDifficulty() == 1){
        Monk.setHealth(20);
    }else if (Monk.getDifficulty() == 2){
        Monk.setHealth(15);
    }else if (Monk.getDifficulty() == 3){
        Monk.setHealth(10);
    }
    cout << "Welcome to the Game " << Monk.getName() << ", You have chose to play with a difficulty level of " << Monk.getDifficulty() << endl;
}
int randNum(int min, int max)
{
    return rand() % (max - min + 1) + min;


}
void fillVector(vector<Room>&);
void printVector(const vector<Room>&);
int main() {
    srand((unsigned)time(NULL));
    /*Welcome();*/
    vector<Room> dungeon;
    fillVector(dungeon);
    printVector(dungeon);
    return 0;
}
void fillVector(vector<Room>& newDungeon){
    for(int i=1; i<=6; i++){
        Room room(randNum(1,3), true);
        newDungeon.push_back(room);
    }
}
void printVector(const vector<Room>& newDungeon){
    for(unsigned int i=0; i < newDungeon.size(); i++){
        cout << "Dungeon:" << endl;
        cout << "Room Type: " << newDungeon[i].getType() << " Has Monsters: " << newDungeon[i].isMonster() << endl;
    }
}
