//
// Created by juqne on 10/11/2026.
//

#include "objeto.h"
#include <iostream>
Objeto::Objeto(std::string nombre):nombre(nombre){}
Objeto::~Objeto() {
    std::cout<<"El objeto " << nombre << " ha sido destruido." << std::endl;
}
std::string Objeto::getNombre()const {return nombre;}