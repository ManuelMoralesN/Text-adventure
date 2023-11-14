#include "Cuarto.h"
#include <iostream>

using namespace std;

Cuarto::Cuarto() : nombre(""), descripcion(""), item(), enemigo() {}

Cuarto::Cuarto(const std::string& nombre, const std::string& descripcion, const Item& item, const Enemigo& enemigo)
    : nombre(nombre), descripcion(descripcion), item(item), enemigo(enemigo) {}

void Cuarto::mostrarInfo() const {
    cout << "Nombre: " << nombre << "\nDescripcion: " << descripcion << endl;
}

bool Cuarto::tieneItem() const {
    return !item.getNombre().empty();
}

const Item& Cuarto::getItem() const {
    return item;
}

bool Cuarto::tieneEnemigo() const {
    return !enemigo.getNombre().empty();
}
