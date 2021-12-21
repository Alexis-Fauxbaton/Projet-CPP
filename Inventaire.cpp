#include <iostream>
#include <string>
#include <vector>
#include "Inventaire.hpp"
#include "Objet.hpp"
using namespace std;


class Objet;

void Inventaire::ajouterObjet(Objet objet)
{
    if (objets.size()<max_objets)
        objets.push_back(objet);
}

void Inventaire::retirerObjet(int index)
{
    if (index<objets.size() && index>=0)
        objets.erase(objets.begin()+index);
}


void Inventaire::affecterObjet(Objet& objet, Personnage& personnage)
{

}


void Inventaire::desaffecterObjet(Arme& arme, Personnage& personnage)
{
    arme.setEquipe(false);
    personnage.getEquipement().getArme() = objets[0];
    
    
}

void Inventaire::desaffecterObjet(Armure& armure, Personnage& personnage)
{
    armure.setEquipe(false);
    personnage.getEquipement().getArmure() = objets[1];
    
    
}

void Inventaire::desaffecterObjet(Mystique& mystique, Personnage& personnage)
{
    mystique.setEquipe(false);
    personnage.getEquipement().getMystique() = objets[2];
    
    
}