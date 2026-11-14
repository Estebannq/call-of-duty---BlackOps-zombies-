#include <iostream>
#include <limits>
#include "Juego.h"
#include "Zombie.h"
#include "PerroInfernal.h"
#include "Arma.h"
#include "Perk.h"

int main() {
    int opcion = 0;

    std::cout << "===========================================" << std::endl;
    std::cout << "     BIENVENIDO A BLACK OPS ZOMBIES        " << std::endl;
    std::cout << " Viviras la experiencia de jugar textualmente." << std::endl;
    std::cout << "===========================================" << std::endl;

    while (opcion != 4) {
        std::cout << "\n=========== MENU PRINCIPAL ===========" << std::endl;
        std::cout << "1. Iniciar Juego." << std::endl;
        std::cout << "2. Mostrar informacion de enemigos y objetos." << std::endl;
        std::cout << "3. Informacion y reglas del juego." << std::endl;
        std::cout << "4. Salir." << std::endl;
        std::cout << "Escoge una opcion: ";
        std::cin >> opcion;

        // Validar que el usuario no ingrese letras en lugar de numeros
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n[ERROR] Por favor ingresa un numero valido." << std::endl;
            continue;
        }

        // Limpiar el Enter pendiente para que std::getline funcione bien en juego.iniciar()
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1: {
                Juego juego;
                juego.iniciar();
                break;
            }
            case 2: {
                std::cout << "\n--- BESTIARIO DE ENEMIGOS ---" << std::endl;
                Zombie zDemo;
                PerroInfernal pDemo;
                zDemo.mostrarInfo();
                std::cout << "   Recompensa por baja: " << zDemo.getPuntosRecompensa() << " puntos." << std::endl;
                pDemo.mostrarInfo();
                std::cout << "   Recompensa por baja: " << pDemo.getPuntosRecompensa() << " puntos." << std::endl;

                std::cout << "\n--- ARMAS Y PERKS DISPONIBLES ---" << std::endl;
                Arma pistola("M1911 Mejorada", 15);
                Arma rayGun("Ray Gun", 45);
                Perk juggernog("Juggernog", 50);
                pistola.mostrarInfo();
                rayGun.mostrarInfo();
                juggernog.mostrarInfo();
                break;
            }
            case 3: {
                std::cout << "\n--- INFORMACION DEL JUEGO ---" << std::endl;
                std::cout << "Objetivo: Sobrevive a las hordas de no-muertos, explora las habitaciones," << std::endl;
                std::cout << "equipa armas y bebidas (Perks) para llegar a la Azotea y escapar." << std::endl;
                std::cout << "\nEstadisticas iniciales del Superviviente:" << std::endl;
                std::cout << "- Vida inicial: 100 HP (se regenera +25 HP al despejar salas)." << std::endl;
                std::cout << "- Danio base sin armas: 10 puntos." << std::endl;
                std::cout << "\nComandos dentro de la partida:" << std::endl;
                std::cout << "- [mover]: Desplazate entre salas (norte, sur, este, oeste)." << std::endl;
                std::cout << "- [atacar]: Golpea o dispara al primer enemigo de la sala." << std::endl;
                std::cout << "- [recoger]: Guarda en tu mochila el objeto del suelo." << std::endl;
                std::cout << "- [inventario]: Equipa armas o bebe Perks de tu mochila." << std::endl;
                std::cout << "- [estado]: Revisa tu vida actual, danio total y puntos." << std::endl;
                break;
            }
            case 4:
                std::cout << "\nSaliendo de Black Ops Zombies. ¡Hasta la proxima!" << std::endl;
                break;
            default:
                std::cout << "\n[ERROR] Opcion no valida. Elige un numero entre 1 y 4." << std::endl;
                break;
        }
    }

    return 0;
}
