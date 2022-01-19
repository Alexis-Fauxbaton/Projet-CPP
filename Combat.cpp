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
#include <unistd.h>



void attaquer_animation(Allie &allie,Ennemi &ennemi,sf::RenderWindow &window,Maitre &perso1,Map &maps){


   int initial_allie_position = allie.getSprite().getPosition().x;
    while(abs(allie.getSprite().getPosition().x - ennemi.getSprite().getPosition().x)>10){

         allie.getSprite().setPosition(allie.getSprite().getPosition().x+3,allie.getSprite().getPosition().y);
         //  cout << "ANIMATION COMBAT : " << allie.getSprite().getPosition().x << endl;

         window.draw(maps.getSpriteCombat());
         window.draw(perso1.getSprite());
         window.draw(ennemi.getSprite());
         window.draw(ennemi.getLifeBarBackground());
         window.draw(ennemi.getLifeBar());

         for(size_t i = 0;i<perso1.getAllAllies().size();i++){
             if(perso1.getAllie(i).getNom() != allie.getNom()){
                 window.draw(perso1.getAllie(i).getSprite());
                 window.draw(perso1.getAllie(i).getLifeBarBackground());
                 window.draw(perso1.getAllie(i).getLifeBar());
                 
             }
         }
         window.draw(allie.getSprite());
         window.display();
         window.clear();
    }


    sf::SoundBuffer default_buffer;
    default_buffer.loadFromFile("Sound/attack-sound-effect-new-yorker (mp3cut.net).wav");
    sf::Sound music(default_buffer);

    music.play();
    sleep(1);
    allie.attaquer(ennemi);
    ennemi.getLifeBar().setSize(sf::Vector2f(ennemi.getHP()/2,5));


    while(abs(allie.getSprite().getPosition().x - initial_allie_position)>=3){
        allie.getSprite().setPosition(allie.getSprite().getPosition().x-3,allie.getSprite().getPosition().y);

        window.draw(maps.getSpriteCombat());
         window.draw(perso1.getSprite());
         window.draw(ennemi.getSprite());
         window.draw(ennemi.getLifeBarBackground());
         window.draw(ennemi.getLifeBar());
         
         for(size_t i = 0;i<perso1.getAllAllies().size();i++){
             if(perso1.getAllie(i).getNom() != allie.getNom()){
                 window.draw(perso1.getAllie(i).getSprite());
                 window.draw(perso1.getAllie(i).getLifeBarBackground());
                 window.draw(perso1.getAllie(i).getLifeBar());
                
             }
         }
         window.draw(allie.getSprite());
         window.display();
         window.clear();

    }
    
    
    
}




using namespace std;

Combat::Combat(Maitre &_P1, Ennemi &_P2,Map& _map)
{
    perso1 = _P1;
    perso2 = _P2;
    map = _map;
}


