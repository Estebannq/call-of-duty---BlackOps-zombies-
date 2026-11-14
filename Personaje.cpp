//
// Created by juqne on 10/11/2026.
//

#include "Personaje.h"
#include <iostream>

#include "Superviviente.h"

Personaje::Personaje(std::string nombre, int vidaMaxima, int dano):nombre(nombre), dano(dano), vidaMaxima(vidaMaxima), vidaActual(vidaMaxima) {}

std::string Personaje::getNombre() {return nombre;}

int Personaje::getVidaActual(){return vidaActual;}

bool Personaje::estaVivo(){
    if (vidaActual > 0){
        return true;
    } else {
        std::cout<<"El personaje " << nombre << " ha muerto." << std::endl;
        return false;
    }
}
int Personaje::getDano() const {
    return dano;
}

void Personaje::recibirDano(int cantidad){
    vidaActual -= cantidad;
    if (vidaActual < 0){
        vidaActual = 0;
    }
    std::cout<<"El personaje " << nombre << " ha recibido " << cantidad << " de danio. Vida actual: " << vidaActual << std::endl;
}
