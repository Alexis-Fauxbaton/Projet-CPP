#include <iostream>
#include <string>
#include <vector>
#include "Objet.hpp"
#include "Equipement.hpp"


void Equipement::setArme(Arme &arme){
    this->arme=arme;
    this->arme.getTexture().loadFromFile(arme.getTexturePath());
    this->arme.getSprite().setTexture(this->arme.getTexture());
}

void Equipement::setArmure(Armure &armure){
    this->armure = armure;
    this->armure.getTexture().loadFromFile(armure.getTexturePath());
    this->armure.getSprite().setTexture(this->armure.getTexture());
}

void Equipement::setMystique(Mystique &mystique){
    this->mystique = mystique;
    this->mystique.getTexture().loadFromFile(mystique.getTexturePath());
    this->mystique.getSprite().setTexture(this->mystique.getTexture());
}