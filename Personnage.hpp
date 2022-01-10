#pragma once
#include <iostream>
#include <string>
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include <SFML/Graphics.hpp>
//#include "Allie.hpp"
using namespace std;

class Equipement;
class Allie;
class Ennemi;
class Objet;
class Arme;
class Armure;
class Mystique;

int v_abs(int a);

class Personnage
{
    public:
        Personnage();
        Personnage(std::string nom, int vie, int force, size_t x_coor, size_t y_coor,string texture_path);
        ~Personnage(){};
        //void afficher(); Implementation avec IMGUI
        virtual void attaquer(Allie &cible)=0;
        virtual void attaquer(Ennemi &cible)=0;
        void subir(int degats){hp-=degats;};
        void setNom(string nom){this->nom=nom;}
        void setHp(int vie){hp=vie;}
        void setAtk(int force){atk=force;}
        string getNom(){return nom;}
        int getHP(){return hp;}
        int getAtk(){return atk;}
        Equipement& getEquipement(){return equipement;}
        void appliquerEffetEquipement();
        void ajouterArme(Arme& arme);
        void ajouterArmure(Armure& armure);
        void ajouterMystique(Mystique& mystique);
        void setPosition(size_t x, size_t y){this->x=x;this->y=y;}
        size_t getX(){return x;}
        size_t getY(){return y;}
        sf::Sprite getSprite(){return sprite;}
        bool estProche(Personnage& cible, int distance);


    protected:
        int hp;
        int atk;
        string nom;
        Equipement equipement;
        int baseAtk;
        int baseHp;
        size_t x;
        size_t y;
        sf::Sprite sprite;
        sf::Texture texture;
        
};



class Allie : public Personnage
{

    public:
        Allie(std::string nom, int vie, int force, size_t x_coor, size_t y_coor, string texture_path);
        void attaquer(Ennemi &cible);
        void attaquer(Allie &cible){};

};

class Ennemi : public Personnage
{
    public:
        Ennemi(std::string nom, int vie, int force, size_t x_coor, size_t y_coor,string texture_path):Personnage(nom,vie,force,x_coor,y_coor,texture_path){};
        void attaquer(Allie &cible);
        void attaquer(Ennemi &cible){};
};





