#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Objet.hpp"
using namespace std;

class Objet;

class Inventaire//Inventaire du Master
{
    public:
        Inventaire():objets(),max_objets(3){};
        ~Inventaire();
        int getNbObjet(){return objets.size();}
        void ajouterObjet(Objet objet);
        void retirerObjet(int index);
        //void afficher(); Implementation avec IMGUI

    private://A modifier pour rendre heritage possible si besoin 
        int max_objets;
        vector<Objet> objets;
        
        
};


