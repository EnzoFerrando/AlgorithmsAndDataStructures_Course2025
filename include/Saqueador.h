//
// Created by Enzo on 2/4/2025.
//

#ifndef SAQUEADOR_H
#define SAQUEADOR_H
#include <string>
#include "Enemigo.h"

class Saqueador : public Enemigo {
    std::string gangName_; //nombre de la banda de saqueadores
    std::string weaponName_; //el arma que tiene equipada (revolver, escopeta, cuchillo,etc)
    int weaponLvl_; //nivel del arma equipada (1-10)

public : Saqueador (std::string name, const int health, const int attackPoints, std::string weakness,
        std::string gangName, std::string weaponName, const int weaponLvl):
        Enemigo (std::move(name), health, attackPoints, std::move(weakness)),
        gangName_(std::move(gangName)),
        weaponName_(std::move(weaponName)),
        weaponLvl_(weaponLvl){}

    ~Saqueador() override = default;
    void showInfo() const override
    {
        Enemigo::showInfo();
        std::cout << "Pertenece a la banda: " << gangName_ << std::endl;
        std::cout <<m_name<<" tiene un/a: "<<weaponName_<< " nivel: "<<weaponLvl_<<"/10"<<std::endl;
    }
    void doAction() const override
    {
     std::cout<<"¡"<<m_name<<" junto a sus compañeros de "<<gangName_<<" estan preparando un ataque al refugio 33!"<<std::endl;
    }
};
#endif //SAQUEADOR_H