bool Combat::commencer(sf::RenderWindow &window){

    window.create(sf::VideoMode(800, 400), "Combat");

    sf::Texture texture_map = map.getTextureCombat();
    sf::Sprite sprite_map(texture_map);
    
               
    // Positionnement allies Personnages

    perso1.getSprite().setPosition(100,240);
    perso2.getSprite().setPosition(650,240);                 
    cout << perso1.getSprite().getPosition().x << endl;

    for(size_t i=0;i < perso1.getAllAllies().size();i++){
        perso1.getAllie(i).getSprite().setPosition(sf::Vector2f(perso1.getSprite().getPosition().x+60*(i+1),perso1.getSprite().getPosition().y));
    }
                   
    // perso1.getAllie(0).getSprite().setPosition(500,100);
    cout << perso1.getAllie(0).getSprite().getPosition().x << endl;

    // Bar de vies et menus       

    for(size_t i= 0;i<perso1.getAllAllies().size();i++){
        perso1.getAllie(i).getLifeBar().setFillColor(sf::Color::Red);
        perso1.getAllie(i).getLifeBar().setPosition(perso1.getAllie(i).getSprite().getPosition().x,perso1.getAllie(i).getSprite().getPosition().y-10);
        perso1.getAllie(i).getLifeBarBackground().setPosition(perso1.getAllie(i).getSprite().getPosition().x,perso1.getAllie(i).getSprite().getPosition().y-10);
    }


    perso2.getLifeBar().setFillColor(sf::Color::Red);
    perso2.getLifeBar().setPosition(650,245);
    perso2.getLifeBar().setSize(sf::Vector2f(50,5));
    perso2.getLifeBarBackground().setPosition(perso2.getLifeBar().getPosition().x,perso2.getLifeBar().getPosition().y);

    cout << "lifebar position x : " << perso2.getLifeBar().getPosition().x << endl;

    sf::Texture texture_combat_action_menu;
    sf::Sprite sprite_combat_action_menu;
    texture_combat_action_menu.loadFromFile("Images/combat_action_menu.png");
    sprite_combat_action_menu.setTexture(texture_combat_action_menu);
    sprite_combat_action_menu.setPosition(100,30);



    //TEXTE MENU

    sf::Font font_game;
    font_game.loadFromFile("Fonts/game_font.TTF");

    //Phase 0

    sf::Text phase_0_press1("PRESS 1",font_game,8);
    phase_0_press1.setPosition(20,55);
    sf::Text phase_0_press2("PRESS 2",font_game,8);
    phase_0_press2.setPosition(20,75);
    sf::Text phase_0_press3("PRESS 3",font_game,8);
    phase_0_press3.setPosition(20,95);
    sf::Text phase_0_press4("PRESS 4",font_game,8);
    phase_0_press4.setPosition(20,115);
    

    //Phase 01

    sf::Text phase_01_choose("Choisissez un personnage pour attaquer : ",font_game,10);
    phase_01_choose.setFillColor(sf::Color::Black);
    phase_01_choose.setPosition(20,50);
    sf::Text phase_01_nom("vide",font_game,8);
    phase_01_nom.setFillColor(sf::Color::Black);

    Allie poubelle2("Poubelle",100,10,50,50,"Images/poubelle2.png");


    string phases = "0";
    
    
    

    while(1){

        //std::cout << "map sprite position :" << map.getSpriteCombat().getPosition().x << map.getSpriteCombat().getPosition().y << std::endl; 

        sf::Event event_combat;
        while(window.pollEvent(event_combat)){
             window.draw(sprite_map);
             window.draw(perso1.getSprite());
             window.draw(perso2.getSprite());
             window.draw(perso2.getLifeBarBackground());
             window.draw(perso2.getLifeBar());
             
            if(event_combat.type == sf::Event::Closed)
            {
                window.close();
                return true;
            }
            if(phases == "0"){
                //  cout << "0" << endl;
                if(event_combat.type == sf::Event::KeyPressed){
                    if(event_combat.key.code == sf::Keyboard::Num1){
                        phases += "1";
                        cout << "PHASES :" << phases << endl;
                    }
                    if(event_combat.key.code == sf::Keyboard::Num2){
                        phases += "2";
                        cout << "PHASES :" << phases << endl;
                    }
                    if(event_combat.key.code == sf::Keyboard::Num3){
                        phases += "3";
                        cout << "PHASES :" << phases << endl;
                    }
                    if(event_combat.key.code == sf::Keyboard::Num4){
                        phases += "4";
                        cout << "PHASES :" << phases << endl;
                    }
                }

                window.draw(phase_0_press1);
                window.draw(phase_0_press2);
                window.draw(phase_0_press3);
                window.draw(phase_0_press4);
                window.draw(sprite_combat_action_menu);
            }
            if(phases == "01"){

                if(event_combat.key.code == sf::Keyboard::A){
                    phases += "1";
                    attaquer_animation(perso1.getAllie(0),perso2,window,perso1,map);
                        
                }
                if(event_combat.key.code == sf::Keyboard::B){
                    phases += "2";
                    
                }
                if(event_combat.key.code == sf::Keyboard::C){
                    phases += "3";
                    
                }
                if(event_combat.key.code == sf::Keyboard::D){
                    phases += "4";
                    
                }
                window.draw(poubelle2.getSprite());
                window.draw(phase_01_choose);
                for(size_t i=0;i<perso1.getAllAllies().size();i++){
                    phase_01_nom.setString("PRESS "+ to_string(i+1) +" pour : "+perso1.getAllie(i).getNom());
                    phase_01_nom.setPosition(phase_01_choose.getPosition().x,phase_01_choose.getPosition().y+(i+1)*30);
                    window.draw(phase_01_nom);
                }
            } 
            
            for(size_t i = 0;i<perso1.getAllAllies().size();i++){
                 window.draw(perso1.getAllie(i).getSprite());
                 window.draw(perso1.getAllie(i).getLifeBarBackground());
                 window.draw(perso1.getAllie(i).getLifeBar());
                 
            }

             //  cout << "PHASE : " << phases << endl;
             window.display();
             window.clear();

        }

    
        //std::cout << "voucle inf" << std::endl;
    }
    return false;
}
