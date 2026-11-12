
#include "Zombie.h"
#include "Enemigo.h"
#include <iostream>
Zombie::Zombie(): Enemigo(nombre, vidaMaxima, dano, puntosRecompensa) {}

int Zombie::atacar(Personaje& objetivo){
    objetivo.recibirDano(dano);
    return dano;
}

void Zombie::mostrarInfo() {
    std::cout<<"El Zombie "<< this->nombre << " tiene " << this->vidaActual << " de vida y hace " << this->dano << " de daño." << std::endl;
}
