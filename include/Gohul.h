//
// Created by Enzo on 2/4/2025.
//

#ifndef GOHUL_H
#define GOHUL_H
#include "Enemigo.h"



class Gohul : public Enemigo{

    int radiationResistance_; //(0-100) indica la resistencia a la radiacion
    bool isFeral_; //true: es salvaje, false: es racional

public: Gohul(std::string name,
          const int health,
          const int attackPoints,
          std::string weakness,
          const int radiationResistance,
          const bool isFeral)
        : Enemigo(std::move(name), health, attackPoints, std::move(weakness))
        , radiationResistance_(radiationResistance)
        , isFeral_(isFeral)
    {
    }

    ~Gohul() override = default;

    void showInfo() const override
    {
        Enemigo::showInfo();
        std::cout << "Resistencia a la radiacion: " << radiationResistance_<<"/100" << std::endl;
        std::cout<<(isFeral_) ? "¡El gohul es salvaje!": "El gohul aun es racional"<<std::endl;
    }
    void doAction() const override
    {
        std::cout<<m_name<<(isFeral_) ?" esta atacando a todo aquel que se le acerque":" esta escondido en busca de sobrevivir"<<std::endl;
    }
};

#endif //GOHUL_H
