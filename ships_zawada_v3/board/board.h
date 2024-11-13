#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "../functions/functions.h"
#include "../ship/ship.h"

using namespace std;

class Board
{
    private:

    char playerBoard[10][10];
    std::vector<Ship> ships; //without std doesnt work
    

    public:
    Board();
    void clearBoard();
    void showBoard(bool whoseBoard);
    bool canShipBePlaced(Ship &ship);
    bool getHit(short x, short y, bool &canShoot);
    void markAreaOfSinkedShip(Ship &ship);
    bool lostCheck();

};

#endif