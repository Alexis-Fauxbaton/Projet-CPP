#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
using namespace std;

class Objet
{
    public:
        Objet();
        Objet(std::string nom, int vie, int force, int defense, bool equipe,string texture_path);
        ~Objet(){};
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
        sf::Sprite &getSprite(){return sprite_objet;};
        sf::Texture &getTexture(){return texture_objet;};
        string getTexturePath(){return chemin_texture;};
        Objet operator=(const Objet &objet);

    protected:
        int hp;
        int atk;
        int def;
        string nom;
        bool estEquipe;
        sf::Sprite sprite_objet;
        sf::Texture texture_objet;
        string chemin_texture;
};


class Arme : public Objet
{
    public:
        Arme():Objet(){};
        Arme(std::string nom, int vie, int force, int defense, bool equipe,string texture_path):Objet(nom,vie,force,defense,equipe,texture_path){};
        ~Arme(){};

};


class Armure : public Objet
{
    public:
        Armure():Objet(){};
        Armure(std::string nom, int vie, int force,int defense, bool equipe,string texture_path):Objet(nom,vie,force,defense,equipe,texture_path){};
        ~Armure(){};

};


class Mystique : public Objet

{
    public:
        Mystique():Objet(){};
        Mystique(std::string nom, int vie, int force, int defense, bool equipe,string texture_path):Objet(nom,vie,force,defense,equipe,texture_path){};
        ~Mystique(){};

};