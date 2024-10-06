#ifndef MUNDO_HPP
#define MUNDO_HPP

#include <string>
#include "personaje.hpp"

class Mundo {
public:
    Mundo(const std::string& _nombre); // Constructor con parámetros

    std::string getNombre() const; // Método para obtener el nombre del mundo
    void setSiguienteMundo(Mundo& _siguienteMundo); // Método para establecer el siguiente mundo
    Mundo* getSiguienteMundo() const; // Método para obtener el siguiente mundo
    void setPersonaje(Personaje& _personaje); // Método para establecer el personaje del mundo
    Personaje* getPersonaje() const; // Método para obtener el personaje del mundo
    void imprime() const; // Método para imprimir el nombre del mundo
    void interactuarConAmigo(Personaje& jugador);

private:
    std::string nombre; // Almacena el nombre del mundo
    Mundo* siguienteMundo; // Puntero al siguiente mundo
    Personaje* personaje; // Puntero al personaje del mundo
};

#endif
