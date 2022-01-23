#define CATCH_CONFIG_MAIN

#include "catch.hpp"
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

TEST_CASE("1: Méthodes Personnage")
{
    Allie allie("Allié",100,10,220,240,"../Images/wind-turbine.png");
    Ennemi ennemi("Ennemi",100,10,500,400,"../Images/poubelle2.png");
    Maitre maitre("Maitre",100,10,220,240,"../Images/poubelle2.png");

    allie.setAtk(15);
    CHECK(allie.getAtk() == 15);
    allie.setAtk(10);
    
    allie.setHp(10);
    CHECK(allie.getHP() == 10);
    allie.setHp(100);

    allie.setNom("Allié2");
    CHECK(allie.getNom() == "Allié2");
    
    allie.attaquer(ennemi);
    CHECK(ennemi.getHP() == 90);

    ennemi.attaquer(allie);
    CHECK(allie.getHP() == 90);

    maitre.attaquer(allie);
    CHECK(allie.getHP() == 90);

    maitre.attaquer(ennemi);
    CHECK(ennemi.getHP() == 90);

    allie.setHp(0);
    CHECK(allie.estMort());

    CHECK_FALSE(allie.estProche(ennemi,10));

    CHECK(allie.estProche(ennemi,1000));

}

TEST_CASE("2: Méthodes Objet")
{
    Allie allie("Allié",100,10,220,240,"../Images/wind-turbine.png");

    Arme arme("épée",10,10,10,false,"../Images/épée_1.png");
    Arme arme_copie = arme;
    CHECK((arme_copie.getAtk() == arme.getAtk() && arme_copie.getDef() == arme.getDef() && arme_copie.getHP() == arme.getHP() && arme_copie.getNom() == arme.getNom() && arme_copie.getTexturePath() == arme.getTexturePath()));

    Armure armure("armure",10,10,10,false,"../Images/armure_1.png");
    Mystique mystique("mystique",10,10,10,false,"../Images/relique_1.png");

    CHECK(arme.getNom() == "épée");

    CHECK(arme.getAtk() == 10);

    allie.ajouterArme(arme);

    CHECK(allie.getAtk() == 20);

    CHECK(allie.getHP() == 110);

}

TEST_CASE("3: Méthodes Equipement")
{
    Allie allie("Allié",100,10,220,240,"../Images/wind-turbine.png");
    Equipement equipement;
    Arme arme("épée",10,10,10,false,"../Images/épée_1.png");
    Armure armure("armure",10,10,10,false,"../Images/armure_1.png");
    Mystique mystique("mystique",10,10,10,false,"../Images/relique_1.png");

    equipement.setArme(arme);
    equipement.setArmure(armure);
    equipement.setMystique(mystique);

    CHECK(equipement.getArme().getNom() == "épée");
    CHECK(equipement.getArme().getAtk() == 10);

    allie.setEquipement(equipement);



    CHECK(allie.getAtk() == 10);
    CHECK(allie.getHP() == 100);

    allie.appliquerEffetEquipement();

    CHECK(allie.getAtk() == 40);
    CHECK(allie.getHP() == 130);

}

/*
TEST_CASE("4: Méthodes Inventaire")
{
    Maitre maitre("Maitre",100,10,220,240,"../Images/poubelle2.png");
    Inventaire inventaire;
    Arme arme("épée",10,10,10,false,"../Images/épée_1.png");
    Armure armure("armure",10,10,10,false,"../Images/armure_1.png");
    Mystique mystique("mystique",10,10,10,false,"../Images/relique_1.png");

    inventaire.ajouterObjet(arme);
    inventaire.ajouterObjet(armure);
    inventaire.ajouterObjet(mystique);

    std::cout << inventaire.getObjets()[0].getNom() << std::endl;

    CHECK(inventaire.getObjet(0).getNom() == arme.getNom());
    CHECK(inventaire.getObjet(0).getAtk() == arme.getAtk());

}*/

TEST_CASE("5: Obstacle")
{
    Obstacle obstacle(0,0,100,100);
    Allie allie("Allié",100,10,220,240,"../Images/wind-turbine.png");

    CHECK_FALSE(obstacle.detecter_collision(allie));

    allie.setPosition(50,50);

    CHECK(obstacle.detecter_collision(allie));

    obstacle.setX(200);
    obstacle.setY(200);

    CHECK_FALSE(obstacle.detecter_collision(allie));
}

TEST_CASE("6: Porte")
{
    Porte porte(0,100,100,100,Cardinalite::NORTH);
    Allie allie("Allié",100,10,220,240,"../Images/wind-turbine.png");

    CHECK_FALSE(porte.entre(allie.getX(),allie.getY()));

    porte.setX1(200);
    porte.setX2(250);
    porte.setY1(240);
    porte.setY2(240);

    CHECK(porte.entre(allie.getX(),allie.getY()));
}