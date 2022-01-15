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
#include "Map.hpp"

using namespace std;

Map::Map():ennemis(),jouee_actuellement(false),active(false),sprite(sf::Sprite()),sprite_combat(sf::Sprite()),texture(sf::Texture()),texture_combat(sf::Texture())
{
    cout << "Constructeur Map" << endl;
}

Map::Map(vector<Ennemi> v_ennemis, bool jouee, bool activation, string texture_path, string combat_texture_path):ennemis(v_ennemis),jouee_actuellement(jouee),active(activation)
{
    texture.loadFromFile(texture_path);   
    sprite.setTexture(texture);
    texture_combat.loadFromFile(combat_texture_path);
    sprite_combat.setTexture(texture_combat);
    setSpriteCombatPosition(ennemis.size(),ennemis.size());
}