#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Combat.hpp"
#include "Map.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

Combat::Combat(Allie &_P1, Ennemi &_P2,Map& _map)
{
    perso1 = _P1;
    perso2 = _P2;
    map = _map;
}


void Combat::commencer(sf::RenderWindow &window){

    sf::Texture texture_perso1 = perso1.getTexture();
    sf::Texture texture_perso2 = perso2.getTexture();
    sf::Texture texture_map = map.getTextureCombat();
    sf::Image image_perso1 = texture_perso1.copyToImage();
    sf::Image image_perso2 = texture_perso2.copyToImage();

    sf::Sprite sprite_perso1(texture_perso1);
    sprite_perso1.setPosition(100,340);
    sf::Sprite sprite_perso2(texture_perso2);
    sprite_perso2.setPosition(150,340);
    sf::Sprite sprite_map(texture_map);

    while(1){

        //std::cout << "map sprite position :" << map.getSpriteCombat().getPosition().x << map.getSpriteCombat().getPosition().y << std::endl; 

        window.clear();
        window.draw(sprite_map);
        window.draw(sprite_perso1);
        window.draw(sprite_perso2);
        window.display();
        //std::cout << "voucle inf" << std::endl;

    }
}