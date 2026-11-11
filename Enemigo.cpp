#include "Enemigo.h"
#include <iostream>

enemigo::Enemigo(std::string nombre,int vidaActual,int vidaMaxima,int dano,int puntosRecompensa)
    :personaje(nombre,vidaActual,vidaMaxima,dano) {
    this->puntosRecompensa = puntosRecompensa;
}
enemigo::~Enemigo() {

}
int enemigo::getpuntosRecompensa() {
    return this->puntosRecompensa;
}
