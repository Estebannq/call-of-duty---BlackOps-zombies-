#include "objeto.h"
objeto::objeto(std::string nombre) {
    this->nombre = nombre;
}
objeto::~objeto() {

}
std::string objeto::getNombre() {
    return this->nombre;
}