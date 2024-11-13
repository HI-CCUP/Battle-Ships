#include <iostream>
#include "board.h"


using namespace std;

const short BOARD_SIZE = 9;

Board::Board()
{
    for(short i = 0; i <= BOARD_SIZE; i++)
    {
        for(short j = 0; j <= BOARD_SIZE; j++)
        {
            this->playerBoard[i][j] = '~';
        }
    }
}

void Board::clearBoard()
{
    for(short i = 0; i <= BOARD_SIZE; i++)
    {
        for(short j = 0; j <= BOARD_SIZE; j++)
        {
            this->playerBoard[i][j] = '~';
        }
    }
}

void Board::showBoard(bool whoseBoard)
{

    cout << " |0 1 2 3 4 5 6 7 8 9 | " <<endl;
    cout << "=|====================|=" <<endl;
    

    for (short i = 0; i <= BOARD_SIZE; i++) {
        

       
            cout << i << "|";
            for (short j = 0; j <= BOARD_SIZE; j++) {
                if (playerBoard[i][j] == '~') cout << "\033[1;44m~ \033[0m";
                if (playerBoard[i][j] == '#' && whoseBoard) cout << "\033[1;41m# \033[0m"; // ship
                if (playerBoard[i][j] == '#' && !whoseBoard) cout << "\033[1;44m~ \033[0m"; // hidden ship
                if (playerBoard[i][j] == 'X') cout << "\033[1;42mX \033[0m";
                if (playerBoard[i][j] == '-') cout << "\033[1;43m- \033[0m";
           }
            
        

        cout << "|" <<endl;     
    }
    cout << "=|====================|=" <<endl;
}

bool Board::canShipBePlaced(Ship &ship)
{
    string orientation = ship.returnDirection();
    short x = ship.returnX();
    short y = ship.returnY();
    short length = ship.returnLength();

    if (orientation == "E" || orientation == "e" || orientation == "East" || orientation == "east")
    {
        if (x + length > BOARD_SIZE+1 || x < 0)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            if (this->playerBoard[y][x + i] != '~')
            {
                return false;
            }
            //left as a curiosity
            /*if ((x + i - 1 >= 0 && this->playerBoard[y][x + i - 1] == '#') ||
                (x + i + 1 <= BOARD_SIZE && this->playerBoard[y][x + i + 1] == '#') ||
                (y - 1 >= 0 && this->playerBoard[y - 1][x + i] == '#') ||
                (y + 1 <= BOARD_SIZE && this->playerBoard[y + 1][x + i] == '#') ||
                (y - 1 >= 0 && x + i - 1 >= 0 && this->playerBoard[y - 1][x + i - 1] == '#') ||
                (y - 1 >= 0 && x + i + 1 <= BOARD_SIZE && this->playerBoard[y - 1][x + i + 1] == '#') ||
                (y + 1 <= BOARD_SIZE && x + i - 1 >= 0 && this->playerBoard[y + 1][x + i - 1] == '#') ||
                (y + 1 <= BOARD_SIZE && x + i + 1 <= BOARD_SIZE && this->playerBoard[y + 1][x + i + 1] == '#'))
            {
                return false;
            }*/
           for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy == 0 && dx == 0) continue;//skip position y, x+i

                    int newY = y + dy;
                    int newX = x + i + dx;

                    if (newY >= 0 && newY <= BOARD_SIZE && newX >= 0 && newX <= BOARD_SIZE) //check is inside the board
                    {
                        if (this->playerBoard[newY][newX] == '#') {
                            return false;
                        }
                    }
                }   
            }
        }

        for (int i = 0; i < length; i++)
        {
            this->playerBoard[y][x + i] = '#';
        }
        this->ships.push_back(ship);
        return true;

    }
    else if (orientation == "S" || orientation == "s" || orientation == "South" || orientation == "south")
    {
        if (y + length > BOARD_SIZE+1 || y < 0)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            if (this->playerBoard[y + i][x] != '~') { return false; }

            /*if ((y + i - 1 >= 0 && this->playerBoard[y + i - 1][x] == '#') ||
                (y + i + 1 <= BOARD_SIZE && this->playerBoard[y + i + 1][x] == '#') ||
                (x - 1 >= 0 && this->playerBoard[y + i][x - 1] == '#') ||
                (x + 1 <= BOARD_SIZE && this->playerBoard[y + i][x + 1] == '#') ||
                (y + i - 1 >= 0 && x - 1 >= 0 && this->playerBoard[y + i - 1][x - 1] == '#') ||
                (y + i - 1 >= 0 && x + 1 <= BOARD_SIZE && this->playerBoard[y + i - 1][x + 1] == '#') ||
                (y + i + 1 <= BOARD_SIZE && x - 1 >= 0 && this->playerBoard[y + i + 1][x - 1] == '#') ||
                (y + i + 1 <= BOARD_SIZE && x + 1 <= BOARD_SIZE && this->playerBoard[y + i + 1][x + 1] == '#'))
            {
                return false;
            }*/

           for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy == 0 && dx == 0) continue;//skip position y+i, x

                    int newY = y + i + dy;
                    int newX = x + dx;

                    
                    if (newY >= 0 && newY <= BOARD_SIZE && newX >= 0 && newX <= BOARD_SIZE) //check is inside the board
                    {
                        if (this->playerBoard[newY][newX] == '#') {
                            return false;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < length; i++)
        {
            this->playerBoard[y + i][x] = '#';
        }
        this->ships.push_back(ship);
        return true;
    }
    else if (orientation == "N" || orientation == "n" || orientation == "North" || orientation == "north")
    {
        if (y - length + 1 < 0 || y >= BOARD_SIZE+1)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            if (this->playerBoard[y - i][x] != '~') { return false; }

            /*if ((y - i - 1 >= 0 && this->playerBoard[y - i - 1][x] == '#') ||
                (y - i + 1 <= BOARD_SIZE && this->playerBoard[y - i + 1][x] == '#') ||
                (x - 1 >= 0 && this->playerBoard[y - i][x - 1] == '#') ||
                (x + 1 <= BOARD_SIZE && this->playerBoard[y - i][x + 1] == '#') ||
                (y - i - 1 >= 0 && x - 1 >= 0 && this->playerBoard[y - i - 1][x - 1] == '#') ||
                (y - i - 1 >= 0 && x + 1 <= BOARD_SIZE && this->playerBoard[y - i - 1][x + 1] == '#') ||
                (y - i + 1 <= BOARD_SIZE && x - 1 >= 0 && this->playerBoard[y - i + 1][x - 1] == '#') ||
                (y - i + 1 <= BOARD_SIZE && x + 1 <= BOARD_SIZE && this->playerBoard[y - i + 1][x + 1] == '#'))
            {
                return false;
            }*/
           for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dy == 0 && dx == 0) continue;//skip position y-i, x

                int newY = y - i + dy;
                int newX = x + dx;

                if (newY >= 0 && newY <= BOARD_SIZE && newX >= 0 && newX <= BOARD_SIZE) //check is inside the board
                {
                    if (this->playerBoard[newY][newX] == '#') {
                        return false;
                    }
                }
            }
        }
        }

        for (int i = 0; i < length; i++)
        {
            this->playerBoard[y - i][x] = '#';
        }
        this->ships.push_back(ship);
        return true;
    }
    else if (orientation == "W" || orientation == "w" || orientation == "West" || orientation == "west")
    {
        if (x - length + 1 < 0 || x >= BOARD_SIZE+1)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            if (this->playerBoard[y][x - i] != '~') { return false; }

            /*if ((x - i - 1 >= 0 && this->playerBoard[y][x - i - 1] == '#') ||
                (x - i + 1 <= BOARD_SIZE && this->playerBoard[y][x - i + 1] == '#') ||
                (y - 1 >= 0 && this->playerBoard[y - 1][x - i] == '#') ||
                (y + 1 <= BOARD_SIZE && this->playerBoard[y + 1][x - i] == '#') ||
                (y - 1 >= 0 && x - i - 1 >= 0 && this->playerBoard[y - 1][x - i - 1] == '#') ||
                (y - 1 >= 0 && x - i + 1 < BOARD_SIZE && this->playerBoard[y - 1][x - i + 1] == '#') ||
                (y + 1 <= BOARD_SIZE && x - i - 1 >= 0 && this->playerBoard[y + 1][x - i - 1] == '#') ||
                (y + 1 <= BOARD_SIZE && x - i + 1 <= BOARD_SIZE && this->playerBoard[y + 1][x - i + 1] == '#'))
            {
                return false;
            }*/
           for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dy == 0 && dx == 0) continue;//skip position y, x-i

                int newY = y + dy;
                int newX = x - i + dx;

                if (newY >= 0 && newY <= BOARD_SIZE && newX >= 0 && newX <= BOARD_SIZE)//check is inside the board
                {
                    if (this->playerBoard[newY][newX] == '#') {
                        return false;
                    }
                }
            }
        }
        }

        for (int i = 0; i < length; i++)
        {
            this->playerBoard[y][x - i] = '#';
        }
        this->ships.push_back(ship);
        return true;
    }

    return false;
}



