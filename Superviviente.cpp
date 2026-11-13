//
// Created by juqne on 10/11/2026.
//

#include "Objeto.h"
#include "Habitacion.h"
#include "Personaje.h"
#include <iostream>

Superviviente::Superviviente(std::string nombre): Personaje(nombre, 100, 10), puntos(0), zombisEliminados(0), danoTotal(0), danoArma(10) {
    this->vidaActual = vidaMaxima;
}
Superviviente::~Superviviente() {
    std::cout<<"El superviviente " << nombre << " ha sido destruido." << std::endl;
}

int Superviviente::atacar(Personaje& objetivo) {
    danoTotal += dano + danoArma;
    objetivo.recibirDano(danoTotal);
    std::cout<<"El superviviente " << nombre << " ha atacado a " <<objetivo.getNombre() << ". Le genero un daño de "<< danoArma << std::endl;
    std::cout<<"El superviviente " << nombre << " ha generado un daño total de "<< danoTotal << std::endl;
    return danoTotal;
}
void Superviviente::recibirDano(int cantidad) {
    vidaActual -= cantidad;
    if (vidaActual < 0) {
        vidaActual = 0;
    }
    std::cout<<"El superviviente " << nombre << " ha recibido " << cantidad << " de daño." << std::endl;
}

void Superviviente::mostrarInfo() {
    std::cout<<"El superviviente " << nombre << " tiene " << vidaActual << " de vida." << " y genera " << danoTotal << " de daño total." << std::endl;
}
void Superviviente::agregarObjeto(Objeto* objeto) {
    if (objeto==nullptr){
        std::cout<<"El objeto no es valido." << std::endl;
    } else {
        objetos.push_back(objeto);
        std::cout<<"El objeto " << objeto->getNombre() << " ha sido agregado al inventario del superviviente " << nombre << "." << std::endl;

    }
}
void Superviviente::usarObjeto(int indice) {
    if (indice >= 0 && indice < objetos.size()) {
        objetos[indice]->usar(*this);
    } else {
        std::cout<<"El indice del objeto no es valido." << std::endl;
    }
}
void Superviviente::mostrarInventario() {
    std::cout<<"Inventario del superviviente " << nombre << ":" << std::endl;
    for (int i = 0; i < objetos.size(); i++) {
        std::cout << "  " << (i + 1) << ". ";
        objetos[i]->mostrarInfo();
    }
}
void Superviviente::regenerarVida() {
    vidaActual = vidaMaxima;
}
void Superviviente::registrarEliminacion(int puntos) {
    this->puntos += puntos;
    zombisEliminados++;
}
void Superviviente::mostrarResumenFinal() {
    std::cout<<"Resumen final del superviviente " << nombre << ":" << std::endl;
    std::cout<<"  Puntos obtenidos: " << puntos << std::endl;
    std::cout<<"  Zombis eliminados: " << zombisEliminados << std::endl;
}
void Superviviente::setDanoArma(int dano) {
    this->danoArma = dano;
}
void Superviviente::aumentarVidaMaxima(int cantidad) {
    vidaMaxima += cantidad;
    vidaActual = vidaMaxima;
}
Habitacion* Superviviente::getHabitacionActual() {
    return habitacionActual;
}
void Superviviente::setHabitacionActual(Habitacion* habitacion) {
    this->habitacionActual = habitacion;
}
std::string Superviviente::getNombre() const { return nombre;}
int Superviviente::getVidaMaxima() const { return vidaMaxima;}