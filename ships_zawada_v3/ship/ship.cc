#include <iostream>
#include "ship.h"

using namespace std;

Ship::Ship(short length, short x, short y, string direction)
{
    this->length = length;
    this->positionX = x;
    this->positionY = y;
    this->direction = direction;
    this->hits = this->length;
}

bool Ship::isAlive()
{
    return this->hits > 0;
}

void Ship::hitted()
{ 
    this->hits--;
}

string Ship::returnDirection()
{
    return this->direction;
}

short Ship::returnX()
{
    return this->positionX;
}

short Ship::returnY()
{
    return this->positionY;
}

short Ship::returnLength()
{
    return this->length;
}

bool Ship::isAtPosition(short x, short y)
{
    if(direction == "E" || direction == "e" || direction == "East" || direction == "east")
    {
        return (this->positionY == y) && (x>= this->positionX) && (x < this->positionX + length);
    }else if(direction == "S" || direction == "s" || direction == "South" || direction == "south")
    {
        return (this->positionX == x) && (y >= this->positionY) && (y < this->positionY + length);

    }else if(direction == "N" || direction == "n" || direction == "North" || direction == "north")
    {
        return (this->positionX == x) && (y<= this->positionY) && (y > this->positionY - length);
    }else if(direction == "W" || direction == "w" || direction == "West" || direction == "west")
    {
        return (this->positionY == y) && (x <= this->positionX) && (x > this->positionX - length);

    }
    return false;
}
