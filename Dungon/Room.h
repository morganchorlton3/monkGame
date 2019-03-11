//
// Created by morgan on 10/03/2019.
//

#ifndef MONK_ROOM_H
#define MONK_ROOM_H
#include <string>

using namespace std;
class Room {
public:
    Room(const string &name, int type, bool monster);


public:

    const string &getName() const;

    void setName(const string &name);

    int getType() const;

    void setType(int type);

    bool isMonster() const;

    void setMonster(bool monster);

private:
    string name;
    int type;
    bool monster;

};


#endif //MONK_ROOM_H
