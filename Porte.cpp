#include "Porte.hpp"
#include <iostream>
#include <string>
#include <vector>

bool Porte::entre(int x, int y)
{
    if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            return true;
        }
    return false;
}