//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__OBJETO_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__OBJETO_H
#include <string>
#include "Superviviente.h"

class Objeto {
protected:
    std::string nombre;
public:
    Objeto(std::string nombre);
    virtual ~Objeto();
    virtual bool usar(Superviviente& usuario) = 0;
    virtual void mostrarInfo() = 0;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__OBJETO_H
