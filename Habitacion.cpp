#include "Habitacion.h"

#include <iostream>
#include <ostream>

Habitacion::Habitacion(std::string nombre, std::string descripcion) {
    this->nombre = nombre;
    this->descripcion = descripcion;
}
Habitacion::~habitacion() {
    for (int i=0;i<objetos.size();i++) {
        delete objetos[i];
    }
    objetos.clear();
    std::cout<<"Habitacion con objetos barrado"<<std::endl;
}
void Habitacion::conectar(std::string direccion, habitacion* destino) {
salidas[direccion]=destino;
}
void Habitacion::agregarEnemigo(enemigo* enemigo) {
    enemigos.push_back(enemigo);
}
void Habitacion::quitarEnemigo(Enemigo* enemigo) {
    for (int i=0;i<enemigos.size();i++) {
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
    objetos.push_back(objeto);
}

Objeto* Habitacion::recogertoObjeto(int indice) {

}
void Habitacion::mostrar() {

        std::cout << "\nHabitacion: " << nombre << std::endl;
        std::cout << "Descripcion: " << descripcion << std::endl;

        
        std::cout << "Salidas: ";
        for (auto const& par : salidas) {
            std::cout << "[" << par.first << "] ";
        }
        std::cout << std::endl;

        
        std::cout << "Enemigos vivos: " << enemigos.size() << std::endl;
        std::cout << "Objetos en el suelo: " << objetos.size() << std::endl;

}
std::string Habitacion::getNombre() {
    return nombre;
}
Habitacion* habitacion::getSalida(std::string direccion) {
    if (salidas.find(direccion) != salidas.end()) {
        return salidas[direccion];
    }
    return nullptr;
}
std::vector<Enemigo*>& getEnemigos() const {
    return enemigos;
}
