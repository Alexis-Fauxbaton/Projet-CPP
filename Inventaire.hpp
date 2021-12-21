#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Objet.hpp"
#include "Personnage.hpp"
using namespace std;

class Personnage;

class Objet;

class Inventaire//Inventaire du Master
{
    public:
        Inventaire():objets(),max_objets(3){};
        ~Inventaire();
        int getNbObjet(){return objets.size();}
        void ajouterObjet(Objet objet){objets.push_back(objet);}
        void retirerObjet(int index){objets.erase(objets.begin()+index);}
        void affecterObjet(Objet& objet, Personnage& personnage); // A coder
        void desaffecterObjet(Arme& arme, Personnage& personnage); // A coder
        void desaffecterObjet(Armure& armure, Personnage& personnage);
        void desaffecterObjet(Mystique& mystique, Personnage& personnage);
        //void afficher(); Implementation avec IMGUI

    private://A modifier pour rendre heritage possible si besoin 
        int max_objets;
        vector<Objet> objets;
        
        
};


