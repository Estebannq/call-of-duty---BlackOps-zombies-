//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__ARMA_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__ARMA_H
#include "Objeto.h"
#include "Superviviente.h"

class Arma : public Objeto{
private:
    int dano;
public:
    Arma(std::string nombre, int dano);
    bool usar(Superviviente& usuario) override;
    void mostrarInfo() override;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__ARMA_H
