//
// Created by juqne on 10/11/2026.
//

#include "Superviviente.h"
#include "Personaje.h"
#include "Objeto.h"
#include <iostream>

Superviviente::Superviviente(std::string nombre) : Personaje(nombre, 100, 10), puntos(0), zombisEliminados(0), danoTotal(0), danoArma(0) {}

Superviviente::~Superviviente() {
    for (size_t i = 0; i < objetos.size(); i++) {
        delete objetos[i];
    }
    objetos.clear();
}
int Superviviente::getDanoTotal() const {return danoTotal;}

int Superviviente::atacar(Personaje& objetivo) {
    int danoRealizado = this->getDano() + this->danoArma;
    this->danoTotal += danoRealizado;
    objetivo.recibirDano(danoRealizado);
    std::cout << nombre << " ataca a " << objetivo.getNombre() << " causando " << danoRealizado << " de danio." << std::endl;
    return danoRealizado;
}

void Superviviente::recibirDano(int cantidad) {
    vidaActual -= cantidad;

    if (vidaActual < 0) {
        vidaActual = 0;
    }
}

void Superviviente::mostrarInfo() {
    int danoActual = this->getDano() + this->danoArma;
    std::cout << "Danio de ataque actual: " << danoActual << " (Base: " << this->getDano() << " + Arma: " << this->danoArma << ")" << std::endl;
    std::cout << "Puntos: " << puntos << " | Zombis eliminados: " << zombisEliminados << " | Danio acumulado: " << danoTotal << std::endl;
}

void Superviviente::agregarObjeto(Objeto* objeto) {
    objetos.push_back(objeto);
}

void Superviviente::usarObjeto(int indice) {
    if (indice >= 0 && indice < static_cast<int>(objetos.size())) {
        bool seConsume = objetos[indice]->usar(*this);
        if (seConsume) {
            delete objetos[indice];
            objetos.erase(objetos.begin() + indice);
        }
    }
}

void Superviviente::mostrarInventario() {
    std::cout << "--- Inventario de Objetos ---" << std::endl;
    if (objetos.empty()) {
        std::cout << "Inventario vacio." << std::endl;
        return;
    }
    for (size_t i = 0; i < objetos.size(); i++) {
        std::cout << i << ". ";
        objetos[i]->mostrarInfo();
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
    std::cout << "=============RESUMEN FINAL=============" << std::endl;
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
int Superviviente::getPuntos() const{ return puntos;}
std::string Superviviente::getNombre() const{return nombre;}
int Superviviente::getVidaMaxima() const {return vidaMaxima;}