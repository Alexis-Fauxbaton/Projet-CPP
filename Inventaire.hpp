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
        void affecterObjet(Arme& arme, Personnage& personnage);
        void affecterObjet(Armure& armure, Personnage& personnage);
        void affecterObjet(Mystique& mystique, Personnage& personnage);
        void desaffecterObjet(Arme& arme, Personnage& personnage);
        void desaffecterObjet(Armure& armure, Personnage& personnage);
        void desaffecterObjet(Mystique& mystique, Personnage& personnage);
        vector<Objet> &getObjets(){return objets;};
        Objet& getObjet(size_t index){return objets[index];};

    private:
        size_t max_objets;
        vector<Objet> objets;
        
        
};


