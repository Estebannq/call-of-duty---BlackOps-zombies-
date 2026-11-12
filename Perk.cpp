//
// Created by juqne on 10/11/2026.
//

#include "Perk.h"
#include <iostream>

Perk::Perk(std::string nombre, int vidaExtra): Objeto(nombre), vidaExtra(vidaExtra) {}
bool Perk::usar(Superviviente& usuario) {
        usuario.aumentarVidaMaxima(vidaExtra);
        std::cout<<"El superviviente " << usuario.getNombre() << " ha usado el perk " << nombre << ". Ahora tiene " << usuario.getVidaMaxima() << " de vida." << std::endl;
        return true;
}
void Perk::mostrarInfo() {
    std::cout<<"El perk cumple la funcion de aumentar la vida maxima del superviviente en " << vidaExtra << " puntos." << std::endl;
}