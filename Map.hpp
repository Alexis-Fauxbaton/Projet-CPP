#pragma once
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

class Map
{
    public:
        Map(vector<Ennemi> v_ennemis, bool jouee, bool activation, string texture_path, string combat_texture_path);
        ~Map(){};
        void setJouee(bool jouee){jouee_actuellement=jouee;}
        bool getJouee(){return jouee_actuellement;}
        void setActive(bool activation){active=activation;}
        bool getActive(){return active;}
        void setEnnemis(vector<Ennemi> v_ennemis){ennemis=v_ennemis;}
        vector<Ennemi> getEnnemis(){return ennemis;}
        void setSprite(sf::Sprite sprite){this->sprite=sprite;}
        void setSpriteCombat(sf::Sprite sprite){this->sprite_combat=sprite;}
        sf::Sprite getSprite(){return sprite;}
        sf::Sprite getSpriteCombat(){return sprite_combat;}
        void ajouterEnnemi(Ennemi& ennemi){ennemis.push_back(ennemi);}
        void retirerEnnemi(size_t index){ennemis.erase(ennemis.begin()+index);}
        void run();

    private:
        vector<Ennemi> ennemis; //Initialisés aléatoirement ?
        //Ajouter un attribut caractérisant les portes nord sud est ouest 
        //par lesquelles le joueur peut sortir/entrer de la map
        //AJOUTER LARGEUR ET LONGUEUR EN PIXELS
        bool jouee_actuellement;
        bool active;
        sf::Sprite sprite;
        sf::Sprite sprite_combat;
        sf::Texture texture;
        sf::Texture texture_combat;
  
};