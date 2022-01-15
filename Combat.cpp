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

Combat::Combat(Maitre &_P1, Ennemi &_P2,Map& _map)
{
    perso1 = _P1;
    perso2 = _P2;
    map = _map;
}


void Combat::commencer(sf::RenderWindow &window){

    window.create(sf::VideoMode(800, 400), "Combat");

    sf::Texture texture_perso1 = perso1.getTexture();
    sf::Texture texture_perso2 = perso2.getTexture();
    sf::Texture texture_map = map.getTextureCombat();
    sf::Image image_perso1 = texture_perso1.copyToImage();
    sf::Image image_perso2 = texture_perso2.copyToImage();
               
    // Positionnement allies Personnages

    perso1.getSprite().setPosition(100,240);
    perso2.getSprite().setPosition(650,240);

    // for(size_t i;i<perso1.getAllAllies().size();i++){
    //     perso1.getAllie(i).setPosition(perso1.getX()+(i+1)*50,perso1.getY());
    // }

    
    sf::Sprite sprite_map(texture_map);

    // Bar de vies et menus


    perso2.getLifeBar().setFillColor(sf::Color::Red);
    perso2.getLifeBar().setPosition(650,245);
    perso2.getLifeBar().setSize(sf::Vector2f(50,5));

    cout << "lifebar position x : " << perso2.getLifeBar().getPosition().x << endl;

    sf::Texture texture_combat_action_menu;
    sf::Sprite sprite_combat_action_menu;
    texture_combat_action_menu.loadFromFile("Images/combat_action_menu.png");
    sprite_combat_action_menu.setTexture(texture_combat_action_menu);
    sprite_combat_action_menu.setPosition(100,30);



    //TEXTE MENU

    sf::Font font_game;
    font_game.loadFromFile("Fonts/game_font.TTF");

    sf::Text text1("PRESS 1",font_game,8);
    text1.setPosition(20,55);
    sf::Text text2("PRESS 2",font_game,8);
    text2.setPosition(20,75);
    sf::Text text3("PRESS 3",font_game,8);
    text3.setPosition(20,95);
    sf::Text text4("PRESS 4",font_game,8);
    text4.setPosition(20,115);

    while(1){

        //std::cout << "map sprite position :" << map.getSpriteCombat().getPosition().x << map.getSpriteCombat().getPosition().y << std::endl; 

        window.clear();
        window.draw(sprite_map);
        window.draw(perso1.getSprite());
        window.draw(perso2.getSprite());
        window.draw(perso2.getLifeBar());
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(sprite_combat_action_menu);
        
        // for(size_t i;i<perso1.getAllAllies().size();i++){
        //     window.draw(perso1.getAllie(i).getSprite());
        // }


        window.display();
        //std::cout << "voucle inf" << std::endl;

    }
}