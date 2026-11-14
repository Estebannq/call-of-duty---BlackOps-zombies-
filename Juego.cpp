
#include <iostream>
#include <ostream>
#include "Juego.h"
#include "Habitacion.h"
#include "Enemigo.h"
#include "Superviviente.h"
#include "PerroInfernal.h"
#include "Zombie.h"
#include "Arma.h"
#include "Perk.h"


Juego::Juego() : jugador(nullptr) {
}

Juego::~Juego() {
    for (auto& par : habitaciones) {
        delete par.second;
    }
    habitaciones.clear();
    delete jugador;
    for (size_t i = 0; i < enemigos.size(); i++) {
        delete enemigos[i];
    }
    enemigos.clear();
}

void Juego::construirMapa() {
    // 1. Crear habitaciones
    Habitacion* entrada = new Habitacion("Sala Inicial", "Un vestibulo destruido con barricadas de madera.");
    Habitacion* pasillo = new Habitacion("Pasillo Oscuro", "Se escuchan gruñidos y pasos pesados.");
    Habitacion* laboratorio = new Habitacion("Laboratorio", "Hay maquinas expendedoras de bebidas antiguas.");
    Habitacion* azotea = new Habitacion("Azotea", "Punto de extraccion. Un helicoptero espera.");

    habitaciones["entrada"] = entrada;
    habitaciones["pasillo"] = pasillo;
    habitaciones["laboratorio"] = laboratorio;
    habitaciones["azotea"] = azotea;

    // 2. Conectar salidas (ida y vuelta)
    entrada->conectar("norte", pasillo);
    pasillo->conectar("sur", entrada);

    pasillo->conectar("este", laboratorio);
    laboratorio->conectar("oeste", pasillo);

    laboratorio->conectar("norte", azotea);
    azotea->conectar("sur", laboratorio);

    // 3. Agregar Armas y Perks al mapa
    entrada->agregarObjeto(new Arma("M1911 Mejorada", 15));
    pasillo->agregarObjeto(new Perk("Juggernog", 50));
    laboratorio->agregarObjeto(new Arma("Ray Gun", 45));

    // 4. Agregar Enemigos (a la habitacion y a la lista de Juego)
    Enemigo* perro = new PerroInfernal();
    pasillo->agregarEnemigo(perro);
    enemigos.push_back(perro);

    Enemigo* zombie1 = new Zombie();
    laboratorio->agregarEnemigo(zombie1);
    enemigos.push_back(zombie1);

    Enemigo* zombieJefe = new Zombie();
    azotea->agregarEnemigo(zombieJefe);
    enemigos.push_back(zombieJefe);
}

void Juego::iniciar() {
    std::string nombreJugador;
    std::cout << "=== CALL OF DUTY: BLACK OPS ZOMBIES ===" << std::endl;
    std::cout << "Ingresa el nombre de tu superviviente: ";
    std::getline(std::cin, nombreJugador);

    jugador = new Superviviente(nombreJugador);
    construirMapa();
    jugador->setHabitacionActual(habitaciones["entrada"]);

    bool jugando = true;
    while (jugando && jugador->estaVivo()) {
        Habitacion* actual = jugador->getHabitacionActual();
        actual->mostrar();

        if (actual->hayEnemigos()) {
            std::cout << "\n--- Enemigos en la sala ---" << std::endl;
            for (Enemigo* e : actual->getEnemigos()) {
                e->mostrarInfo();
            }
        }

        std::cout << "\nAcciones: [mover] [atacar] [recoger] [inventario] [estado] [salir]: ";
        std::string opcion;
        std::cin >> opcion;

        if (opcion == "mover") {
            std::cout << "Direccion (norte, sur, este, oeste): ";
            std::string dir;
            std::cin >> dir;
            Habitacion* siguiente = actual->getSalida(dir);

            if (siguiente != nullptr) {
                jugador->setHabitacionActual(siguiente);
                // Regenera vida automaticamente si entras a una zona despejada
                if (!siguiente->hayEnemigos()) {
                    jugador->regenerarVida();
                    std::cout << "Zona despejada. Tu superviviente recupera aliento (+25 vida)." << std::endl;
                }
                if (siguiente == habitaciones["azotea"] && !siguiente->hayEnemigos()) {
                    std::cout << "\n¡Llegaste a la azotea despejada y escapaste!" << std::endl;
                    jugando = false;
                }
            } else {
                std::cout << "No hay salida en esa direccion." << std::endl;
            }
        }
        else if (opcion == "atacar") {
            if (actual->hayEnemigos()) {
                Enemigo* objetivo = actual->getEnemigos()[0];
                int dano = jugador->atacar(*objetivo);
                std::cout << "Atacaste a " << objetivo->getNombre() << " por " << dano << " de dano." << std::endl;

                if (!objetivo->estaVivo()) {
                    std::cout << "¡Has eliminado a " << objetivo->getNombre() << "!" << std::endl;
                    jugador->registrarEliminacion(objetivo->getPuntosRecompensa());
                    actual->quitarEnemigo(objetivo);

                    // Si despejas toda la sala, regeneras vida
                    if (!actual->hayEnemigos()) {
                        jugador->regenerarVida();
                        std::cout << "¡Sala despejada! Regeneras +25 de vida." << std::endl;
                    }

                    if (actual == habitaciones["azotea"] && !actual->hayEnemigos()) {
                        std::cout << "\n¡Despejaste la azotea y abordaste el helicoptero! ¡Victoria!" << std::endl;
                        jugando = false;
                    }
                } else {
                    // Los enemigos vivos contraatacan
                    for (Enemigo* e : actual->getEnemigos()) {
                        e->atacar(*jugador);
                    }
                }
            } else {
                std::cout << "No hay enemigos en esta sala." << std::endl;
            }
        }
        else if (opcion == "recoger") {
            Objeto* obj = actual->recogerObjeto(0);
            if (obj != nullptr) {
                jugador->agregarObjeto(obj);
                std::cout << "Has recogido: ";
                obj->mostrarInfo();
            } else {
                std::cout << "No hay objetos en el suelo." << std::endl;
            }
        }
        else if (opcion == "inventario") {
            jugador->mostrarInventario();
            std::cout << "Escribe el numero del objeto a usar (-1 para cancelar): ";
            int idx;
            std::cin >> idx;
            if (idx >= 0) {
                jugador->usarObjeto(idx);
            }
        }
        else if (opcion == "estado") {
            jugador->mostrarInfo();
        }
        else if (opcion == "salir") {
            jugando = false;
        }
    }

    finalizarPartida();
}

void Juego::finalizarPartida() {
    if (jugador != nullptr) {
        jugador->mostrarResumenFinal();
    }
}
