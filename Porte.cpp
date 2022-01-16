#include "Porte.hpp"
#include <iostream>
#include <string>
#include <vector>

bool Porte::entre(int x, int y)
{
    if(orientation == NORTH)
    {
        if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            return true;
        }
    }
    else if(orientation == SOUTH)
    {
        if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            return true;
        }
    }
    else if(orientation == EAST)
    {
        if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            return true;
        }
    }
    else if(orientation == WEST)
    {
        if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            return true;
        }
    }
    return false;
}