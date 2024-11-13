#include "Bot.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const short BOT_BOARD_SIZE = 9;

Bot::Bot(string name) : Player(name)
{
    this->name = name;
    
}

void Bot::placeShips()
{
    srand(time(NULL));
    short shipSizes[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    short x, y, d;
    string direction;
    bool isShipPlaced = false;

    for (short &size : shipSizes)
    {
        int attempts = 0; //as if what
        isShipPlaced = false;
        
        while (!isShipPlaced && attempts < 100)
        {
            x = rand() % BOT_BOARD_SIZE;
            y = rand() % BOT_BOARD_SIZE;
            d = rand() % 2;
            
            if(d == 0){direction = "e";}
            if(d == 1){direction = "s";}

            Ship ship(x, y, size, direction);
            isShipPlaced = board.canShipBePlaced(ship);
            attempts++;
        }
    }
}


bool Bot::turn(Player &opponent)
{

    short x, y;
    bool hit, canShoot = false;
    do
    {
        while(!canShoot)
        {
            x = rand() % BOT_BOARD_SIZE;
            y = rand() % BOT_BOARD_SIZE;
            hit = opponent.board.getHit(x, y, canShoot);
            if(hit && x+1 <= BOT_BOARD_SIZE)
            {
                hit = opponent.board.getHit(x+1, y, canShoot);
            }else if(hit && x-1 >= 0)
            {
                hit = opponent.board.getHit(x-1, y, canShoot);
            }else if(hit && y-1 >= 0)
            {
                hit = opponent.board.getHit(x, y-1, canShoot);
            }else if(hit && y+1 <= BOT_BOARD_SIZE)
            {
                hit = opponent.board.getHit(x, y+1, canShoot);
            }
        
        }
    } while (hit);

    

    return !opponent.board.lostCheck();
    
}
