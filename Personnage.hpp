#pragma once
#include <iostream>
#include <string>
#include "Inventaire.hpp"
using namespace std;



class Personnage
{
    public:
        Personnage():nom(""),hp(0),atk(0){};
        Personnage(std::string nom, int vie, int force):nom(nom),hp(vie),atk(force){};
        ~Personnage();
        //void afficher(); Implementation avec IMGUI
        virtual void attaquer(Personnage &cible)=0;
        void subir(int degats){hp-=degats;};
        void setNom(string nom);
        void setHp(int vie);
        void setAtk(int force);
        string getNom(){return nom;}
        int getHP(){return hp;}
        int getAtk(){return atk;}

    protected:
        int hp;
        int atk;
        string nom;
        
};




class Allie : public Personnage
{

    public:
        Allie(std::string nom, int vie, int force):Personnage(nom,vie,force){};
        void attaquer(Ennemi &cible){cible.subir(this->atk);};

};


class Ennemi : public Personnage
{
    public:
        Ennemi(std::string nom, int vie, int force):Personnage(nom,vie,force){};
        void attaquer(Allie &cible){cible.subir(this->atk);};
};





