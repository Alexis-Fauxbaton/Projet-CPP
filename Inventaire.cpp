#include <iostream>
#include <string>
#include <vector>
#include "Inventaire.hpp"
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