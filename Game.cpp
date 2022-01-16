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
    bool switched = true;
    int map_index = 0;
    int combat_index = 0;
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

    Allie poubelle("Poubelle",100,10,200,250,"Images/poubelle2.png");
    //poubelle.setPosition(150,650);  
    vector<Allie> vector_poubelle;
    vector_poubelle.push_back(Allie("Poubelle",100,10,600,500,"Images/poubelle2.png"));
    vector_poubelle.push_back(poubelle);
    cout << "ICI1" << endl;

    //joueur.addAllie(poubelle);
    



    // cout << "NAME 0" << joueur.getAllie(0).getNom() << endl;
    // joueur.addAllie(Allie("Eolienne",100,10,250,230,"Images/wind-turbine.png"));
    // joueur.addAllie(Allie("Panneau",100,10,300,230,"Images/solar-pannel.png"));

    // sf::Sprite Sprite_poubelle = joueur.getAllie(0).getSprite();
    // Creation des bars de vie

    

    // Creation des items

    Arme epee_perso("Epée",0,20,0,true,"Images/épée_1.png");
    sf::Sprite sprite_arme_perso = epee_perso.getSprite();

    // Creation du texte de combat

    

    // Item sprite

    sf::Sprite spirte_arme_perso = joueur.getEquipement().getArme().getSprite();

    cout << "ICI2" << endl;

    sf::Sound music;

    while(1)
    {
        if (switched)
        {
            music.setBuffer(maps[map_index].getBufferMain());
            ennemis = maps[map_index].getEnnemis();
            music.setLoop(true);
            music.play();
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
                    if (event.key.code == sf::Keyboard::Up && joueur.getY() > 0)
                    {
                        joueur.setPosition(joueur.getX(),joueur.getY()-10);
                    }
                    else if (event.key.code == sf::Keyboard::Down && joueur.getY() < 599)
                    {
                        joueur.setPosition(joueur.getX(),joueur.getY()+10);
                    }
                    else if (event.key.code == sf::Keyboard::Left && joueur.getX() > 0)
                    {
                        joueur.setPosition(joueur.getX()-10,joueur.getY());
                    }
                    else if (event.key.code == sf::Keyboard::Right && joueur.getX() < 799)
                    {
                        joueur.setPosition(joueur.getX()+10,joueur.getY());
                    }
                    sprite_joueur.setPosition(joueur.getX(),joueur.getY());
                }
            }
            
        }
        if(en_combat)
        {
            music.setBuffer(maps[0].getBufferCombat());
            music.setLoop(true);
            music.play();
            cout << "Map position 1 " <<maps[map_index].getSpriteCombat().getPosition().x << maps[map_index].getSpriteCombat().getPosition().y << endl;
            maps[0].getSpriteCombat().setPosition(20,20);
            cout << "Map position 2 " <<maps[map_index].getSpriteCombat().getPosition().x << maps[map_index].getSpriteCombat().getPosition().y << endl;
            Combat combat(joueur,ennemis[combat_index],maps[map_index]);
            if (combat.commencer(window))
                return;

            en_combat = false;
        }
        else
        {
            
            //SUITE D'INSTRUCTIONS POUR LE JEU HORS COMBAT
            
            
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
            window.draw(maps[map_index].getSprite());
            for (size_t i=0;i<ennemis.size();i++)
            {
                window.draw(ennemis[i].getSprite());
            }
            window.draw(sprite_joueur);
            
            window.draw(vector_poubelle[0].getSprite());
            window.display();
        }
    }
}