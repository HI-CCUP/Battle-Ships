#include <iostream>
#include "../functions/functions.h"
#include "../ship/ship.h"
#include "../board/board.h"
#include "player.h"

using namespace std;

Player::Player(string name)
{
    this->winCount = 0;

    cout << " name: ";
    cin >> name;

    this->name = name;

    clear();
    cout << "Hi, \033[1;31m" << name << "\033[0m!" <<endl;
    sleep(1500);
    
    clear();
}

string Player::returnName()
{
    return this->name;
}

void Player::clearBoardToNextGame()
{
    board.clearBoard();
}

void Player::increaseWinCount()
{
    this->winCount++;
}

short Player::returnWinCount()
{
    return this->winCount;
}

void Player::showBoard(Player &opponent)
{
    clear();
    
    cout << "\033[1;31m" << this->name <<"\'s\033[0m board:"<<endl;

    board.showBoard(true);
    

    cout <<endl<<"Opponent's board:" <<endl;

    opponent.board.showBoard(false);


}

void Player::placeShip(Player &opponent)
{
    clear();
    short shipSizes[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    short x, y;
    string direction;
    for(short &length : shipSizes)
    {
        bool isShipPlaced = false;
        while(isShipPlaced == false)
        {
            showBoard(opponent);
            cout << "Current ship length: " << length <<endl;
            cout << "Enter position of first ship cell (\033[1;32m x y direction \033[0m): " <<endl;
            cin >> x >> y >> direction;

            Ship ship(length, x, y, direction);
            isShipPlaced = board.canShipBePlaced(ship);
            

            if(isShipPlaced == false)
            {
                cout << "\033[1;31m" << "Can't place ship!" << "\033[0m";
                sleep(2000);
                clear();
            }
        }
    }
}

void Player::chceckAttackEffectiveness(const bool &hit, const bool &canShoot)
{
    if(hit && canShoot)
    {
       cout << "\033[1;35m" << "Shooted!" << "\033[0m" <<endl;
       sleep(2000);
    }else if(!hit && canShoot)
    {
        cout << "\033[1;36m" << "Mishit!" << "\033[0m" <<endl;
        sleep(2000);
    }else if(!canShoot && !hit)
    {
        cout << "You've already shot at this spot. Choose another one." <<endl;
        sleep(2000);
    }
}

bool Player::turn(Player &opponent)
{
    restBetweenPlayers();
    short x, y;
    bool hit, canShoot = false;

do
{

    showBoard(opponent);
    
    cout << "Player " << this->name << " is shooting:" <<endl;
    cout << "Enter (" << "\033[1;31m" << "x y" << "\033[0m" << ") of attack:" <<endl;
    cin  >> x >> y;
    
    hit = opponent.board.getHit(x, y, canShoot);
    
    chceckAttackEffectiveness(hit, canShoot);
    while(!canShoot)
    {
        cin  >> x >> y;
        hit = opponent.board.getHit(x, y, canShoot);
        chceckAttackEffectiveness(hit, canShoot);
    }
    


} while (hit);

    
    return !opponent.board.lostCheck();
}
