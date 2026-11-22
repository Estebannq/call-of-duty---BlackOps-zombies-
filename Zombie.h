//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__ZOMBIE_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__ZOMBIE_H
#include "Enemigo.h"

class Zombie : public Enemigo {
public:
    Zombie();
    Zombie(std::string nombre);
    int atacar(Personaje& objetivo) override;
    void mostrarInfo() override;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__ZOMBIE_H
