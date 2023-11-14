#pragma once
#include <string>

using namespace std;

class Item {
public:
    Item(); 

    Item(const string& nombre, const string& descripcion);

    const string& getNombre() const;

    const string& getDescripcion() const;

private:
    string nombre;
    string descripcion;
};
