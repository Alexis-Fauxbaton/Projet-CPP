#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Objet.hpp"

using namespace std;

class Objet;

class Equipement
{
    public:
        Equipement():arme(),armure(),mystique(){};
        ~Equipement();
        Objet& getArme(){return arme;}
        Objet& getArmure(){return armure;}
        Objet& getMystique(){return mystique;}
        Objet& setArme(Objet& arme);
        Objet& setArmure(Objet& armure);
        Objet& setMystique(Objet& mystique);
        //void afficher(); Implementation avec IMGUI

    private://A modifier pour rendre heritage possible si besoin 
        int max_objets;
        Objet arme;
        Objet armure;
        Objet mystique;
        
        
};