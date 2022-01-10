#include <iostream>
#include <string>
#include "Personnage.hpp"
#include "Equipement.hpp"
//#include "Allie.hpp"
using namespace std;

Personnage::Personnage():hp(0),atk(0),nom(""),equipement(),baseAtk(0),baseHp(0),x(0),y(0)
{
    sf::Texture texture;
    texture.loadFromFile("Images/poubelle2.png");
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
}

Personnage::Personnage(std::string nom, int vie, int force, size_t x_coor, size_t y_coor, string texture_path):hp(vie),atk(force),nom(nom),equipement(),baseAtk(force),baseHp(vie),x(x_coor),y(y_coor)
{
    sf::Texture texture;
    string path("Images/");
    path+=texture_path;
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
}


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

Allie::Allie(std::string nom, int vie, int force, size_t x_coor,size_t y_coor, string texture_path):Personnage(nom,vie,force,x_coor,y_coor,texture_path)
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