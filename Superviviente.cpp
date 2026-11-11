#include "Superviviente.h"
#include <iostream>

// Constructor
Superviviente::Superviviente(std::string nombre) : Personaje(nombre) {
    this->puntos = 0;
    this->zombisEliminados = 0;
    this->danoTotal = 0;
    this->danoArma = 0;
}

// Destructor (libera la memoria dinámica de los objetos almacenados)
Superviviente::~Superviviente() {
    for (size_t i = 0; i < objetos.size(); i++) {
        delete objetos[i];
    }
    objetos.clear();
}

// Método sobrescrito: atacar
int Superviviente::atacar(Personaje& objetivo) {
    int danoRealizado = this->getDano() + this->danoArma;
    this->danoTotal += danoRealizado;
    // objetivo.recibirDano(danoRealizado); // Descomenta si tu clase Personaje tiene este método
    return danoRealizado;
}

// Método para recibir daño
void Superviviente::recibirDano(int cantidad) {
    // Lógica para restar vida al superviviente
}

// Método sobrescrito: mostrarInfo
void Superviviente::mostrarInfo() {
    Personaje::mostrarInfo();
    std::cout << "Puntos: " << puntos << " | Zombis eliminados: " << zombisEliminados << " | Daño total: " << danoTotal << std::endl;
}

// Agregar objeto al vector 'objetos'
void Superviviente::agregarObjeto(Objeto* objeto) {
    objetos.push_back(objeto);
}

// Usar objeto en un índice específico
void Superviviente::usarObjeto(int indice) {
    if (indice >= 0 && indice < objetos.size()) {
        objetos[indice]->usar(); // Asumiendo que la clase Objeto tiene el método usar()
    }
}

// Mostrar inventario
void Superviviente::mostrarInventario() {
    std::cout << "--- Inventario de Objetos ---" << std::endl;
    for (size_t i = 0; i < objetos.size(); i++) {
        std::cout << i << ". Objeto en inventario" << std::endl;
    }
}

// Regenerar vida
void Superviviente::regenerarVida() {
    // Lógica de regeneración sin superar la vida máxima
}

// Registrar eliminación de un zombi
void Superviviente::registrarEliminacion(int puntosGanados) {
    this->zombisEliminados++;
    this->puntos += puntosGanados;
}

// Mostrar resumen final
void Superviviente::mostrarResumenFinal() {
    std::cout << "=== RESUMEN FINAL ===" << std::endl;
    std::cout << "Zombis eliminados: " << zombisEliminados << std::endl;
    std::cout << "Puntos totales: " << puntos << std::endl;
    std::cout << "Daño total causado: " << danoTotal << std::endl;
}

// Setters de objetos
void Superviviente::setDanoArma(int dano) {
    this->danoArma = dano;
}

void Superviviente::aumentarVidaMaxima(int cantidad) {
    // Lógica para incrementar la vida máxima
}

// Getters y Setters de Habitación actual (manejando el vector 'habitaciones')
Habitacion* Superviviente::getHabitacionActual() {
    if (!habitaciones.empty()) {
        return habitaciones.back(); // Retorna la última habitación actual
    }
    return nullptr;
}

void Superviviente::setHabitacionActual(Habitacion* habitacion) {
    habitaciones.push_back(habitacion);
}