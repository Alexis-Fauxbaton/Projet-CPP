#pragma once
#include <iostream>
#include <string>
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include <SFML/Graphics.hpp>
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
        Personnage(std::string nom, int vie, int force, int x_coor, int y_coor,string texture_path);
        Personnage(const Personnage& orig);
        ~Personnage(){};
        virtual void attaquer(Allie &cible)=0;
        virtual void attaquer(Ennemi &cible)=0;
        void subir(int degats){hp-=degats;};
        void setNom(string nom){this->nom=nom;}
        void setHp(int vie){hp=vie;}
        void setAtk(int force){atk=force;}
        string getNom(){return nom;}
        int getHP(){return hp;}
        int getAtk(){return atk;}
        int getBaseHP(){return baseHp;};
        void setEquipement(Equipement& equipement){this->equipement=equipement;}
        Equipement& getEquipement(){return equipement;}
        void appliquerEffetEquipement();
        void ajouterArme(Arme& arme);
        void ajouterArmure(Armure& armure);
        void ajouterMystique(Mystique& mystique);
        void setPosition(size_t x, size_t y){this->x=x;this->y=y;}
        int getX(){return x;}
        int getY(){return y;}
        sf::Sprite& getSprite(){return sprite;}
        sf::Texture getTexture(){return texture;}
        virtual sf::RectangleShape& getLifeBar()=0;
        virtual sf::RectangleShape& getLifeBarBackground()=0;
        bool estProche(Personnage& cible, int distance);
        bool estMort(){return hp<=0;}
        string getTexturePath(){return chemin_texture;};


    protected:
        int hp;
        int atk;
        string nom;
        Equipement equipement;
        int baseAtk;
        int baseHp;
        int x;
        int y;
        sf::Sprite sprite;
        sf::Texture texture;
        string chemin_texture;
        
        
};

class Allie : public Personnage
{

    public:
        Allie():Personnage(){};
        Allie(std::string nom, int vie, int force, int x_coor, int y_coor, string texture_path);
        virtual ~Allie(){};

        sf::RectangleShape& getLifeBar(){return lifebar_perso;};
        sf::RectangleShape& getLifeBarBackground(){return lifebar_background;};
        void attaquer(Ennemi &cible);
        void attaquer(Allie &cible){};
    protected:
        sf::RectangleShape lifebar_perso;
        sf::RectangleShape lifebar_background;

};

class Ennemi : public Personnage
{
    public:
        Ennemi():Personnage(){};
        Ennemi(std::string nom, int vie, int force, int x_coor, int y_coor,string texture_path);
        virtual ~Ennemi(){};

        sf::RectangleShape& getLifeBar(){return lifebar_perso;};
        sf::RectangleShape& getLifeBarBackground(){return lifebar_background;};
        void setPrisonnier(Allie &allie);
        Allie &getPrisonnier(){return prisonnier;};
        bool getloot_allie(){return loot_allie;};

        void attaquer(Allie &cible);
        void attaquer(Ennemi &cible){};
    protected:
        sf::RectangleShape lifebar_perso;
        sf::RectangleShape lifebar_background;
        bool loot_allie;
        Allie prisonnier;
        

    
        
};

class Maitre : public Personnage
{
    public:
        Maitre():Personnage(){};
        Maitre(std::string nom, int vie, int force, int x_coor, int y_coor,string texture_path):Personnage(nom,vie,force,x_coor,y_coor,texture_path){};
        virtual ~Maitre(){};

        vector<Allie> getAllAllies(){return perso_allies;};
        Allie& getAllie(size_t indice){return perso_allies[indice];};
        void setAllAllies(vector<Allie>& allies){perso_allies=allies;};

        void addAllie(Allie &allie){perso_allies.push_back(allie);};
        void attaquer(Allie &cible){};
        void attaquer(Ennemi &cible){};
        sf::RectangleShape& getLifeBar(){return lifebar_perso;};
        sf::RectangleShape& getLifeBarBackground(){return lifebar_background;};


    protected:
        vector<Allie> perso_allies;
        sf::RectangleShape lifebar_perso;
        sf::RectangleShape lifebar_background;

};



