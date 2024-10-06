#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "personaje.hpp"

class Guerrero : public Personaje {
public:
    Guerrero(const std::string& _nombre, const std::string& _descripcion);
    virtual int actuar(); // Método virtual que permite al guerrero atacar
    void recibirInteraccion(int cantidad); // Método que permite al guerrero recibir daño y actualizar su salud
};

#endif
