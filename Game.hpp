#pragma once
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Map.hpp"
#include "Combat.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using namespace std;

//vector<Objet> OBJETS; // A DEFINIR

//vector<Map> MAPS; // A DEFINIR

class Game
{
    public:
        Game():en_cours(true){}
        ~Game(){};
        void run(vector<Map*> maps);

    private:
        bool en_cours;

};
