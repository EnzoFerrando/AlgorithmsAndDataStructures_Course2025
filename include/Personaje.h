//
// Created by Enzo on 27/3/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>
#include "EntidadGenerica.hpp"

class Personaje : public EntidadGenerica {
 protected:
    int m_age;
    int m_health;

 public:
    Personaje(std::string name,const int age,const int health=100)
    : EntidadGenerica(std::move(name)), m_age(age), m_health(health) {}

    ~Personaje() override = default; //sobrescribe el destructor de la clase entidadGenerica

    void showInfo() const override{
        std::cout<<"Nombre: "<<m_name<<std::endl;
        std::cout<<"Edad: "<<m_age<<std::endl;
        std::cout<<"Salud: "<<m_health<<"/100"<<std::endl;
    }
     virtual void doAction() const;

};



#endif //PERSONAJE_H
