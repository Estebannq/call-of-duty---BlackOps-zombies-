//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__ENEMIGO_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__ENEMIGO_H
#include "Personaje.h"

class Enemigo : public Personaje{
protected:
    int puntosRecompensa;
public:
    Enemigo(std::string nombre, int vidaMaxima, int dano, int puntosRecompensa);
    virtual ~Enemigo();
    int getPuntosRecompensa();
    virtual int  atacar(personaje& personaje);
};



#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__ENEMIGO_H
