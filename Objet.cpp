#include <iostream>
#include <string>
#include "Objet.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
using namespace std;


Objet::Objet(std::string nom, int vie, int force, int defense, bool equipe,string texture_path):hp(vie),atk(force),def(defense),nom(nom),estEquipe(equipe),chemin_texture(texture_path){

    texture_objet.loadFromFile(texture_path);   
    sprite_objet.setTexture(texture_objet);
}

Objet Objet::operator=(const Objet& objet)
{
    nom=objet.nom;
    hp=objet.hp;
    atk=objet.atk;
    def=objet.def;
    estEquipe=objet.estEquipe;
    return *this;
}