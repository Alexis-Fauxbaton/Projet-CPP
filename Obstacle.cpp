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
#include "Obstacle.hpp"

using namespace std;

bool Obstacle::detecter_collision(Personnage& perso) // On détecte si le personnage "perso" entre en collision avec l'obstacle courant
{
    if(perso.getX()>=x && perso.getX()<=x+longueur && perso.getY()>=y && perso.getY()<=y+largeur)
    {
        return true;
    }
    else
    {
        return false;
    }
}