//
// Created by Enzo on 27/3/2025.
//

#ifndef VAULT_TECREFUGIADO_H
#define VAULT_TECREFUGIADO_H
#include "Personaje.h"
#include "entidadGenerica.hpp"


class Vault_TecRefugiado : public Personaje
{
    //atributos S.P.E.C.I.A.L (1-10)
    int strength_; //fuerza
    int perception_; //percepcion
    int endurance_; //resistencia
    int charisma_; //carisma
    int intelligence_; //inteligencia
    int agility_; //agilidad
    int luck_; //suerte

public:
    Vault_TecRefugiado(std::string name,const int age,const int strength,const int perception,
        const int endurance,const int charisma,const int intelligence,const int agility,const int luck)
    : Personaje(std::move(name),age,100), //hereda los atributos de la clase madre
    strength_(strength),
    perception_(perception),
    endurance_(endurance),
    charisma_(charisma),
    intelligence_(intelligence),
    agility_(agility),
    luck_(luck)
    {}
    ~Vault_TecRefugiado() override = default; /*sobrescribe el destructor de la clase Personaje,
    que sobrescribe el destructor de la clase EntidadGenerica*/

    void  showInfo() const override{
        Personaje::showInfo();  //utiliza el metodo de la clase personaje para imprimir los atributos de la clase madre
        std::cout<<"Fuerza: "<<strength_<<"/10"<<std::endl;
        std::cout<<"Percepcion: "<<perception_<<"/10"<<std::endl;
        std::cout<<"Resistencia: "<<endurance_<<"/10"<<std::endl;
        std::cout<<"Carisma: "<<charisma_<<"/10"<<std::endl;
        std::cout<<"Inteligencia: "<<intelligence_<<"/10"<<std::endl;
        std::cout<<"Agilidad: "<<agility_<<"/10"<<std::endl;
        std::cout<<"Suerte: "<<luck_<<"/10"<<std::endl;

    }

    void doAction() const override
    {
        std::cout<<m_name<<" está explorando el yermo."<<std::endl;
    }
};
#endif //VAULT_TECREFUGIADO_H
