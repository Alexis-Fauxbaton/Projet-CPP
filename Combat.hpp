#pragma once
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Map.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
  

class Maitre;
class Ennemi;

using namespace std;

class Combat{

    public:
    
        Combat(Maitre &_P1, Ennemi &_P2,Map& _map);
        
        bool commencer(sf::RenderWindow &window,sf::Sound &music);

    private:
        Maitre perso1;
        Ennemi perso2;
        Map map;

};