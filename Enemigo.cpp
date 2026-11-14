//
// Created by juqne on 10/11/2026.
//

#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo(std::string nombre, int vidaMaxima, int dano, int puntosRecompensa): Personaje(nombre, vidaMaxima, dano), puntosRecompensa(puntosRecompensa){}

int Enemigo::getPuntosRecompensa() {
    return puntosRecompensa;
}