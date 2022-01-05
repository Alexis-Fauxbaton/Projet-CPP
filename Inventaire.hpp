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
        Inventaire();
        ~Inventaire(){};
        int getNbObjet();
        void ajouterObjet(Objet objet);
        void retirerObjet(size_t index);
        void affecterObjet(Arme& arme, Personnage& personnage); // A coder
        void affecterObjet(Armure& armure, Personnage& personnage);
        void affecterObjet(Mystique& mystique, Personnage& personnage);
        void desaffecterObjet(Arme& arme, Personnage& personnage); // A coder
        void desaffecterObjet(Armure& armure, Personnage& personnage);
        void desaffecterObjet(Mystique& mystique, Personnage& personnage);
        //void afficher(); Implementation avec IMGUI

    private://A modifier pour rendre heritage possible si besoin 
        size_t max_objets;
        vector<Objet> objets;
        
        
};


