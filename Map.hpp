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

using namespace std;

class Map
{
    public:
        Map();
        ~Map();
        void run();

    private:
        vector<Ennemi> ennemis; //Initialisés aléatoirement ?
        //Ajouter un attribut caractérisant les portes nord sud est ouest 
        //par lesquelles le joueur peut sortir/entrer de la map
        bool currently_played;
  
};