#pragma once
#include <iostream>
#include <string>
#include "Inventaire.hpp"
#include "Equipement.hpp"
//#include "Allie.hpp"
using namespace std;

class Equipement;
class Allie;
class Ennemi;

class Personnage
{
    public:
        Personnage():nom(""),hp(0),atk(0){};
        Personnage(std::string nom, int vie, int force):nom(nom),hp(vie),atk(force){};
        ~Personnage(){};
        //void afficher(); Implementation avec IMGUI
        virtual void attaquer(Allie &cible)=0;
        virtual void attaquer(Ennemi &cible)=0;
        void subir(int degats){hp-=degats;};
        void setNom(string nom);
        void setHp(int vie);
        void setAtk(int force);
        string getNom(){return nom;}
        int getHP(){return hp;}
        int getAtk(){return atk;}
        Equipement& getEquipement(){return equipement;}

    protected:
        int hp;
        int atk;
        string nom;
        Equipement equipement;
        
};



class Allie : public Personnage
{

    public:
        Allie(std::string nom, int vie, int force);
        void attaquer(Ennemi &cible);
        void attaquer(Allie &cible){};

};

class Ennemi : public Personnage
{
    public:
        Ennemi(std::string nom, int vie, int force):Personnage(nom,vie,force){};
        void attaquer(Allie &cible);
        void attaquer(Ennemi &cible){};
};





