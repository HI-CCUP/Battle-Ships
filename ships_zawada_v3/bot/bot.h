#ifndef BOT_H
#define BOT_H

#include "../player/player.h"
#include "../board/board.h"

using namespace std;

class Bot : public Player 
{
    
public:
    Bot(string name);
    void placeShips();
    bool turn(Player &opponent);


};

#endif