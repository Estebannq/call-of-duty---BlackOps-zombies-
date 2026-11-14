//
// Created by juqne on 10/11/2026.
//

#ifndef CALL_OF_DUTY___BLACKOPS_ZOMBIES__SUPERVIVIENTE_H
#define CALL_OF_DUTY___BLACKOPS_ZOMBIES__SUPERVIVIENTE_H

#include "Habitacion.h"
#include "Personaje.h"
#include <vector>

class Objeto;
class Habitacion;
class Superviviente : public Personaje {
private:
    int puntos;
    int zombisEliminados;
    int danoTotal;
    int danoArma;
    std::vector<Objeto*> objetos;
    std::vector<Habitacion*> habitaciones;
public:
    Superviviente(std::string nombre);
    ~Superviviente();
    int atacar(Personaje& objetivo) override;
    void recibirDano(int cantidad);
    void mostrarInfo() override;
    void agregarObjeto(Objeto* objeto);
    void usarObjeto(int indice);
    void mostrarInventario();
    void regenerarVida();
    void registrarEliminacion(int puntos);
    void mostrarResumenFinal();
    void setDanoArma(int dano);
    void aumentarVidaMaxima(int cantidad);
    Habitacion* getHabitacionActual();
    void setHabitacionActual(Habitacion* habitacion);
    std::string getNombre() const;
    int getVidaMaxima() const;
    int getDanoTotal()const;
    int getPuntos() const;
};


#endif //CALL_OF_DUTY___BLACKOPS_ZOMBIES__SUPERVIVIENTE_H
