//
// Created by juqne on 10/11/2026.
//

#include "PerroInfernal.h"
#include <iostream>
#include "Enemigo.h"

PerroInfernal::PerroInfernal(): Enemigo("Cerbero",50, 15, 25) {
    this->vidaActual = vidaMaxima;
}

int PerroInfernal::atacar(Personaje& objetivo) {
    objetivo.recibirDano(dano);
    std::cout<<"El Perro Infernal " << nombre << " ha atacado a " <<objetivo.getNombre() << ". Le genero un daño de "<< dano << std::endl;
    return dano;
}
void PerroInfernal::mostrarInfo() {
    std::cout<<"El Perro Infernal "<< this->nombre << " tiene " << this->vidaActual << " de vida y hace " << this->dano << " de daño." << std::endl;
}