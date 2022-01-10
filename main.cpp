#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Inventaire.hpp"
#include "Obstacle.hpp"
#include "Map.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    vector<Map> maps;
    Map map = Map(vector<Ennemi>(), false, false, "Images/Forest_R.png", "Images/Forest_Combat.png");     
    maps.push_back(map);
    Game jeu;
    jeu.run(maps);
    return 0;
}