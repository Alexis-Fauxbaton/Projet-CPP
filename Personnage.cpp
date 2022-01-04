#include <iostream>
#include <string>
#include "Personnage.hpp"
#include "Equipement.hpp"
//#include "Allie.hpp"
using namespace std;

void Personnage::appliquerEffetEquipement()
{
    atk=baseAtk+equipement.getArme().getAtk()+equipement.getArmure().getAtk()+equipement.getMystique().getAtk();

    hp=baseHp+equipement.getArmure().getHP()+equipement.getMystique().getHP()+equipement.getArme().getHP();
    
}

void Personnage::ajouterArme(Arme& arme)
{
    equipement.setArme(arme);
    appliquerEffetEquipement();
}

void Personnage::ajouterArmure(Armure& armure)
{
    equipement.setArmure(armure);
    appliquerEffetEquipement();
}

void Personnage::ajouterMystique(Mystique& mystique)
{
    equipement.setMystique(mystique);
    appliquerEffetEquipement();
}

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