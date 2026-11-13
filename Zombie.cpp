//
// Created by juqne on 10/11/2026.
//

#include "Zombie.h"
#include "Enemigo.h"
#include <iostream>
Zombie::Zombie(): Enemigo("Guamanga", 70, 20, 50) {
    this->vidaActual = vidaMaxima;
}

int Zombie::atacar(Personaje& objetivo){
    objetivo.recibirDano(dano);
    std::cout<<"El Zombie " << nombre << " ha atacado a " <<objetivo.getNombre() << ". Le genero un daño de "<< dano << std::endl;
    return dano;
}

void Zombie::mostrarInfo() {
    std::cout<<"El Zombie "<< this->nombre << " tiene " << this->vidaActual << " de vida y hace " << this->dano << " de daño." << std::endl;
}
