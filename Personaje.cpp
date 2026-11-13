//
// Created by juqne on 10/11/2026.
//

#include "Personaje.h"
#include <iostream>

Personaje::Personaje(std::string nombre, int vidaMaxima, int dano) {
    this->nombre = nombre;
    this->vidaMaxima = vidaMaxima;
    this->dano = dano;
    (this->vidaActual < 0) ? this->vidaActual = 0 : this->vidaActual;
}

std::string Personaje::getNombre() {return nombre;}

int Personaje::getVidaActual(){return vidaActual;}

bool Personaje::estaVivo(){
    if (vidaActual > 0){
        std::cout<<"El personaje " << nombre << " está vivo con " << vidaActual << " de vida." << std::endl;
        return true;
    } else {
        std::cout<<"El personaje " << nombre << " ha muerto." << std::endl;
        return false;
    }
}

void Personaje::recibirDano(int cantidad){
    vidaActual -= cantidad;
    if (vidaActual < 0){
        vidaActual = 0;
    }
    std::cout<<"El personaje " << nombre << " ha recibido " << cantidad << " de daño. Vida actual: " << vidaActual << std::endl;
}
