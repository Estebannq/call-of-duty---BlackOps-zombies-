//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERSONAJE_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERSONAJE_H

#include <string>

class Personaje {
protected:
    std::string nombre;
    int vidaActual;
    int vidaMaxima;
    int dano;
public:
    Personaje(std::string nombre, int vidaMaxima, int dano);
    virtual ~Personaje();
    std::string getNombre();
    int getVidaActual();
    bool estaVivo();
    virtual int atacar(Personaje& objetivo) = 0;
    void recibirDano(int cantidad);
    virtual void mostrarInfo() = 0;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERSONAJE_H
