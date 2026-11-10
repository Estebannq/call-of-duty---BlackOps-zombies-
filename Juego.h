//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__JUEGO_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__JUEGO_H
#include "Habitacion.h"
#include "Superviviente.h"
#include "Enemigo.h"
#include <vector>
#include <map>

class Juego {
private:
    std::map<std::string, Habitacion*> habitaciones;
    Superviviente* jugador;
    std::vector<Enemigo*> enemigos;
    void construirMapa();
    void finalizarPartida();
public:
    Juego();
    ~Juego();
    void iniciar();
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__JUEGO_H
