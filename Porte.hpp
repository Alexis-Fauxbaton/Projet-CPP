#pragma once

#include <iostream>
#include <string>
#include <vector>

typedef enum{NORTH,SOUTH,EAST,WEST} Cardinalite;

class Porte
{
    public:
        Porte():x1(-10),x2(-10),y1(-10),y2(-10),orientation(NORTH){}
        
        Porte(int p1, int p2, int y1, int y2, Cardinalite o):x1(p1),x2(p2),y1(y1),y2(y2),orientation(o){}

        Porte(const Porte& p):x1(p.x1),x2(p.x2),y1(p.y1),y2(p.y2),orientation(p.orientation){}

        int getX1() const {return x1;}

        int getX2() const {return x2;}

        int getY1() const {return y1;}

        int getY2() const {return y2;}

        Cardinalite getOrientation() const {return orientation;}

        void setX1(int p1){x1=p1;}

        void setX2(int p2){x2=p2;}

        void setY1(int y1){this->y1=y1;}

        void setY2(int y2){this->y2=y2;}

        void setOrientation(Cardinalite o){orientation=o;}

        bool entre(int x, int y);

        void afficher_coordonnees(){std::cout<<"x1: "<<x1<<" y1: "<<y1<<std::endl<<" x2: "<<x2<<" y2: "<<y2<<std::endl;}

    private:
        int x1;
        int x2;
        int y1;
        int y2;
        Cardinalite orientation;
};