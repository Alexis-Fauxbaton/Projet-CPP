#include "Equipement.hpp"
#include "Objet.hpp"
#include "Personnage.hpp"
#include "Inventaire.hpp"

int main()
{
    Allie allie1("Allie_1",100,10);
    std::cout << "Allie1: " << allie1.getNom() << " / HP : " << allie1.getHP() << " / Atk : " << allie1.getAtk() << std::endl;
    Ennemi ennemi1("Ennemi_1",100,10);
    std::cout << "Ennemi1: " << ennemi1.getNom() << " / HP : " << ennemi1.getHP() << " / Atk : " << ennemi1.getAtk() << std::endl;
    allie1.attaquer(ennemi1);
    std::cout << "Ennemi1: " << ennemi1.getNom() << " / HP : " << ennemi1.getHP() << " / Atk : " << ennemi1.getAtk() << std::endl;
    return 0;
}