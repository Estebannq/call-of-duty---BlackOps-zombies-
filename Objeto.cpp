#include "objeto.h"
#include <iostream>
Objeto::Objeto(std::string nombre):nombre(nombre){}
std::string Objeto::getNombre()const {return nombre;}