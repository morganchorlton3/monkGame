//
// Created by morga on 14/03/2019.
//

#ifndef MONK_COORDINATES_H
#define MONK_COORDINATES_H


class Coordinates {
public:
    int x, y;

    Coordinates(int x, int y);

    Coordinates();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
};


#endif //MONK_COORDINATES_H
