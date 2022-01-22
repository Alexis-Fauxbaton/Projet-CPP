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
    Porte porte_nord();
    Ennemi Boss("Boss",500,40,400,300,"Images/poubelle2.png");
    
    Map map1 = Map(vector<Ennemi>(), "Images/Forest_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(750,750,374,590,Cardinalite::NORTH),Porte(-10,-10,-10,-10,Cardinalite::SOUTH),NULL,NULL);     
    Allie eolienne("Eolienne",100,10,220,240,"Images/wind-turbine.png");
    
    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }
    ennemis[2].setPrisonnier(eolienne);

    std::cout << "Here1" << std::endl;

    map1.setEnnemis(ennemis);

    ennemis.clear();

//    maps.push_back(&map1);

    Map map2 = Map(vector<Ennemi>(), "Images/map_inter_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(363,489,0,0,Cardinalite::NORTH),Porte(0,0,140,240,Cardinalite::SOUTH),NULL,&map1);

    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }

    map2.setEnnemis(ennemis);

    ennemis.clear();

    Map map3 = Map(vector<Ennemi>(), "Images/Map2_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(-10,-10,-10,-10,Cardinalite::NORTH),Porte(300,500,590,590,Cardinalite::SOUTH),NULL,&map1);

    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,200,"Images/poubelle2.png"));
    }

    std::cout << "Here2" << std::endl;

    map3.setEnnemis(ennemis);

    ennemis.clear();

//    maps.push_back(&map3);

//    map1.setMapNord(&map3);

    map3.setMapSud(&map2);

    Map map_boss = Map(vector<Ennemi>(), "Images/Boss_map_R.png", "Images/Boss_combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(-10,-10,-10,-10,Cardinalite::NORTH),Porte(380,420,590,590,Cardinalite::SOUTH),NULL,&map3);

    map_boss.ajouterEnnemi(Boss);

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
    map3.setPorteNord(Porte(300,380,0,0,Cardinalite::NORTH));
    map_boss.setMapSud(&map3);
    maps.push_back(&map1);
    maps.push_back(&map3);
    maps.push_back(&map_boss);
    std::cout << "Maps chargées" << std::endl;


    Game jeu;
    jeu.run(maps);
    return 0;
}