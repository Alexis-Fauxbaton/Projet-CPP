#pragma once
#include <iostream>
#include <string>
using namespace std;

class Objet
{
    public:
        Objet():nom(""),hp(0),atk(0){};
        Objet(std::string nom, int vie, int force):nom(nom),hp(vie),atk(force){};
        ~Objet();
        //void afficher(); Implementation avec IMGUI
        void setNom(std::string nom);
        void setHp(int vie);
        void setAtk(int force);
        std::string getNom(){return nom;}
        int getHP(){return hp;}
        int getAtk(){return atk;}

    private://A modifier pour rendre heritage possible si besoin 
        int hp;
        int atk;
        string nom;
        bool estEquipe;
};