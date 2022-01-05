#pragma once
#include <iostream>
#include <string>
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
//#include "Allie.hpp"
using namespace std;

class Equipement;
class Allie;
class Ennemi;
class Objet;
class Arme;
class Armure;
class Mystique;

class Personnage
{
    public:
        Personnage():hp(0),atk(0),nom(""),equipement(),baseAtk(0),baseHp(0){};
        Personnage(std::string nom, int vie, int force):hp(vie),atk(force),nom(nom),equipement(),baseAtk(force),baseHp(vie){};
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


    protected:
        int hp;
        int atk;
        string nom;
        Equipement equipement;
        int baseAtk;
        int baseHp;
        
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





