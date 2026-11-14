
#include "Zombie.h"
#include "Enemigo.h"
#include <iostream>
Zombie::Zombie(): Enemigo("Guamanga", 70, 20, 50) {
    this->vidaActual = vidaMaxima;
}

int Zombie::atacar(Personaje& objetivo){
    objetivo.recibirDano(dano);
    std::cout<<"==================================="<<std::endl;
    std::cout<<"El Zombie " << nombre << " ha atacado a " <<objetivo.getNombre() << ". Le genero un dano de "<< dano << std::endl;
    std::cout<<"===================================\n"<<std::endl;
    return dano;
}

void Zombie::mostrarInfo() {
    std::cout<<"El Zombie "<< this->nombre << " tiene " << this->vidaActual << " de vida y hace " << this->dano << " de dano." << std::endl;
}
