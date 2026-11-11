#include "Juego.h"

#include <iostream>
#include <ostream>

juego::juego() {
}
juego::~juego() {
    for (auto* par: habitaciones ) {
        delete par;
    }
    habitaciones.clear();
    delete jugador;
    for (int i=0;i<enemigos.size();i++) {
        delete enemigos[i];
    }
    enemigos.clear();
}
void juego::iniciar() {
    std::cout << "Iniciando Juego" << std::endl;
    construirMapa();
}
void juego::construirMapa() {
    std::cout << "Construir Mapa" << std::endl;
}
void juego::finalizarPartida() {
    if (jugador!= nullptr) {
        jugador->mostrarResultado();
    }
}