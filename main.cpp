#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Inventaire.hpp"
#include "Obstacle.hpp"
#include "Map.hpp"
#include "Game.hpp"
#include "Porte.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

int main()
{
    vector<Map*> maps;
    vector<Ennemi> ennemis;
    vector<Obstacle> obstacles2;
    vector<Obstacle> obstacles3;
    vector<Obstacle> obstacles_boss;
    Porte porte_nord();
    Ennemi Boss("Boss",500,40,400,300,"Images/voiture.png");
    
    Map map1 = Map(vector<Ennemi>(), "Images/Forest_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(750,750,374,590,Cardinalite::NORTH),Porte(-10,-10,-10,-10,Cardinalite::SOUTH),NULL,NULL, vector<Obstacle>());     
    Allie eolienne("Eolienne",100,10,220,240,"Images/wind-turbine.png");
    
    /*for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }*/

    ennemis.push_back(Ennemi("Ennemi 1",100,10,550,230,"Images/poubelle2.png"));
    ennemis.push_back(Ennemi("Ennemi 2",130,30,550,480,"Images/poubelle2.png"));

    ennemis[1].setPrisonnier(eolienne);

    std::cout << "Here1" << std::endl;

    map1.setEnnemis(ennemis);

    ennemis.clear();

//    maps.push_back(&map1);

    Map map2 = Map(vector<Ennemi>(), "Images/map_inter_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(380,540,0,0,Cardinalite::NORTH),Porte(0,0,140,240,Cardinalite::SOUTH),NULL,&map1, vector<Obstacle>());

    ennemis.push_back(Ennemi("Ennemi 1",150,35,220,170,"Images/masque.png"));
    ennemis.push_back(Ennemi("Ennemi 2",180,45,490,110,"Images/masque.png"));

    obstacles2.push_back(Obstacle(0,0,380,160));
    obstacles2.push_back(Obstacle(530,0,270,340));
    obstacles2.push_back(Obstacle(0,270,350,300)); // PB SUR CET OBSTACLE

    map2.setObstacles(obstacles2);

    map2.setEnnemis(ennemis);

    ennemis.clear();

    Map map3 = Map(vector<Ennemi>(), "Images/Map2_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(-10,-10,-10,-10,Cardinalite::NORTH),Porte(300,500,590,590,Cardinalite::SOUTH),NULL,&map1, obstacles3);

    /*for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,200,"Images/poubelle2.png"));
    }*/
    ennemis.push_back(Ennemi("Ennemi 1",250,60,300,300,"Images/cigarettes.png"));
    


    obstacles3.push_back(Obstacle(0,0,290,600));
    obstacles3.push_back(Obstacle(440,0,360,600));

    map3.setObstacles(obstacles3);

    map3.setEnnemis(ennemis);

    ennemis.clear();

//    maps.push_back(&map3);

//    map1.setMapNord(&map3);

    map3.setMapSud(&map2);

    Map map_boss = Map(vector<Ennemi>(), "Images/Boss_map_R.png", "Images/Boss_combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(-10,-10,-10,-10,Cardinalite::NORTH),Porte(210,480,590,590,Cardinalite::SOUTH),NULL,&map3, obstacles_boss);

    map_boss.ajouterEnnemi(Boss);

    obstacles_boss.push_back(Obstacle(0,0,800,280));
    obstacles_boss.push_back(Obstacle(0,0,200,600));
    obstacles_boss.push_back(Obstacle(580,0,250,600));

    map_boss.setObstacles(obstacles_boss);

/*    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*80,300,"Images/poubelle2.png"));
    }

    map_boss.setEnnemis(ennemis);*/


//    ennemis.clear();

//    maps.push_back(&map_boss);

    std::cout << "Here" << std::endl;
    map1.setMapNord(&map2);
    map2.setMapNord(&map3);
    map2.setMapSud(&map1);
    map3.setMapNord(&map_boss);
    map3.setPorteNord(Porte(290,440,0,0,Cardinalite::NORTH));
    map_boss.setMapSud(&map3);
    maps.push_back(&map1);
    maps.push_back(&map3);
    maps.push_back(&map_boss);
    std::cout << "Maps chargées" << std::endl;


    Game jeu;
    jeu.run(maps);
    return 0;
}