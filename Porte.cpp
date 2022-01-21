#include "Porte.hpp"
#include <iostream>
#include <string>
#include <vector>

bool Porte::entre(int x, int y)
{
    std::cout << "Point 1 :" << x1 << " " << y1 << std::endl;
    std::cout << "Point 2 :" << x2 << " " << y2 << std::endl;
    std::cout << "Joueur :" << x << " " << y << std::endl;
    std::cout << (x >= x1 && x <= x2 && y >= y1 && y <= y2) << std::endl;
    if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            return true;
        }
    return false;
}