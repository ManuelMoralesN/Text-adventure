#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include <iostream>

using namespace std;

class Jugador {
public:
    Jugador(const string& nombre);

    bool tieneItem(const string& nombreItem) const;
    void recogerItem(const Item& item);
    void mostrarInventario() const;

private:
    string nombre;
    vector<Item> inventario;
};
