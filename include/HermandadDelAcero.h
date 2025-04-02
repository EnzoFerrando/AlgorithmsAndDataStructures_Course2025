//
// Created by Enzo on 30/3/2025.
//

#ifndef HERMANDADDELACERO_H
#define HERMANDADDELACERO_H
#include "Personaje.h"
#include "entidadGenerica.hpp"



class HermandadDelAcero : public Personaje {

    std::string rank_; //recluta, caballero, paladin, etc
    int armorProtection_; //proteccion que brinda la sevoarmadura (1-100)
    int weaponLvl_; //nivel de dominio de armas avanzadas (1-10)
    bool loyalty_; // true:leal a la hermandad, false:traidor
    public: HermandadDelAcero(std::string name, const int age, const int health, std::string rank,
        const int armorProtection, const int weaponLvl, const bool loyalty):
    Personaje(std::move(name), age, health),
    rank_(std::move(rank)),
    armorProtection_(armorProtection),
    weaponLvl_(weaponLvl),
    loyalty_(loyalty){}

    ~HermandadDelAcero() override = default;

    void showInfo() const override
    {
        Personaje::showInfo();
        std::cout <<"Rango: "<<rank_<<std::endl;
        std::cout <<"Nivel de proteccion: "<<armorProtection_<<"/100"<<std::endl;
        std::cout <<"Habilidad con armas avanzadas: "<<weaponLvl_<<"/10"<<std::endl;
        //verifica y devuelve si loyalty==true es leal, en el otro caso ha traicionado a la hermandad
        std::cout <<m_name<<(loyalty_? " es leal a la Hermandad del Acero": " ha traicionado a la Hermandad del Acero")<<std::endl;
    };

    void doAction() const override
    {
        std::cout<<m_name<<(loyalty_?" esta entrenando en la base de la Hermandad" : " esta profugo y la Hermandad ofrece una recompensa a quien lo encuentre")<<std::endl;
    }
};
#endif //HERMANDADDELACERO_H
