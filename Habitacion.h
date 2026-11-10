//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__HABITACION_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__HABITACION_H
#include <string>
#include <vector>
#include <map>
#include "Habitacion.h"
#include "Enemigo.h"
#include "Objeto.h"

class Habitacion {
private:
    std::string nombre;
    std::string descripcion;
    std::map<std::string, Habitacion*> salidas;
    std::vector<Enemigo*> enemigos;
    std::vector<Objeto*> objetos;
public:
    Habitacion(std::string nombre, std::string descripcion);
    ~Habitacion();
    void conectar(std::string direccion, Habitacion* destino);
    void agregarEnemigo(Enemigo* enemigo);
    void quitarEnemigo(Enemigo* enemigo);
    bool hayEnemigos();
    void agregarObejto(Objeto* objeto);
    Objeto* recojerObjeto(int indice);
    void mostrar();
    std::string getNombre();
    Habitacion* getSalida(std::string direccion);
    std::vector<Enemigo*>& getEnemigos() const;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__HABITACION_H
