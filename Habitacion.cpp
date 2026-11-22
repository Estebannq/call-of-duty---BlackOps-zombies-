#include "Habitacion.h"
#include "Objeto.h"
#include "Enemigo.h"
#include <iostream>
#include <ostream>

Habitacion::Habitacion(std::string nombre, std::string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}
Habitacion::~Habitacion() {
    std::cout << "[Habitacion] Eliminando: " << this->nombre << std::endl;

    if (objetos.empty()) {
        std::cout << "   -> Sin objetos en el suelo." << std::endl;
    } else {
        for (Objeto* o : objetos) {
            std::cout << "   -> Objeto destruido: " << o->getNombre() << std::endl;
            delete o;
        }
        objetos.clear();
    }
}

void Habitacion::conectar(std::string direccion, Habitacion* destino) {
    if (destino != nullptr) {
        salidas[direccion] = destino;
    }
}

void Habitacion::agregarEnemigo(Enemigo* enemigo) {
    if (enemigo != nullptr) {
        enemigos.push_back(enemigo);
    }
}

void Habitacion::quitarEnemigo(Enemigo* enemigo) {
    for (size_t i=0;i<enemigos.size();i++) {
        if (enemigos[i]==enemigo) {
            enemigos.erase(enemigos.begin()+i);
            break;
        }
    }
}
bool Habitacion::hayEnemigos() {
    return !enemigos.empty();
}

void Habitacion::agregarObjeto(Objeto* objeto) {
    if (objeto != nullptr) {
        objetos.push_back(objeto);
    }
}

Objeto* Habitacion::recogerObjeto(int indice) {
    if (indice >= 0 && indice < static_cast<int>(objetos.size())) {
        Objeto* objeto = objetos[indice];
        objetos.erase(objetos.begin() + indice);
        return objeto;
    }
    return nullptr;
}
void Habitacion::mostrar() {

    std::cout << "\n========================================" << std::endl;
    std::cout << "Habitacion: " << nombre << std::endl;
    std::cout << "Descripcion: " << descripcion << std::endl;

    std::cout << "Salidas: ";
    if (salidas.empty()) {
        std::cout << "Ninguna";
    } else {
        for (const auto& par : salidas) {
            std::cout << "[" << par.first << "] ";
        }
    }
    std::cout << std::endl;

    std::cout << "Enemigos vivos: " << enemigos.size() << std::endl;
    std::cout << "Objetos en el suelo: " << objetos.size() << std::endl;
    std::cout << "========================================" << std::endl;

}
std::string Habitacion::getNombre() {
    return nombre;
}
Habitacion* Habitacion::getSalida(std::string direccion) {
    auto it = salidas.find(direccion);
    if (it != salidas.end()) {
        return it->second;
    }
    return nullptr;
}


const std::vector<Enemigo*>& Habitacion::getEnemigos() const{
    return enemigos;
}
