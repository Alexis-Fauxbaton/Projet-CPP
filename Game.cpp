#include "Game.hpp"
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Map.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

void Game::run(vector<Map> maps)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    bool en_combat = false;
    while(1)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
        }
        if(en_combat)
        {
            window.clear();
            window.draw(maps[0].getSpriteCombat());
            //SUITE D'INSTRUCTIONS POUR LE COMBAT
            window.display();
        }
        else
        {
            window.clear();
            window.draw(maps[0].getSprite());
            //SUITE D'INSTRUCTIONS POUR LE JEU HORS COMBAT
            window.display();
        }
    }
}