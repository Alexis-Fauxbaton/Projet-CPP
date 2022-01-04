#include <iostream>
#include <string>
#include <vector>
#include "Inventaire.hpp"
#include "Objet.hpp"
using namespace std;


class Objet;

Inventaire::Inventaire():max_objets(15)
{
    objets.push_back(Objet("Aucun",0,0,0,false));
}

int Inventaire::getNbObjet()
{
    return objets.size();
}

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


void Inventaire::affecterObjet(Arme& arme, Personnage& personnage)
{
    if (arme.getEquipe()==false)
    {
        arme.setEquipe(true);
        personnage.getEquipement().setArme(arme);
    }
}

void Inventaire::affecterObjet(Armure& armure, Personnage& personnage)
{
    if (armure.getEquipe()==false)
    {
        armure.setEquipe(true);
        personnage.getEquipement().setArmure(armure);
    }
}

void Inventaire::affecterObjet(Mystique& mystique, Personnage& personnage)
{
    if (mystique.getEquipe()==false)
    {
        mystique.setEquipe(true);
        personnage.getEquipement().setMystique(mystique);
    }
}

void Inventaire::desaffecterObjet(Arme& arme, Personnage& personnage)
{

    arme.setEquipe(false);
    personnage.getEquipement().getArme() = objets[0]; // Vérifier si l'arme n'est pas écrasée par la valeur de objets[0] à cause du "="
    
    
}

void Inventaire::desaffecterObjet(Armure& armure, Personnage& personnage)
{
    armure.setEquipe(false);
    personnage.getEquipement().getArmure() = objets[0];
    
    
}

void Inventaire::desaffecterObjet(Mystique& mystique, Personnage& personnage)
{
    mystique.setEquipe(false);
    personnage.getEquipement().getMystique() = objets[0];
    
    
}