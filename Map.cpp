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

Map::Map():ennemis(),sprite(sf::Sprite()),sprite_combat(sf::Sprite()),texture(sf::Texture()),texture_combat(sf::Texture()),buffer_main(sf::SoundBuffer()),buffer_combat(sf::SoundBuffer()),porte_nord(Porte()),porte_sud(Porte()),map_nord(NULL),map_sud(NULL),obstacles(){}

Map::Map(vector<Ennemi> v_ennemis, string texture_path, string combat_texture_path, string main_sound_path, string combat_sound_path, Porte porte_nord, Porte porte_sud, Map* map_nord, Map* map_sud, vector<Obstacle> v_obstacles):ennemis(v_ennemis),porte_nord(porte_nord),porte_sud(porte_sud),map_nord(map_nord),map_sud(map_sud),obstacles(v_obstacles)
{
    texture.loadFromFile(texture_path);   
    sprite.setTexture(texture);
    texture_combat.loadFromFile(combat_texture_path);
    sprite_combat.setTexture(texture_combat);
    setSpriteCombatPosition(ennemis.size(),ennemis.size());
    buffer_main.loadFromFile(main_sound_path);
    buffer_combat.loadFromFile(combat_sound_path);
    
}