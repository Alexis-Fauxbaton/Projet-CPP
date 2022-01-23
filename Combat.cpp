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



void attaquer_animation(Allie &allie,Ennemi &ennemi,sf::RenderWindow &window,Maitre &perso1,sf::Sprite sprite_map, sf::Sprite sprite_cage){


   int initial_allie_position = allie.getSprite().getPosition().x;

   // l'allié qui attaque se déplace jusqu'a l'ennemi
    while(abs(allie.getSprite().getPosition().x - ennemi.getSprite().getPosition().x)>10){

         allie.getSprite().setPosition(allie.getSprite().getPosition().x+3,allie.getSprite().getPosition().y);

        // on draw les alliés, le joueur et l'ennemi à chaque tour
         window.draw(sprite_map);
         window.draw(perso1.getSprite());
         window.draw(ennemi.getSprite());
         window.draw(ennemi.getLifeBarBackground());
         window.draw(ennemi.getLifeBar());
         window.draw(ennemi.getPrisonnier().getSprite());
         if (ennemi.getloot_allie())
            window.draw(sprite_cage);

         for(size_t i = 0;i<perso1.getAllAllies().size();i++){
            window.draw(perso1.getAllie(i).getSprite());
            window.draw(perso1.getAllie(i).getLifeBarBackground());
            window.draw(perso1.getAllie(i).getLifeBar());
            window.draw(perso1.getAllie(i).getEquipement().getArme().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getArmure().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getMystique().getSprite());
                 
             
         }
         window.draw(allie.getSprite());
         window.display();
         window.clear();
    }

    // son d'attaque et on inflige les dégats

    sf::SoundBuffer default_buffer;
    default_buffer.loadFromFile("Sound/attack-sound-effect-new-yorker (mp3cut.net).wav");
    sf::Sound music(default_buffer);

    music.play();
    sleep(1);
    allie.attaquer(ennemi);
    if(!ennemi.estMort()){
        ennemi.getLifeBar().setSize(sf::Vector2f((ennemi.getHP()*1.0/ennemi.getBaseHP())*50,5));
    }
    else{
        ennemi.getLifeBar().setSize(sf::Vector2f(0,5));
    }
    
    // l'allié retourne a sa place

    while(abs(allie.getSprite().getPosition().x - initial_allie_position)>=3){
        allie.getSprite().setPosition(allie.getSprite().getPosition().x-3,allie.getSprite().getPosition().y);

        window.draw(sprite_map);
         window.draw(perso1.getSprite());
         window.draw(ennemi.getSprite());
         window.draw(ennemi.getLifeBarBackground());
         window.draw(ennemi.getLifeBar());
         window.draw(ennemi.getPrisonnier().getSprite());
         if (ennemi.getloot_allie())
         window.draw(sprite_cage);
         
         for(size_t i = 0;i<perso1.getAllAllies().size();i++){
             
            window.draw(perso1.getAllie(i).getSprite());
            window.draw(perso1.getAllie(i).getLifeBarBackground());
            window.draw(perso1.getAllie(i).getLifeBar());
            window.draw(perso1.getAllie(i).getEquipement().getArme().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getArmure().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getMystique().getSprite());
                
             
         }
         window.draw(allie.getSprite());
         window.display();
         window.clear();

    }
    
    
    
}

