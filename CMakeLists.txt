cmake_minimum_required(VERSION 4.3)
project(call_of_duty___BlackOps_zombies_)

set(CMAKE_CXX_STANDARD 20)

add_executable(call_of_duty___BlackOps_zombies_ main.cpp
        Personaje.cpp
        Personaje.h
        Superviviente.cpp
        Superviviente.h
        Enemigo.cpp
        Enemigo.h
        Zombie.cpp
        Zombie.h
        PerroInfernal.cpp
        PerroInfernal.h
        Juego.cpp
        Juego.h
        Habitacion.cpp
        Habitacion.h
        objeto.cpp
        objeto.h
        Arma.cpp
        Arma.h
        Perk.cpp
        Perk.h)
