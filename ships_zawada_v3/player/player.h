#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "../board/board.h"
#include <time.h>
#include <cstdlib>

using namespace std;

class Ship;

class Player
{
    private:

    
    short winCount;
    

    public:

    Board board;
    string name;
    

    Player(string name);
    string returnName();
    void clearBoardToNextGame();
    void increaseWinCount();
    short returnWinCount();
    void showBoard(Player &opponent);
    void placeShip(Player &opponent);
    void chceckAttackEffectiveness(const bool &hit, const bool &canShoot);
    bool turn(Player &opponent);


};

#endif