//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERROINFERNAL_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERROINFERNAL_H
#include "Enemigo.h"

class PerroInfernal : public Enemigo {
public:
    PerroInfernal();
    int atacar(Personaje& personaje) override;
    void mostrarInfo() override;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERROINFERNAL_H
