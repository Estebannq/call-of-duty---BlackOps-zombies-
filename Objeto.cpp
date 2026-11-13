//
// Created by juqne on 10/11/2026.
//

#include "objeto.h"
#include <iostream>
Objeto::Objeto(std::string nombre):nombre(nombre){}
std::string Objeto::getNombre()const {return nombre;}