#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(const string& nombre) : nombre(nombre) {}

bool Jugador::tieneItem(const string& nombreItem) const {
    for (const auto& item : inventario) {
        if (item.getNombre() == nombreItem) {
            return true;
        }
    }
    return false;
}

void Jugador::recogerItem(const Item& item) {
    inventario.push_back(item);
}

void Jugador::mostrarInventario() const {
    cout << "Inventario de " << nombre << ":\n";
    for (const auto& item : inventario) {
        cout << "- " << item.getNombre() << ": " << item.getDescripcion() << "\n";
    }
    cout << "\n";
}
