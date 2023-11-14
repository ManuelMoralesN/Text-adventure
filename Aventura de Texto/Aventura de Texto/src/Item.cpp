#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() : nombre(""), descripcion("") {}

Item::Item(const string& nombre, const string& descripcion)
    : nombre(nombre), descripcion(descripcion) {}

const string& Item::getNombre() const {
    return nombre;
}

const string& Item::getDescripcion() const {
    return descripcion;
}
