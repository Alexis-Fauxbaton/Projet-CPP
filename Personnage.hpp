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
        Personnage(const Personnage& orig);
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
        sf::Sprite& getSprite(){return sprite;}
        sf::Texture getTexture(){return texture;}
        bool estProche(Personnage& cible, int distance);
        bool estMort(){return hp<=0;}


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
        Allie():Personnage(){};
        Allie(std::string nom, int vie, int force, size_t x_coor, size_t y_coor, string texture_path);

        sf::RectangleShape& getLifeBar(){return lifebar_perso;};
        void attaquer(Ennemi &cible);
        void attaquer(Allie &cible){};
    
    protected:
        sf::RectangleShape lifebar_perso;

};

class Ennemi : public Personnage
{
    public:
        Ennemi():Personnage(){};
        Ennemi(std::string nom, int vie, int force, size_t x_coor, size_t y_coor,string texture_path);

        sf::RectangleShape& getLifeBar(){return lifebar_perso;};

        void attaquer(Allie &cible);
        void attaquer(Ennemi &cible){};

    protected:
        sf::RectangleShape lifebar_perso;
};

class Maitre : public Personnage
{
    public:
        Maitre():Personnage(){};
        Maitre(std::string nom, int vie, int force, size_t x_coor, size_t y_coor,string texture_path):Personnage(nom,vie,force,x_coor,y_coor,texture_path){};

        vector<Allie> getAllAllies(){return perso_allies;};
        Allie& getAllie(size_t indice){return perso_allies[indice];};

        void addAllie(Allie &allie){perso_allies.push_back(allie);};
        void attaquer(Allie &cible){};
        void attaquer(Ennemi &cible){};


    protected:
        vector<Allie> perso_allies;

};



