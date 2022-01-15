#include "Game.hpp"
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Map.hpp"
#include "Combat.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using namespace std;

void Game::run(vector<Map> maps)
{
    vector<Ennemi> ennemis;
    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }

    Allie perso("Poubelle",100,50,100,340,"Images/poubelle2.png");
    sf::Sprite sprite_perso = perso.getSprite();
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Sound/pokemon_eterna_forest.wav");
    sf::Sound sound(buffer);
    sound.setLoop(true);
    sound.play();
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
            if(event.type == sf::Event::KeyPressed)
            {
                if (!en_combat)
                {
                    if (event.key.code == sf::Keyboard::Up && perso.getY() > 0)
                    {
                        perso.setPosition(perso.getX(),perso.getY()-10);
                    }
                    else if (event.key.code == sf::Keyboard::Down && perso.getY() < 599)
                    {
                        perso.setPosition(perso.getX(),perso.getY()+10);
                    }
                    else if (event.key.code == sf::Keyboard::Left && perso.getX() > 0)
                    {
                        perso.setPosition(perso.getX()-10,perso.getY());
                    }
                    else if (event.key.code == sf::Keyboard::Right && perso.getX() < 799)
                    {
                        perso.setPosition(perso.getX()+10,perso.getY());
                    }
                    sprite_perso.setPosition(perso.getX(),perso.getY());
                }
            }
            
        }
        if(en_combat)
        {
            cout << "Map position 1 " <<maps[0].getSpriteCombat().getPosition().x << maps[0].getSpriteCombat().getPosition().y << endl;
            maps[0].getSpriteCombat().setPosition(20,20);
            cout << "Map position 2 " <<maps[0].getSpriteCombat().getPosition().x << maps[0].getSpriteCombat().getPosition().y << endl;
            Combat combat(perso,ennemis[0],maps[0]);
            combat.commencer(window);
            /* BON CODE
            window.clear();
            window.draw(maps[0].getSpriteCombat());
            //SUITE D'INSTRUCTIONS POUR LE COMBAT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                en_combat = false;
            }
            window.display();*/
            en_combat = false;
        }
        else
        {
            window.clear();
            window.draw(maps[0].getSprite());
            //SUITE D'INSTRUCTIONS POUR LE JEU HORS COMBAT
            
            
            for (size_t i = 0;i<ennemis.size();i++)
            {
                if (perso.estProche(ennemis[i],10))
                {
                    cout << "Ennemi " << i << " est proche" << endl;
                    cout << "Perso" << perso.getX() << " " << perso.getY() << endl;
                    cout << "Ennemi" << ennemis[i].getX() << " " << ennemis[i].getY() << endl;
                    en_combat = true;
                    break;
                }
            }


            for (size_t i=0;i<ennemis.size();i++)
            {
                window.draw(ennemis[i].getSprite());
            }
            window.draw(sprite_perso);
            window.display();
        }
    }
}