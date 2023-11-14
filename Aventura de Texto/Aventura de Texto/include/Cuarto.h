#pragma once
#include <string>
#include "Item.h"
#include "Enemigo.h"

class Cuarto {
public:
    Cuarto(); 

    Cuarto(const std::string& nombre, const std::string& descripcion, const Item& item, const Enemigo& enemigo);

    void mostrarInfo() const;

    bool tieneItem() const;

    const Item& getItem() const;

    bool tieneEnemigo() const;

private:
    std::string nombre;
    std::string descripcion;
    Item item;
    Enemigo enemigo;
};
