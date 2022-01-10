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

Map::Map(vector<Ennemi> v_ennemis, bool jouee, bool activation, string texture_path, string combat_texture_path):ennemis(v_ennemis),jouee_actuellement(jouee),active(activation)
{
    string path("Images/");
    path+=texture_path;
    sf::Texture texture;
    texture.loadFromFile(path);   
    sprite.setTexture(texture);
    path = "Images/";
    path+=combat_texture_path;
    texture.loadFromFile(path);
    sprite_combat.setTexture(texture);
}