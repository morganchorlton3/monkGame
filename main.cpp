#include <iostream>
#include <String>
#include "Character/Player.h"
#include "Dungon/Room.h"
#include "Tools/Weapon.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
void createWeapons(vector<Weapon> weaponList);
Player Welcome();
int randNum(int min, int max);
vector < vector <Room> > generateDungeon(int dungeonSize);
void printDungeon(const vector<vector <Room> > & dungeon);
void startGame(const vector<Room>&, Player monk);
void setPlayerWeapon(const vector<Weapon>& weaponList,Player monk);

int main() {
    srand((unsigned)time(NULL));//Sets seed for random generator
    Player *monk = new Player(Welcome());
    cout << "---  Monk Created  ---" << endl;
    cout << "---  Generating Dungeon  ---" << endl;
    int dungeonSize = randNum(1,10);
    int roomCount = 0;
    vector <vector <Room> >  dungeon  = generateDungeon(dungeonSize);// Generated the dungeon's rooms
    for(int i = 0; i < dungeon.size(); i++){
        roomCount =  roomCount + dungeon[i].size();
        for(int j = 0; j<dungeon[i].size(); j++){
            cout << "X: " << dungeon[i][j].getX() << " Y: " << dungeon[i][j].getY() << " ";
        }
        cout << endl;
    }
    cout << "Room count: " << roomCount << endl;
    cout << "---  Dungeon Complete  ---" << endl;
    //startGame(dungeon, *monk);
    return 0;
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

int randNum(int min, int max){
    return rand() % (max - min + 1) + min;


}

void startGame(const vector<Room>& dungeon, Player monk) {
    string name;
    int health;
    name = monk.getName();
    health = monk.getHealth();
    for(unsigned int i=0; i < dungeon.size(); i++){
        cout << "you have entered the room " << endl;
        /*if(checkMonster) {
            string play;
            cout << "There is a Monster in the room" << endl;
            cout << "How do you want to play: ";
            cin >> play;
            if(play == "a"){

            }
        }*/
    }
}

vector < vector <Room> > generateDungeon(int dungeonSize){
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