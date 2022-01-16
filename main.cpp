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
    vector<Map> maps;
    vector<Ennemi> ennemis;
    Porte porte_nord();
    
    Map map1 = Map(vector<Ennemi>(), false, false, "Images/Forest_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(363,1,489,1,Cardinalite::NORTH),Porte(-10,-10,-10,-10,Cardinalite::SOUTH),NULL,NULL);     

    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }

    map1.setEnnemis(ennemis);

    ennemis.clear();

    maps.push_back(map1);

    Map map2 = Map(vector<Ennemi>(), false, false, "Images/Map2_R.png", "Images/Forest_Combat_R.png", "Sound/pokemon_eterna_forest.wav", "Sound/pokemon-brilliant-diamond-shining-pearl-gym-leader-battle-music-hq.wav",Porte(300,599,500,599,Cardinalite::SOUTH),Porte(-10,-10,-10,-10,Cardinalite::NORTH),NULL,&maps[0]);

    for (size_t i = 0;i < 3;i++)
    {
        ennemis.push_back(Ennemi("Ennemi"+to_string(i),100,10,i*50,75,"Images/poubelle2.png"));
    }

    map2.setEnnemis(ennemis);

    ennemis.clear();

    maps.push_back(map2);

    maps[0].setMapNord(&maps[1]);

    Game jeu;
    jeu.run(maps);
    return 0;
}