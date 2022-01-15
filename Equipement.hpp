#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Objet.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Objet;
class Arme;
class Armure;
class Mystique;

class Equipement
{
    public:
        Equipement():arme(),armure(),mystique(){};
        ~Equipement(){};
        Objet& getArme(){return arme;}
        Objet& getArmure(){return armure;}
        Objet& getMystique(){return mystique;}
        void setArme(Arme& arme){this->arme=arme;}
        void setArmure(Armure& armure){this->armure=armure;}
        void setMystique(Mystique& mystique){this->mystique=mystique;}
        //void afficher(); Implementation avec IMGUI

    private://A modifier pour rendre heritage possible si besoin 
        int max_objets;
        Arme arme;
        Armure armure;
        Mystique mystique;
        
        
};

