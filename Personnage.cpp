#include <iostream>
#include <string>
#include "Personnage.hpp"
#include "Equipement.hpp"
//#include "Allie.hpp"
using namespace std;

int v_abs(int a){
    if (a<0)
        return -a;
    else
        return a;
}

Personnage::Personnage():hp(0),atk(0),nom(""),equipement(),baseAtk(0),baseHp(0),x(0),y(0)
{
    sf::Texture texture;
    texture.loadFromFile("Images/poubelle2.png");
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
}

Personnage::Personnage(std::string nom, int vie, int force, int x_coor, int y_coor, string texture_path):hp(vie),atk(force),nom(nom),equipement(),baseAtk(force),baseHp(vie),x(x_coor),y(y_coor),chemin_texture(texture_path)
{
    texture.loadFromFile(texture_path);
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
}

Personnage::Personnage(const Personnage& orig):hp(orig.hp),atk(orig.atk),nom(orig.nom),equipement(orig.equipement),baseAtk(orig.baseAtk),baseHp(orig.baseHp),x(orig.x),y(orig.y)
{
    texture = orig.texture;
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
}

void Personnage::appliquerEffetEquipement()
{
    atk=baseAtk+equipement.getArme().getAtk()+equipement.getArmure().getAtk()+equipement.getMystique().getAtk();

    hp=hp+equipement.getArmure().getHP()+equipement.getMystique().getHP()+equipement.getArme().getHP();
    baseHp = baseHp + equipement.getArmure().getHP()+equipement.getMystique().getHP()+equipement.getArme().getHP();

    this->getLifeBar().setSize(sf::Vector2f(this->getHP()/2,5));
    this->getLifeBarBackground().setSize(sf::Vector2f(this->getBaseHP()/2,5));
    
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

    
bool Personnage::estProche(Personnage& cible, int distance)
{
    int a = static_cast<int>(x - cible.getX());
    int b = static_cast<int>(y - cible.getY());
    if(v_abs(a)<=distance && v_abs(b)<=distance)
    {
        return true;
    }
    return false;
}

Allie::Allie(std::string nom, int vie, int force, int x_coor, int y_coor, string texture_path):Personnage(nom,vie,force,x_coor,y_coor,texture_path)
{
    sf::RectangleShape bar_de_vie;
    lifebar_perso = bar_de_vie;
    lifebar_perso.setFillColor(sf::Color::Red);
    lifebar_perso.setPosition(150,230);
    lifebar_perso.setSize(sf::Vector2f(50,5));
    lifebar_background.setFillColor(sf::Color::Black);
    lifebar_background.setPosition(150,230);
    lifebar_background.setSize(sf::Vector2f(50,5));
}

void Allie::attaquer(Ennemi &cible)
{
    cible.subir(this->atk);
}

Ennemi::Ennemi(std::string nom, int vie, int force, int x_coor, int y_coor, string texture_path):Personnage(nom,vie,force,x_coor,y_coor,texture_path)
{
    lifebar_perso.setFillColor(sf::Color::Red);
    lifebar_perso.setPosition(150,230);
    lifebar_perso.setSize(sf::Vector2f(50,5));
    lifebar_background.setFillColor(sf::Color::Black);
    lifebar_background.setPosition(150,230);
    lifebar_background.setSize(sf::Vector2f(50,5));
    loot_allie = false;
}


void Ennemi::attaquer(Allie &cible)
{
    cible.subir(this->atk);
}

void Ennemi::setPrisonnier(Allie &allie){

    prisonnier = allie;
    prisonnier.getTexture().loadFromFile(allie.getTexturePath());
    prisonnier.getSprite().setTexture(prisonnier.getTexture());
    loot_allie = true;

}