bool Board::getHit(short x, short y, bool &canShoot)
{
    bool repair = true;
    if(this->playerBoard[y][x] == '#')
    {
        this->playerBoard[y][x] = 'X';

   for(short i = 0; i <= ships.size(); i++)
   {
        if(ships[i].isAtPosition(x, y))
        {
            ships[i].hitted();

            if(!ships[i].isAlive())
            {
                markAreaOfSinkedShip(ships[i]);
                //return true; - it doesnt work, idk why
                repair = true;    
            }
            break;
        }
        
   }

        canShoot = true;
        
    }else if(this->playerBoard[y][x] == '~'){
        this->playerBoard[y][x] = '-';
        canShoot = true;
        
        repair = false;
    }else{
        //cout << "You've already shot at this spot. Choose another one." <<endl;
        canShoot = false;
        
        repair = false;
    }
    return repair;
    
}

void Board::markAreaOfSinkedShip(Ship &ship)
{
    short x = ship.returnX();
    short y = ship.returnY();
    string orientation = ship.returnDirection();
    short size = ship.returnLength();

    short startX = x, startY = y, endX = x, endY = y;

    if(orientation == "E" || orientation == "e" || orientation == "East" || orientation == "east")
    {
        endX = x + size- 1;
    }else if(orientation == "S" || orientation == "s" || orientation == "South" || orientation == "south")
    {
        endY = y + size - 1;
    }else if(orientation == "N" || orientation == "n" || orientation == "North" || orientation == "north")
    {
        startY = y - size + 1;
    }else if(orientation == "W" || orientation == "w" || orientation == "West" || orientation == "west")
    {
        startX = x - size + 1;
    }

    for (int i = startY - 1; i <= endY + 1; i++) 
    {
        for (int j = startX - 1; j <= endX + 1; j++) 
        {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) //is out of board
            {
                if (this->playerBoard[i][j] != 'X')//without this it change 'X' from ship to '~'
                {
                    this->playerBoard[i][j] = '-';
                }
            }
        }
    }

}

bool Board::lostCheck()
{
    for(int i = 0; i <= BOARD_SIZE; i++)
    {
        for(int j = 0; j <= BOARD_SIZE; j++)
        {
            if(playerBoard[i][j] ==  '#')
            {
                return true;
            }

        }
    }
    return false;
}
