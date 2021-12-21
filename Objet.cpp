#include <iostream>
#include <string>
#include "Objet.hpp"
using namespace std;


Objet Objet::operator=(const Objet& objet)
{
    nom=objet.nom;
    hp=objet.hp;
    atk=objet.atk;
    def=objet.def;
    estEquipe=objet.estEquipe;
    return *this;
}