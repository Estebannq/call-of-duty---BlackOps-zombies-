//
// Created by juqne on 10/11/2026.
//

#include "PerroInfernal.h"
#include <iostream>
#include "Enemigo.h"

PerroInfernal::PerroInfernal(): Enemigo(nombre, vidaMaxima, dano, puntosRecompensa) {}

int PerroInfernal::atacar(Personaje& objetivo) {
    objetivo.recibirDano(dano);
    return dano;
}
void PerroInfernal::mostrarInfo() {
    std::cout<<"El Perro Infernal "<< this->nombre << " tiene " << this->vidaActual << " de vida y hace " << this->dano << " de daño." << std::endl;
}