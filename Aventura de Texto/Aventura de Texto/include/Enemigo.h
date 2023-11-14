#pragma once
#include <string>

class Enemigo {
public:
    Enemigo(); 

    Enemigo(const std::string& nombre, const std::string& descripcion);

    const std::string& getNombre() const;

    const std::string& getDescripcion() const;

private:
    std::string nombre;
    std::string descripcion;
};
