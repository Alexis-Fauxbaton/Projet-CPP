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
        Obstacle(size_t x_coor, size_t y_coor, size_t L, size_t l):x(x_coor),y(y_coor),longueur(L),largeur(l){}
        ~Obstacle(){};
        bool detecter_collision(Personnage& perso);
        size_t getX(){return x;}
        size_t getY(){return y;}
        size_t getLongueur(){return longueur;}
        size_t getLargeur(){return largeur;}
        void setObstacle(size_t x_coor, size_t y_coor, size_t L, size_t l){x=x_coor;y=y_coor;longueur=L;largeur=l;}
        void setX(size_t x_coor){x=x_coor;}
        void setY(size_t y_coor){y=y_coor;}
        void setPosition(size_t x_coor, size_t y_coor){x=x_coor;y=y_coor;}
        void setLongueur(size_t L){longueur=L;}
        void setLargeur(size_t l){largeur=l;}
    
    private:
        size_t x;
        size_t y;
        size_t longueur;
        size_t largeur;
};