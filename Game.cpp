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
    Map* map_actuelle = &maps[0];
    bool switched = true;
    int map_index = 0;
    int combat_index = 0;
    int new_x = 0;
    int new_y = 0;
    vector<Ennemi> ennemis;
    /*for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }*/

    Maitre joueur("Poubelle",100,50,100,340,"Images/poubelle2.png");
    
    sf::Sprite sprite_joueur = joueur.getSprite();



    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    bool en_combat = false;                         


    // Creation des allies

    Allie poubelle("Poubelle",100,40,360,240,"Images/poubelle2.png");
    Allie eolienne("Eolienne",100,40,220,240,"Images/wind-turbine.png");
    Allie panneau("Panneau",100,40,580,240,"Images/solar-pannel.png");

    joueur.addAllie(poubelle);
    joueur.addAllie(eolienne);
    joueur.addAllie(panneau);

    


    // Creation du texte de combat

    

    // Item sprite

    sf::Texture armure_texture;
    armure_texture.loadFromFile("Images/épée_4.png");
    sf::Sprite armure_sprite(armure_texture);
    armure_sprite.setPosition(250,200);

    Arme epee1("épée 1",0,20,0,true,"Images/épée_1.png");

    joueur.getAllie(0).getEquipement().setArme(epee1);
    joueur.getAllie(0).getEquipement().getArme().getSprite().setPosition(300,200);
    

    cout << "ICI2" << endl;

    sf::SoundBuffer default_buffer;
    default_buffer.loadFromFile("Sound/pokemon_eterna_forest.wav");

    sf::Sound music(default_buffer);
    music.setLoop(true);
    music.play();

    sf::Sound music_combat(map_actuelle->getBufferCombat());

    while(1)
    {
        if (switched)
        {
            if (music.getBuffer()->getDuration() != map_actuelle->getBufferMain().getDuration())
            {
                music.setBuffer(map_actuelle->getBufferMain());
                music.setLoop(true);
                music.play();
            }
            ennemis = map_actuelle->getEnnemis();
            switched = false;
        }

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
                    if (event.key.code == sf::Keyboard::Up && joueur.getY() >= 10)
                    {
                        joueur.setPosition(joueur.getX(),joueur.getY()-10);
                    }
                    else if (event.key.code == sf::Keyboard::Down && joueur.getY() <= 589)
                    {
                        joueur.setPosition(joueur.getX(),joueur.getY()+10);
                    }
                    else if (event.key.code == sf::Keyboard::Left && joueur.getX() >= 10)
                    {
                        joueur.setPosition(joueur.getX()-10,joueur.getY());
                    }
                    else if (event.key.code == sf::Keyboard::Right && joueur.getX() <= 789)
                    {
                        joueur.setPosition(joueur.getX()+10,joueur.getY());
                    }
                    sprite_joueur.setPosition(joueur.getX(),joueur.getY());                }
            }
            
        }
        if(en_combat)
        {

            music.stop();
            music_combat.setLoop(true);
            music_combat.play();
            cout << "Map position 1 " <<map_actuelle->getSpriteCombat().getPosition().x << map_actuelle->getSpriteCombat().getPosition().y << endl;
            map_actuelle->getSpriteCombat().setPosition(20,20);
            cout << "Map position 2 " <<map_actuelle->getSpriteCombat().getPosition().x << map_actuelle->getSpriteCombat().getPosition().y << endl;
            Combat combat(joueur,ennemis[combat_index],maps[map_index]);
            if (combat.commencer(window,music_combat))
            {
                ennemis.erase(ennemis.begin()+combat_index);
                
                

            }
            else{
                // Cas ou on perd
            }
            music.play();
            en_combat = false;
            

        }
        else
        {
            
            //SUITE D'INSTRUCTIONS POUR LE JEU HORS COMBAT
            
            //CHECK SI LE JOUEUR EST SUR LA PORTE NORD

            if (map_actuelle->getPorteNord().entre(joueur.getX(),joueur.getY()) && map_actuelle->getMapNord() != NULL)
            {
                map_actuelle = map_actuelle->getMapNord();
                new_x = (map_actuelle->getPorteSud().getX2() + map_actuelle->getPorteSud().getX1())/2;
                new_y = map_actuelle->getPorteSud().getY1()-20;
                joueur.setPosition(new_x,new_y);
                sprite_joueur.setPosition(joueur.getX(),joueur.getY());
                switched = true;
            }

            //CHECK SI LE JOUEUR EST SUR LA PORTE SUD

            if (map_actuelle->getPorteSud().entre(joueur.getX(),joueur.getY()) && map_actuelle->getMapSud() != NULL)
            {
                map_actuelle = map_actuelle->getMapSud();
                new_x = (map_actuelle->getPorteNord().getX2() + map_actuelle->getPorteNord().getX1())/2;
                new_y = map_actuelle->getPorteNord().getY1()+20;
                joueur.setPosition(new_x,new_y);
                sprite_joueur.setPosition(joueur.getX(),joueur.getY());
                switched = true;
            }
            
            for (size_t i = 0;i<ennemis.size();i++)
            {
                if (joueur.estProche(ennemis[i],10))
                {
                    cout << "Ennemi " << i << " est proche" << endl;
                    cout << "joueur" << joueur.getX() << " " << joueur.getY() << endl;
                    cout << "Ennemi" << ennemis[i].getX() << " " << ennemis[i].getY() << endl;
                    en_combat = true;
                    combat_index = i;
                    break;
                }
            }



            window.clear();
            window.draw(map_actuelle->getSprite());
            for (size_t i=0;i<ennemis.size();i++)
            {
                window.draw(ennemis[i].getSprite());
            }
            window.draw(epee1.getSprite());
            window.draw(sprite_joueur);
            
            
            // window.draw();
            window.display();
        }
    }
}