void attaquer_animation2(Allie &allie,Ennemi &ennemi,sf::RenderWindow &window,Maitre &perso1,sf::Sprite sprite_map, sf::Sprite sprite_cage){


   int initial_ennemi_position = ennemi.getSprite().getPosition().x;
    while(abs(ennemi.getSprite().getPosition().x - allie.getSprite().getPosition().x)>10){

         ennemi.getSprite().setPosition(ennemi.getSprite().getPosition().x-3,ennemi.getSprite().getPosition().y);

         window.draw(sprite_map);
         window.draw(perso1.getSprite());
         window.draw(ennemi.getPrisonnier().getSprite());
         if (ennemi.getloot_allie())
            window.draw(sprite_cage);


         for(size_t i = 0;i<perso1.getAllAllies().size();i++){
            window.draw(perso1.getAllie(i).getSprite());
            window.draw(perso1.getAllie(i).getLifeBarBackground());
            window.draw(perso1.getAllie(i).getLifeBar());
            window.draw(perso1.getAllie(i).getEquipement().getArme().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getArmure().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getMystique().getSprite());
         }
         window.draw(ennemi.getSprite());
         window.display();
         window.clear();
    }


    sf::SoundBuffer default_buffer;
    default_buffer.loadFromFile("Sound/attack-sound-effect-new-yorker (mp3cut.net).wav");
    sf::Sound music(default_buffer);

    music.play();
    sleep(1);
    ennemi.attaquer(allie);
    if(!allie.estMort()){
        allie.getLifeBar().setSize(sf::Vector2f((allie.getHP()*1.0/allie.getBaseHP())*50,5));
    }
    else{
        allie.getLifeBar().setSize(sf::Vector2f(0,5));
    }
    


    while(abs(ennemi.getSprite().getPosition().x - initial_ennemi_position)>=3){
        ennemi.getSprite().setPosition(ennemi.getSprite().getPosition().x+3,ennemi.getSprite().getPosition().y);

         window.draw(sprite_map);
         window.draw(perso1.getSprite());
         window.draw(ennemi.getPrisonnier().getSprite());
         if (ennemi.getloot_allie())
            window.draw(sprite_cage);
         
         for(size_t i = 0;i<perso1.getAllAllies().size();i++){
             
            window.draw(perso1.getAllie(i).getSprite());
            window.draw(perso1.getAllie(i).getLifeBarBackground());
            window.draw(perso1.getAllie(i).getLifeBar());
            window.draw(perso1.getAllie(i).getEquipement().getArme().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getArmure().getSprite());
            window.draw(perso1.getAllie(i).getEquipement().getMystique().getSprite());
                  
         }
         window.draw(ennemi.getSprite());
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


bool Combat::commencer(sf::RenderWindow &window,sf::Sound &music){

    window.create(sf::VideoMode(800, 400), "Combat");

    sf::Texture texture_map = map.getTextureCombat();
    sf::Sprite sprite_map(texture_map);
    
               
    // Positionnement allies Personnages

    perso1.getSprite().setPosition(20,240);
    perso2.getSprite().setPosition(600,240);                 

    for(size_t i=0;i < perso1.getAllAllies().size();i++){
        perso1.getAllie(i).getSprite().setPosition(sf::Vector2f(perso1.getSprite().getPosition().x+70*(i+1),perso1.getSprite().getPosition().y));
    }
                   

    // Bar de vies et menus       

    for(size_t i= 0;i<perso1.getAllAllies().size();i++){
        perso1.getAllie(i).getLifeBar().setFillColor(sf::Color::Red);
        perso1.getAllie(i).getLifeBar().setPosition(perso1.getAllie(i).getSprite().getPosition().x,perso1.getAllie(i).getSprite().getPosition().y-5);
        perso1.getAllie(i).getLifeBarBackground().setPosition(perso1.getAllie(i).getSprite().getPosition().x,perso1.getAllie(i).getSprite().getPosition().y-5);
    }

    // Postionnement Ennemi et/ou prisonnier et cage

    perso2.getLifeBar().setFillColor(sf::Color::Red);
    perso2.getLifeBar().setPosition(600,245);
    perso2.getLifeBar().setSize(sf::Vector2f(50,5));
    perso2.getLifeBarBackground().setPosition(perso2.getLifeBar().getPosition().x,perso2.getLifeBar().getPosition().y);
    perso2.getPrisonnier().getSprite().setPosition(perso2.getSprite().getPosition().x+70,perso2.getSprite().getPosition().y);
    

    sf::Texture texture_cage;
    texture_cage.loadFromFile("Images/Cage-PNG-File.png");
    sf::Sprite sprite_cage(texture_cage);
    sprite_cage.setPosition(perso2.getSprite().getPosition().x+50,perso2.getSprite().getPosition().y-20);


    sf::Texture texture_combat_action_menu;
    sf::Sprite sprite_combat_action_menu;
    texture_combat_action_menu.loadFromFile("Images/combat_action_menu.png");
    sprite_combat_action_menu.setTexture(texture_combat_action_menu);
    sprite_combat_action_menu.setPosition(100,10);


    //TEXTE MENU

    sf::Font font_game;
    font_game.loadFromFile("Fonts/game_font.TTF");

    //Phase 01

    sf::Text phase_01_press1("PRESS 1",font_game,8);
    phase_01_press1.setPosition(20,35);
    sf::Text phase_01_press2("PRESS 2",font_game,8);
    phase_01_press2.setPosition(20,55);
    sf::Text phase_01_press3("PRESS 3",font_game,8);
    phase_01_press3.setPosition(20,75);
    sf::Text phase_01_press4("PRESS L",font_game,8);
    phase_01_press4.setPosition(20,95);
    

    //Phase 0

    sf::Text phase_0_choose("Tour de : ",font_game,14);
    phase_0_choose.setPosition(300,100);
    

    // Allie turn

    size_t allie_turn = 0;
    int phase = 0;
    int mort;
    int action = 0;


    // SET ITEM POSITIONS
    for(size_t i = 0;i < perso1.getAllAllies().size();i++){
        perso1.getAllie(i).getEquipement().getArme().getSprite().setPosition(perso1.getAllie(i).getSprite().getPosition().x,perso1.getAllie(i).getSprite().getPosition().y-40);
        perso1.getAllie(i).getEquipement().getArmure().getSprite().setPosition(perso1.getAllie(i).getSprite().getPosition().x+45,perso1.getAllie(i).getSprite().getPosition().y-40);
        perso1.getAllie(i).getEquipement().getMystique().getSprite().setPosition(perso1.getAllie(i).getSprite().getPosition().x+20,perso1.getAllie(i).getSprite().getPosition().y-85);
    }
        




    while(1){

        // On initialise la boucle du combat

        sf::Event event_combat;
        while(window.pollEvent(event_combat)){

            // On draw la map a chaque tour, le joueur, l'ennemi et les barres de vies
             window.draw(sprite_map);
             window.draw(perso1.getSprite());
             window.draw(perso2.getSprite());
             window.draw(perso2.getLifeBarBackground());
             window.draw(perso2.getLifeBar());
             

            // On regarde si tous les alliés sont morts
            mort = 1;
            for(size_t i = 0;i < perso1.getAllAllies().size();i++){
                if(!perso1.getAllie(i).estMort()){
                    mort = 0;
                    break;
                }
            }
            // Si l'ennemi est mort on déclanche l'animation de fin et on ferme la fenêtre de combat
            if(perso2.estMort()){

                for(size_t i = 0;i<perso1.getAllAllies().size();i++){
                 window.draw(perso1.getAllie(i).getSprite());
                 window.draw(perso1.getAllie(i).getLifeBarBackground());
                 window.draw(perso1.getAllie(i).getLifeBar());
                 
                }

                window.draw(perso2.getPrisonnier().getSprite());
                if(perso2.getloot_allie()){
                    window.draw(sprite_cage);
                }

                window.display();
                
                music.stop();
                sf::SoundBuffer victory_buffer;
                victory_buffer.loadFromFile("Sound/victory-sound-effect.wav");
                sf::Sound victory_sound(victory_buffer);
                victory_sound.play();
                sleep(victory_sound.getBuffer()->getDuration());
                victory_buffer.loadFromFile("Sound/you-win-street-fighter-sound-effect.wav");
                victory_sound.setBuffer(victory_buffer);
                victory_sound.play();
                sleep(victory_sound.getBuffer()->getDuration());
                window.create(sf::VideoMode(800, 600), "Game");
                
                return true;
            }

            // Si tous les alliés sont morts on ferme la fenêtre de combat
            if(event_combat.type == sf::Event::Closed || mort == 1)
            {
                music.stop();
                window.create(sf::VideoMode(800, 600), "Game");
                return false;
            }

            
            // La phase 0 correspond au tour des alliés, is peuvent choisir entre attaquer ou prendre la fuite
            if(phase == 0){

                window.draw(phase_01_press1);
                window.draw(phase_01_press2);
                window.draw(phase_01_press3);
                window.draw(phase_01_press4);
                window.draw(sprite_combat_action_menu);
                phase_0_choose.setString(phase_0_choose.getString()+perso1.getAllie(allie_turn).getNom());
                window.draw(phase_0_choose);
                phase_0_choose.setString("Tour de : ");

                if(!perso1.getAllie(allie_turn).estMort()){

                
                    if(event_combat.type == sf::Event::KeyPressed){
                        action = 1;
                        if(event_combat.key.code == sf::Keyboard::Num1){
                            attaquer_animation(perso1.getAllie(allie_turn),perso2,window,perso1,sprite_map,sprite_cage);

                        }
                        if(event_combat.key.code == sf::Keyboard::Num2){
                            
                        }
                        if(event_combat.key.code == sf::Keyboard::Num3){
                            
                        }
                        if(event_combat.key.code == sf::Keyboard::L){
                            
                            music.stop();
                            window.create(sf::VideoMode(800, 600), "Game");
                            return false;
                        
                        }
                    }
                }
                if(action == 1 || perso1.getAllie(allie_turn).estMort()){
                    if(allie_turn < perso1.getAllAllies().size()-1){
                        allie_turn += 1;
                    }
                    else{
                        phase = 1;
                        allie_turn = 0;
                    }
                    
                }
                action = 0;
                
            } 
            
            // la phase 1 correspond au tour de l'ennemi qui contre attaque l'allié le plus proche de lui
            else if(phase == 1 && !perso2.estMort()){
                
                int cible = perso1.getAllAllies().size() - 1;
                while(1){
                    if(perso1.getAllie(cible).estMort()){
                        cible = cible - 1;
                    }
                    else{
                        break;
                    }
                }
                attaquer_animation2(perso1.getAllie(cible),perso2,window,perso1,sprite_map,sprite_cage);
                phase = 0;

            }

            // on affiche les alliés a chaque tour avec leurs items et les barres de vies
            
            for(size_t i = 0;i<perso1.getAllAllies().size();i++){
                if(!perso1.getAllie(i).estMort()){
                    window.draw(perso1.getAllie(i).getSprite());
                    window.draw(perso1.getAllie(i).getLifeBarBackground());
                    window.draw(perso1.getAllie(i).getLifeBar());
                    window.draw(perso1.getAllie(i).getEquipement().getArme().getSprite());
                    window.draw(perso1.getAllie(i).getEquipement().getArmure().getSprite());
                    window.draw(perso1.getAllie(i).getEquipement().getMystique().getSprite());
                }
            }
            window.draw(perso2.getPrisonnier().getSprite());
            if(perso2.getloot_allie()){
                window.draw(sprite_cage);
            }
            
             window.display();
             
             window.clear();
             

        }

    }
    return false;
}
