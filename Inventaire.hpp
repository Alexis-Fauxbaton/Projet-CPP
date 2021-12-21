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
        Inventaire():max_objets(15){objets.push_back(Objet("Aucun",0,0,0,false));}
        ~Inventaire();
        int getNbObjet(){return objets.size();}
        void ajouterObjet(Objet objet){objets.push_back(objet);}
        void retirerObjet(int index){objets.erase(objets.begin()+index);}
        void affecterObjet(Arme& arme, Personnage& personnage); // A coder
        void affecterObjet(Armure& armure, Personnage& personnage);
        void affecterObjet(Mystique& mystique, Personnage& personnage);
        void desaffecterObjet(Arme& arme, Personnage& personnage); // A coder
        void desaffecterObjet(Armure& armure, Personnage& personnage);
        void desaffecterObjet(Mystique& mystique, Personnage& personnage);
        //void afficher(); Implementation avec IMGUI

    private://A modifier pour rendre heritage possible si besoin 
        int max_objets;
        vector<Objet> objets;
        
        
};


