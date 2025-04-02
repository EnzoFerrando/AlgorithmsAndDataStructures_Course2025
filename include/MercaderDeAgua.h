//
// Created by Enzo on 30/3/2025.
//

#ifndef MERCADERDEAGUA_H
#define MERCADERDEAGUA_H
#include "Personaje.h"

class MercaderDeAgua : public Personaje {
    double waterStock_;//cantidad de agua que tiene a su disposicion en litros
    double stockCapacity_; //stock maximo de agua en litros
    double price_;  //precio de venta del agua por litro
    int negotiationLvl_; //habilidad de negociacion (1-10)
    int reputationLvl_; //reputacion como vendedor (1-10)

    public:
    MercaderDeAgua(std::string name, const int age, const int health,const double waterStock,
        const double stockCapacity, const double price, const int negotiationLvl, const int reputationLvl ):
    Personaje(std::move(name), age, health),
    waterStock_(waterStock),
    stockCapacity_(stockCapacity),
    price_(price),
    negotiationLvl_(negotiationLvl),
    reputationLvl_(reputationLvl){}

     ~MercaderDeAgua() override = default;

    void showInfo() const override
    {
        Personaje::showInfo();
        std::cout << "Agua disponible para la venta: " << waterStock_ <<"/"<<stockCapacity_<< std::endl;
        std::cout << "Precio del agua por litro: "<< price_ <<"/L"<< std::endl;
        std::cout << "Nivel de negociacion: " << negotiationLvl_ <<"/10"<< std::endl;
        std::cout << "Reputacion: " << reputationLvl_ <<"/10" << std::endl;
    }
    void doAction() const override
    {
        (waterStock_>0? std::cout<<"El mercader de agua esta disponile para vender":
            std::cout<<"El mercader no tiene agua para vender")<<std::endl;
    }

    [[nodiscard]] double freeCapacity() const  //retorna el espacio libre del almacenamiento de agua
    {
        return stockCapacity_-waterStock_;
    }
    void increaseWaterStock(double waterIncrement) //aumenta el stock de agua la cantidad waterIncrement
    {
        (freeCapacity()>=waterIncrement?waterStock_+=waterIncrement: waterStock_=stockCapacity_); //el condicional de abajo simplificado
        /*if (freeCapacity() >= waterIncrement)
        {
            waterStock_ += waterIncrement;
        }
        else
        {
            waterStock_ = stockCapacity_; //si se supera la capacidad, el almacenamiento se llena y se pierde el resto
        }*/
    }
    void reduceWaterStock(double waterReduce)//reduce el stock de agua una cantidad waterReduce
    {
        (waterStock_>=waterReduce)? waterStock_-=waterReduce: waterStock_=0;
    }
    void buyWater(double price,double liter)
    {
        price_ = price-negotiationLvl_*5*price/100.0; //descuento segun el nivel de negociacion, por cada nivel el precio disminuye un 5% su valor
        increaseWaterStock(liter);
    }
    /* el vendedor pierde una parte del stock de agua (pensaba luego desarrollarlo mas con un sistema de precios de compra y venta
    y una billetera del vendedor donde se refleje el balance de ganancias y gastos del vendedor)*/
    void sellWater(double liter)
    {
        if (liter>waterStock_)
        {
            std::cout<<"El vendedor no cuenta con la cantidad solicitada de agua"<<std::endl;
        }
        else
        reduceWaterStock(liter);
    }
    void changeReputationLvl(const bool deal) //recibe un parametro true o false, el cual aumenta o disminuye su reputacion
    {
        if (deal)
            if(reputationLvl_<10) reputationLvl_++;
        else
            if(reputationLvl_>0) reputationLvl_--;
    }
};

#endif //MERCADERDEAGUA_H
