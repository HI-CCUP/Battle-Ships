#ifndef SHIP_H
#define SHIP_H

#include <iostream>

using namespace std;

class Ship
{
    private:

    short length;
    short hits;
    short positionX;
    short positionY;
    string direction;

    public:

    Ship(short length, short x, short y, string direction);

    bool isAlive();
    void hitted();
    string returnDirection();
    short returnX();
    short returnY();
    short returnLength();
    bool isAtPosition(short x, short y);



};

#endif