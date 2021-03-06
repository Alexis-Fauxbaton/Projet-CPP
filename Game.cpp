#include "Game.hpp"
#include "Inventaire.hpp"
#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Map.hpp"
#include "Combat.hpp"
#include "Obstacle.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using namespace std;

void Game::run(vector<Map*> maps)
{
    Map* map_actuelle = maps[0];
    bool switched = true;
    int map_index = 0;
    int combat_index = 0;
    int new_x = 0;
    int new_y = 0;
    vector<Ennemi> ennemis;
    vector<Obstacle> obstacles = map_actuelle->getObstacles();

    Maitre joueur("Joueur",100,50,100,340,"Images/joueur.png");
    Inventaire inventaire;
    
    sf::Sprite sprite_joueur = joueur.getSprite();



    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    bool en_combat = false;
    bool dans_inventaire = false;                         


    // Creation des allies

    Allie poubelle("Poubelle",100,10,360,240,"Images/poubelle2.png");
    Allie eolienne("Eolienne",100,10,220,240,"Images/wind-turbine.png");
    Allie panneau("Panneau",100,10,580,240,"Images/solar-pannel.png");

    joueur.addAllie(poubelle);
    joueur.addAllie(eolienne);
    joueur.addAllie(panneau);

    vector<Objet> objets;

    Objet objet1 = Objet("epee", 0, 100, 20, 0, "Images/épée_1.png");
    Objet objet2 = Objet("hache", 50, 50, 0, 0, "Images/épée_2.png");
    Objet objet3 = Objet("armure", 200, 0, 100, 0, "Images/épée_4.png");
    Objet objet4 = Objet("casque", 100, 0, 50, 0, "Images/armure_1.png");

    objets.push_back(objet1);
    objets.push_back(objet2);
    objets.push_back(objet3);
    objets.push_back(objet4);




    // Déclaration des objets

    sf::Texture armure_texture;
    armure_texture.loadFromFile("Images/épée_4.png");
    sf::Sprite armure_sprite(armure_texture);
    armure_sprite.setPosition(250,200);

    Arme epee1("épée 1",0,20,0,true,"Images/épée_1.png");
    Arme epee2("épée_2",0,20,0,true,"Images/épée_2.png");
    Arme hache1("hache_1",0,20,0,true,"Images/hache_1.png");

    Armure armure1("armure_1",0,0,20,true,"Images/armure_1.png");
    Armure bouclier1("bouclier_1",0,0,20,true,"Images/bouclier_1.png");
    Armure bouclier2("bouclier_2",0,0,20,true,"Images/bouclier_2.png");

    Mystique orbe1("orbe_1",20,0,0,true,"Images/relique_1.png");
    Mystique orbe2("orbe_2",20,0,0,true,"Images/relique_2.png");
    Mystique orbe3("orbe_3",20,0,0,true,"Images/relique_3.png");


// Ajout des armes sur les alliés de départ

    joueur.getAllie(0).ajouterArme(epee1);
    joueur.getAllie(0).ajouterArmure(armure1);
    joueur.getAllie(0).ajouterMystique(orbe1);

    joueur.getAllie(1).ajouterArme(epee2);
    joueur.getAllie(1).ajouterArmure(bouclier1);
    joueur.getAllie(1).ajouterMystique(orbe2);

    joueur.getAllie(2).ajouterArme(hache1);
    joueur.getAllie(2).ajouterArmure(bouclier2);
    joueur.getAllie(2).ajouterMystique(orbe3);


    // ajout objet inventaire

    inventaire.ajouterObjet(epee1);
    inventaire.ajouterObjet(epee2);
    inventaire.ajouterObjet(epee1);
    inventaire.ajouterObjet(bouclier2);
    inventaire.ajouterObjet(bouclier1);

    // declaration inventaire

    vector<Objet> liste_objets;
    vector<Allie> liste_allies;

    sf::Texture textureInventaire;
    sf::Sprite spriteInventaire;
    textureInventaire.loadFromFile("Images/inventaire.png");
    spriteInventaire.setTexture(textureInventaire);

    sf::Texture texturePerso;
    sf::Sprite spritePerso;
    texturePerso.loadFromFile("Images/perso_vide.png");
    spritePerso.setTexture(texturePerso);

    sf::Texture textureArme;
    sf::Sprite spriteArme;
    textureArme.loadFromFile("Images/arme_vide.png");
    spriteArme.setTexture(textureArme);

    sf::Texture textureArmure;
    sf::Sprite spriteArmure;
    textureArmure.loadFromFile("Images/armure_vide.png");
    spriteArmure.setTexture(textureArmure);

    sf::Texture textureMythique;
    sf::Sprite spriteMytique;
    textureMythique.loadFromFile("Images/mythique_vide.png");
    spriteMytique.setTexture(textureMythique);
    

    size_t back_x = 0;
    size_t back_y = 0;

    sf::SoundBuffer default_buffer;
    default_buffer.loadFromFile("Sound/pokemon_eterna_forest.wav");

    sf::Sound music(default_buffer);
    music.setLoop(true);
    music.play();

    sf::Sound music_combat(map_actuelle->getBufferCombat());

    while(1)
    {
        if (maps[2]->getEnnemis()[0].getHP() <= 0) // On regarde si les points de vie du boss sont nuls
        {
            cout << "VICTOIRE" << endl;
            break;
        }

        if (switched) // On détecte si on vient de changer de carte
        {
            if (music.getBuffer()->getDuration() != map_actuelle->getBufferMain().getDuration()) // Si oui on change de musique si celle de la nouvelle carte est différente
            {
                music.setBuffer(map_actuelle->getBufferMain());
                music.setLoop(true);
                music.play();
            }
            music_combat.setBuffer(map_actuelle->getBufferCombat()); // On change le buffer de la musique de combat de la carte, les ennemis et les obstacles
            ennemis = map_actuelle->getEnnemis();
            obstacles = map_actuelle->getObstacles();
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
                if (!en_combat && !dans_inventaire)
                {
                    back_x = joueur.getX();
                    back_y = joueur.getY();
                    if (event.key.code == sf::Keyboard::I) // Si on appuie sur I on active l'inventaire
                    {   
                        dans_inventaire = !dans_inventaire;
                    }
                    // Si on appuie sur les flèches directionnelles on déplace le joueur s'il ne sort pas des limites de la carte
                    else if (event.key.code == sf::Keyboard::Up && joueur.getY() >= 0)
                    {
                        joueur.setPosition(joueur.getX(),joueur.getY()-10);
                    }
                    else if (event.key.code == sf::Keyboard::Down && joueur.getY() <= 599)
                    {
                        joueur.setPosition(joueur.getX(),joueur.getY()+10);
                    }
                    else if (event.key.code == sf::Keyboard::Left && joueur.getX() >= 0)
                    {
                        joueur.setPosition(joueur.getX()-10,joueur.getY());
                    }
                    else if (event.key.code == sf::Keyboard::Right && joueur.getX() <= 799)
                    {
                        joueur.setPosition(joueur.getX()+10,joueur.getY());
                    } 
                    if(joueur.getX() < 0)
                    {
                        joueur.setPosition(0,joueur.getY());
                    }
                    else if(joueur.getX() > 799)
                    {
                        joueur.setPosition(790,joueur.getY());
                    }
                    if(joueur.getY() < 0)
                    {
                        joueur.setPosition(joueur.getX(),0);
                    }
                    else if(joueur.getY() > 599)
                    {
                        joueur.setPosition(joueur.getX(),590);
                    }
                    
                    for (size_t i=0;i<obstacles.size();i++)
                    {
                        if (obstacles[i].detecter_collision(joueur))
                        {
                            joueur.setPosition(back_x,back_y);
                        }
                    }
                    sprite_joueur.setPosition(joueur.getX(),joueur.getY());
                }
                else if (dans_inventaire) // Si l'on est dans l'inventaire et que l'on appuie sur la touche I on sort de l'inventaires
                {   
                    if (event.key.code == sf::Keyboard::I)
                    {
                        dans_inventaire = false;
                    }
                }
            }
            
        }
        if(en_combat) // Suite d'instructions à suivre si le joueur est dans un combat
        {
            // On lance la musique de combat
            music.stop();
            music_combat.setLoop(true);
            music_combat.play();
            map_actuelle->getSpriteCombat().setPosition(20,20);
            Combat combat(joueur,ennemis[combat_index],*maps[map_index]);
            if (combat.commencer(window,music_combat)) // Si le combat est terminé
            {
                if(ennemis[combat_index].getloot_allie()){ // Si l'ennemi vaincu possède un prisonnier on l'ajoute à la liste des alliés du joueur
                    joueur.addAllie(ennemis[combat_index].getPrisonnier());
                }
                ennemis[combat_index].setHp(0); // On passe l'ennemi à 0 hp pour le rendre obsolète sur la carte
                map_actuelle->setEnnemis(ennemis); // On actualise les ennemis de la carte
                switched=true;
                

            }
            else // Si on sort du combat (fermeture de la fenêtre de combat)
            {
                joueur.setPosition(back_x,back_y); // On revient à la position du joueur avant le combat
                sprite_joueur.setPosition(back_x,back_y);
            }
            music.play(); // On relance la musique de la carte
            en_combat = false;
            

        }
        else //Suite d'instructions à suivre si le joueur n'est pas engagé dans un combat
        {
            
            //On regarde si le joueur est sur la porte nord de la carte

            if (map_actuelle->getPorteNord().entre(joueur.getX(),joueur.getY()) && map_actuelle->getMapNord() != NULL)
            {
                // On change la carte et on réinitialise la position du joueur sur la fenêtre
                map_actuelle = map_actuelle->getMapNord();
                new_x = (map_actuelle->getPorteSud().getX2() + map_actuelle->getPorteSud().getX1())/2 + 20;
                new_y = (map_actuelle->getPorteSud().getY2() + map_actuelle->getPorteSud().getY1())/2 - 10;
                joueur.setPosition(new_x,new_y);
                sprite_joueur.setPosition(joueur.getX(),joueur.getY());
                switched = true;
            }

            //On regarde si le joueur se situe sur la porte sud de la carte

            if (map_actuelle->getPorteSud().entre(joueur.getX(),joueur.getY()) && map_actuelle->getMapSud() != NULL)
            {
                // On change la carte et on réinitialise la position du joueur sur la fenêtre
                map_actuelle = map_actuelle->getMapSud();
                new_x = (map_actuelle->getPorteNord().getX2() + map_actuelle->getPorteNord().getX1())/2 - 10;
                new_y = (map_actuelle->getPorteNord().getY2() + map_actuelle->getPorteNord().getY1())/2 + 10;
                joueur.setPosition(new_x,new_y);
                sprite_joueur.setPosition(joueur.getX(),joueur.getY());
                switched = true;            }
            
            for (size_t i = 0;i<ennemis.size();i++) // Pour chaque ennemi présent sur la carte
            {
                if (joueur.estProche(ennemis[i],10) && !ennemis[i].estMort()) // On fait entrer le joueur en combat avec le premier ennemi de la carte qui est assez proche de lui et qui n'est pas mort
                {
                    en_combat = true;
                    combat_index = i; // On enregistre l'index de l'ennemi dans le vecteur d'ennemis
                    break;
                }
            }


            //Suite d'instructions concernant l'affichage à l'écran

            window.clear();

            if (dans_inventaire) 
            // Si le joueur est actuellement dans l'inventaire on dessine le fond de l'inventaire, les différents sprites des alliés,
            // les différents objets tenus par les alliés ainsi que les objets dans l'inventaire du joueur qui n'ont été assignés à aucun allié
            {
                window.draw(spriteInventaire);
                liste_allies = joueur.getAllAllies();
                for (size_t i=0; i<4; i++){
                    if (i>=liste_allies.size())
                    {
                        spritePerso.setPosition(50,i*100 + 70);
                        spriteArme.setPosition(150,i*100+ 80);
                        spriteArmure.setPosition(250,i*100+ 80);
                        spriteMytique.setPosition(350,i*100+ 80);
                        window.draw(spritePerso);
                        window.draw(spriteArme);
                        window.draw(spriteArmure);
                        window.draw(spriteMytique);
                    }
                    else
                    {
                        liste_allies[i].getSprite().setPosition(50,i*100+ 70);
                        window.draw(liste_allies[i].getSprite());

                        if (liste_allies[i].getEquipement().getArme().getNom()=="")
                        {
                            spriteArme.setPosition(150,i*100+ 80);
                            window.draw(spriteArme);
                        }
                        else
                        {
                            liste_allies[i].getEquipement().getArme().getSprite().setPosition(150,i*100+ 80);
                            window.draw(liste_allies[i].getEquipement().getArme().getSprite());
                        }

                        if (liste_allies[i].getEquipement().getArmure().getNom()=="")
                        {
                            spriteArmure.setPosition(250,i*100+ 70);
                            window.draw(spriteArmure);
                        }
                        else
                        {
                            liste_allies[i].getEquipement().getArmure().getSprite().setPosition(250,i*100+ 80);
                            window.draw(liste_allies[i].getEquipement().getArmure().getSprite());
                        }

                        if (liste_allies[i].getEquipement().getMystique().getNom()=="")
                        {
                            spriteMytique.setPosition(350,i*100+ 80);
                            window.draw(spriteMytique);
                        }
                        else
                        {
                            liste_allies[i].getEquipement().getMystique().getSprite().setPosition(350,i*100+ 80);
                            window.draw(liste_allies[i].getEquipement().getMystique().getSprite());
                        }
                    }
                    
                }
                liste_objets = inventaire.getObjets();
                for (int i=0; i<inventaire.getNbObjet(); i++)
                {   
                    liste_objets[i].getSprite().setPosition(i*100,500);
                    window.draw(liste_objets[i].getSprite());
                }
                
            }
            else // Si le joueur n'est pas dans l'inventaire on dessine d'abord la carte, puis les ennemis, et enfin le personnage représentant le joueur
            {
                window.draw(map_actuelle->getSprite());
                for (size_t i=0;i<ennemis.size();i++)
                {
                    if (!ennemis[i].estMort())
                    {
                        window.draw(ennemis[i].getSprite());
                    }
                }
                window.draw(sprite_joueur);
            }
            
            window.display(); // On affiche dans la fenêtre tout ce qui a été dessiné
        }
    }
}