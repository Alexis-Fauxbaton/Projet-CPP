#include <iostream>
#include <string>
#include "Personnage.hpp"
#include "Equipement.hpp"
//#include "Allie.hpp"
using namespace std;

Allie::Allie(std::string nom, int vie, int force):Personnage(nom,vie,force)
{
    
}

void Allie::attaquer(Ennemi &cible)
{
    cible.subir(this->atk);
}

void Ennemi::attaquer(Allie &cible)
{
    cible.subir(this->atk);
}