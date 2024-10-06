#ifndef PERSONAJE_AMISTOSO_HPP
#define PERSONAJE_AMISTOSO_HPP

#include "personaje.hpp"
#include "guerrero.hpp"

class PersonajeAmistoso : public Personaje {
public:
    PersonajeAmistoso(const std::string& nombre, const std::string& descripcion, bool dispuestoHablar, const std::string& historia);

    
    bool estaDispuestoHablar() const;
    void juega();
    void recibirInteraccion(int valor);
    std::string getHistoria() const; 
private:
    bool dispuestoHablar;
    std::string historia;
};

#endif
