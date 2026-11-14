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
    std::cout << "\n[ATAQUE] " << nombre << " ataca contra " << objetivo.getNombre()
              << " por " << danoRealizado << " de danio!" << std::endl;
    std::cout<<"==================================="<<std::endl;
    objetivo.recibirDano(danoRealizado);
    return danoRealizado;
}

void Superviviente::recibirDano(int cantidad) {
    vidaActual -= cantidad;
    if (vidaActual < 0) {
        vidaActual = 0;
    }
    std::cout << "[DANO RECIBIDO] " << nombre << " pierde " << cantidad
              << " de vida. Vida restante: " << vidaActual << "/" << vidaMaxima << std::endl;
    std::cout<<"==================================="<<std::endl;
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
        std::cout << "\n[OBJETO] " << nombre << " usa un objeto del inventario..." << std::endl;
        bool seConsume = objetos[indice]->usar(*this);
        if (seConsume) {
            std::cout << "[CONSUMIDO] El objeto se ha agotado y desaparece de la mochila." << std::endl;
            delete objetos[indice];
            objetos.erase(objetos.begin() + indice);
        } else {
            std::cout << "[EQUIPADO] El objeto sigue guardado en tu mochila." << std::endl;
        }
    } else {
        std::cout << "[ERROR] Numero de objeto invalido." << std::endl;
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
    if (vidaActual < vidaMaxima) {
        int vidaAnterior = vidaActual;
        int cantidadRecuperacion = 25;
        vidaActual += cantidadRecuperacion;
        if (vidaActual > vidaMaxima) {
            vidaActual = vidaMaxima;
        }
        std::cout << "[CURACION] " << nombre << " recupera " << (vidaActual - vidaAnterior)
                  << " puntos de vida (" << vidaActual << "/" << vidaMaxima << ")." << std::endl;
    }
}

void Superviviente::registrarEliminacion(int puntosGanados) {
    this->zombisEliminados++;
    this->puntos += puntosGanados;
    std::cout << "[BAJA CONFIRMADA] +" << puntosGanados
              << " puntos (Total: " << puntos << " pts | Bajas: " << zombisEliminados << ")." << std::endl;
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
    std::cout << "[MEJORA] ¡Vida maxima aumentada en +" << cantidad
              << "! Nueva vida: " << vidaActual << "/" << vidaMaxima << std::endl;
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