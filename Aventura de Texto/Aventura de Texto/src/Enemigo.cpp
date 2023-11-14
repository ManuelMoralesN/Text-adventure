#include "Enemigo.h"
using std::string;

Enemigo::Enemigo() : nombre(""), descripcion("") {}

Enemigo::Enemigo(const string& nombre, const string& descripcion)
    : nombre(nombre), descripcion(descripcion) {}

const string& Enemigo::getNombre() const {
    return nombre;
}

const string& Enemigo::getDescripcion() const {
    return descripcion;
}
