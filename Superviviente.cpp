#include "Superviviente.h"
#include <iostream>

Superviviente::Superviviente(std::string nombre) : Personaje(nombre) {
    this->puntos = 0;
    this->zombisEliminados = 0;
    this->danoTotal = 0;
    this->danoArma = 0;
}


Superviviente::~Superviviente() {
    for (size_t i = 0; i < objetos.size(); i++) {
        delete objetos[i];
    }
    objetos.clear();
}


int Superviviente::atacar(Personaje& objetivo) {
    int danoRealizado = this->getDano() + this->danoArma;
    this->danoTotal += danoRealizado;
    objetivo.recibirDano(danoRealizado); 
    return danoRealizado;
}


void Superviviente::recibirDano(int cantidad) {
    vidaActual -= cantidad;

    if (vidaActual < 0) {
        vidaActual = 0;
    }
}



void Superviviente::mostrarInfo() {
    Personaje::mostrarInfo();
    std::cout << "Puntos: " << puntos << " | Zombis eliminados: " << zombisEliminados << " | Daño total: " << danoTotal << std::endl;
}


void Superviviente::agregarObjeto(Objeto* objeto) {
    objetos.push_back(objeto);
}


void Superviviente::usarObjeto(int indice) {
    if (indice >= 0 && indice < objetos.size()) {
        objetos[indice]->usar(); 
    }
}


void Superviviente::mostrarInventario() {
    std::cout << "--- Inventario de Objetos ---" << std::endl;
    for (size_t i = 0; i < objetos.size(); i++) {
        std::cout << i << ". Objeto en inventario" << std::endl;
    }
}


void Superviviente::regenerarVida() {
    int cantidadRecuperacion = 25;

    vidaActual += cantidadRecuperacion;

    if (vidaActual > vidaMaxima) {
        vidaActual = vidaMaxima;
    }
}



void Superviviente::registrarEliminacion(int puntosGanados) {
    this->zombisEliminados++;
    this->puntos += puntosGanados;
}


void Superviviente::mostrarResumenFinal() {
    std::cout << " RESUMEN FINAL " << std::endl;
    std::cout << "Zombis eliminados: " << zombisEliminados << std::endl;
    std::cout << "Puntos totales: " << puntos << std::endl;
    std::cout << "Daño total causado: " << danoTotal << std::endl;
}


void Superviviente::setDanoArma(int dano) {
    this->danoArma = dano;
}

void Superviviente::aumentarVidaMaxima(int cantidad) {
   vidaMaxima += cantidad;  
    vidaActual += cantidad;
}


Habitacion* Superviviente::getHabitacionActual() {
    if (!habitaciones.empty()) {
        return habitaciones.back();
    }
    return nullptr;
}

void Superviviente::setHabitacionActual(Habitacion* habitacion) {
    habitaciones.push_back(habitacion);
}
