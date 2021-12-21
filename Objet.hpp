#pragma once
#include <iostream>
#include <string>
using namespace std;

class Objet
{
    public:
        Objet():nom(""),hp(0),atk(0){};
        Objet(std::string nom, int vie, int force, int defense, bool equipe):nom(nom),hp(vie),atk(force),def(defense),estEquipe(equipe){};
        ~Objet();
        //void afficher(); Implementation avec IMGUI
        void setNom(std::string name){nom=name;}
        void setHp(int vie){hp=vie;}
        void setAtk(int force){atk=force;}
        void setDef(int defense){def=defense;}
        void setEquipe(bool equipe){estEquipe=equipe;}
        std::string getNom(){return nom;}
        int getHP(){return hp;}
        int getAtk(){return atk;}
        int getDef(){return def;}
        bool getEquipe(){return estEquipe;}
        Objet operator=(const Objet &objet);

    private://A modifier pour rendre heritage possible si besoin 
        int hp;
        int atk;
        int def;
        string nom;
        bool estEquipe;
};

class Arme : public Objet
{
    public:
        Arme():Objet(){};
        Arme(std::string nom, int vie, int force, int defense, bool equipe):Objet(nom,vie,force,defense,equipe){};
        ~Arme();        

};

class Armure : public Objet
{
    public:
        Armure():Objet(){};
        Armure(std::string nom, int vie, int force,int defense, bool equipe):Objet(nom,vie,force,defense,equipe){};
        ~Armure();

};

class Mystique : public Objet

{
    public:
        Mystique():Objet(){};
        Mystique(std::string nom, int vie, int force, int defense, bool equipe):Objet(nom,vie,force,defense,equipe){};
        ~Mystique();

};