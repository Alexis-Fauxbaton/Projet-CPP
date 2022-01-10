#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Inventaire.hpp"

int main()
{
    Arme Adefaut;
    Armure Ddefaut;
    Mystique Mdefaut;
    Arme epee("epee",10,10,10,false);
    Armure armure("armure",10,10,10,false);
    Mystique baguette("baguette",10,10,10,false);
    Allie allie1("Allie_1",100,10,0,0,"poubelle2.png");
    std::cout << allie1.getEquipement().getArme().getAtk() << std::endl;
    allie1.ajouterArme(epee);
    allie1.ajouterArmure(armure);
    allie1.ajouterMystique(baguette);
    std::cout << allie1.getEquipement().getArme().getNom() << std::endl;
    std::cout << "Allie1: " << allie1.getNom() << " / HP : " << allie1.getHP() << " / Atk : " << allie1.getAtk() << std::endl;
    Ennemi ennemi1("Ennemi_1",100,10,0,0,"poubelle2.png");
    std::cout << "Ennemi1: " << ennemi1.getNom() << " / HP : " << ennemi1.getHP() << " / Atk : " << ennemi1.getAtk() << std::endl;
    allie1.attaquer(ennemi1);
    std::cout << "Ennemi1: " << ennemi1.getNom() << " / HP : " << ennemi1.getHP() << " / Atk : " << ennemi1.getAtk() << std::endl;
    allie1.ajouterArme(Adefaut);
    allie1.ajouterArmure(Ddefaut);
    allie1.ajouterMystique(Mdefaut);
    std::cout << "Allie1: " << allie1.getNom() << " / HP : " << allie1.getHP() << " / Atk : " << allie1.getAtk() << std::endl;
    return 0;
}