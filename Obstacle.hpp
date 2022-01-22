#pragma once
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Obstacle
{
    public:
        Obstacle(size_t x_coor, int y_coor, int L, int l):x(x_coor),y(y_coor),longueur(L),largeur(l){}
        ~Obstacle(){};
        bool detecter_collision(Personnage& perso);
        int getX(){return x;}
        int getY(){return y;}
        int getLongueur(){return longueur;}
        int getLargeur(){return largeur;}
        void setObstacle(int x_coor, int y_coor, int L, int l){x=x_coor;y=y_coor;longueur=L;largeur=l;}
        void setX(int x_coor){x=x_coor;}
        void setY(int y_coor){y=y_coor;}
        void setPosition(int x_coor, int y_coor){x=x_coor;y=y_coor;}
        void setLongueur(int L){longueur=L;}
        void setLargeur(int l){largeur=l;}
    
    private:
        int x;
        int y;
        int longueur;
        int largeur;
};