#pragma once
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Porte.hpp"
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
        Map();
        Map(vector<Ennemi> v_ennemis, string texture_path, string combat_texture_path, string main_sound_path, string combat_sound_path, Porte porte_nord, Porte porte_sud, Map* map_nord, Map* map_sud);
        ~Map(){};
        void setEnnemis(vector<Ennemi> v_ennemis){ennemis=v_ennemis;}
        vector<Ennemi> &getEnnemis(){return ennemis;}
        void setSprite(sf::Sprite sprite){this->sprite=sprite;}
        void setSpriteCombat(sf::Sprite sprite){this->sprite_combat=sprite;}
        void setSpriteCombatPosition(size_t x, size_t y){sprite_combat.setPosition(x,y);}
        sf::Sprite& getSprite(){return sprite;}
        sf::Sprite& getSpriteCombat(){return sprite_combat;}
        sf::Texture& getTexture(){return texture;}
        sf::Texture& getTextureCombat(){return texture_combat;}
        sf::SoundBuffer& getBufferMain(){return buffer_main;}
        sf::SoundBuffer& getBufferCombat(){return buffer_combat;}
        void setPorteNord(Porte porte_nord){this->porte_nord=porte_nord;}
        void setPorteSud(Porte porte_sud){this->porte_sud=porte_sud;}
        Porte getPorteNord(){return porte_nord;}
        Porte getPorteSud(){return porte_sud;}
        void setMapNord(Map* map_nord){this->map_nord=map_nord;}
        void setMapSud(Map* map_sud){this->map_sud=map_sud;}
        Map* getMapNord(){return map_nord;}
        Map* getMapSud(){return map_sud;}
        void ajouterEnnemi(Ennemi& ennemi){ennemis.push_back(ennemi);}
        void retirerEnnemi(size_t index){ennemis.erase(ennemis.begin()+index);}
        void run();

    private:
        vector<Ennemi> ennemis; //Initialisés aléatoirement ?
        //Ajouter un attribut caractérisant les portes nord sud est ouest 
        //par lesquelles le joueur peut sortir/entrer de la map
        //AJOUTER LARGEUR ET LONGUEUR EN PIXELS
        sf::Sprite sprite;
        sf::Sprite sprite_combat;
        sf::Texture texture;
        sf::Texture texture_combat;
        sf::SoundBuffer buffer_main;
        sf::SoundBuffer buffer_combat;
        Porte porte_nord;
        Porte porte_sud;
        Map* map_nord;
        Map* map_sud;
  
};