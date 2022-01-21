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
    
    Map map1 = Map(vector<Ennemi>(), false, false, "Images/Forest_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(363,489,0,0,Cardinalite::NORTH),Porte(-10,-10,-10,-10,Cardinalite::SOUTH),NULL,NULL);     

    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }

    std::cout << "Here1" << std::endl;

    map1.setEnnemis(ennemis);

    ennemis.clear();

//    maps.push_back(&map1);

    Map map2 = Map(vector<Ennemi>(), false, false, "Images/Map2_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(-10,-10,-10,-10,Cardinalite::NORTH),Porte(300,590,500,590,Cardinalite::SOUTH),NULL,&map1);

    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,200,"Images/poubelle2.png"));
    }

    std::cout << "Here2" << std::endl;

    map2.setEnnemis(ennemis);

    ennemis.clear();

//    maps.push_back(&map2);

    map1.setMapNord(&map2);

    map2.setMapSud(&map1);

    Map map_boss = Map(vector<Ennemi>(), false, false, "Images/Boss_map_R.png", "Images/Boss_combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(-10,-10,-10,-10,Cardinalite::NORTH),Porte(380,420,590,590,Cardinalite::SOUTH),NULL,&map2);

/*    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*80,300,"Images/poubelle2.png"));
    }

    map_boss.setEnnemis(ennemis);*/


//    ennemis.clear();

//    maps.push_back(&map_boss);

    std::cout << "Here" << std::endl;

    map2.setMapNord(&map_boss);
    map2.setPorteNord(Porte(300,380,0,0,Cardinalite::NORTH));
    map_boss.setMapSud(&map2);
    maps.push_back(&map1);
    maps.push_back(&map2);
    maps.push_back(&map_boss);
    std::cout << "Maps chargées" << std::endl;


    Game jeu;
    jeu.run(maps);
    return 0;
}