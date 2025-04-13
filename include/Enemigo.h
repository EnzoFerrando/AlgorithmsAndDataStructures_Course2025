//
// Created by Enzo on 30/3/2025.
//

#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "entidadGenerica.hpp"
#include <iostream>

class Enemigo : public EntidadGenerica {
protected:
    int health_; //cantidad de vida (1-100)
    int attackPoints_; //puntos de ataque, cuanto daño ataque puede causar
    std:: string weakness_; //nombre del tipo de arma que mas daño le genera

public: Enemigo (std::string name, const int health, const int attackPoints, std::string weakness):
    EntidadGenerica(std::move(name)),
    health_(health),
    attackPoints_(attackPoints),
    weakness_(std::move(weakness)){}

     ~Enemigo() override = default;

    void showInfo() const override
    {
        EntidadGenerica::showInfo();
        std::cout<<"Enemigo: "<<m_name<<std::endl;
        std::cout<<"Vida: "<<health_<<"/100"<<std::endl;
        std::cout<<"Puntos de ataque: "<<attackPoints_<<std::endl;
        std::cout<<"Debilidad: "<<weakness_<<std::endl;
    }
};
#endif //ENEMIGO_H
