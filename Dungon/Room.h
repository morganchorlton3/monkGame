//
// Created by morgan on 10/03/2019.
//

#ifndef MONK_ROOM_H
#define MONK_ROOM_H
#include <string>

using namespace std;
class Room {
public:

    Room(const string &name, int type, int X, int Y);

    const string &getName() const;

    void setName(const string &name);

    int getType() const;

    void setType(int type);

    int getX() const;

    void setX(int X);

    int getY() const;

    void setY(int Y);

private:
    string name;
    int type, X, Y;

};


#endif //MONK_ROOM_H
