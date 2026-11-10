//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERK_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERK_H
#include "Objeto.h"
#include "Superviviente.h"

class Perk : public Objeto {
private:
    int vidaExtra;
public:
    Perk(std::string nombre, int vidaExtra);
    bool usar(Superviviente& usuario) override;
    void mostrarInfo() override;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__PERK_H
