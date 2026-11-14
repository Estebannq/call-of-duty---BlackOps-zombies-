#include "Arma.h"
#include "Superviviente.h"
#include <iostream>
Arma::Arma(std::string nombre, int dano):Objeto(nombre), dano(dano){}

bool Arma::usar(Superviviente& usuario) {
    usuario.setDanoArma(dano);
    return false;
};
void Arma::mostrarInfo() {
    std::cout<<"El arma "<< this->nombre << " hace " << this->dano << " de daño." << std::endl;
}