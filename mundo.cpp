#include "mundo.hpp"
#include <iostream>
#include "personaje_amistoso.hpp"
Mundo::Mundo(const std::string& _nombre) : nombre(_nombre), siguienteMundo(nullptr), personaje(nullptr) {}

std::string Mundo::getNombre() const {
    return nombre;
}

void Mundo::setSiguienteMundo(Mundo& _siguienteMundo) {
    siguienteMundo = &_siguienteMundo;
}

Mundo* Mundo::getSiguienteMundo() const {
    return siguienteMundo;
}

void Mundo::setPersonaje(Personaje& _personaje) {
    personaje = &_personaje;
}

Personaje* Mundo::getPersonaje() const {
    return personaje;
}

void Mundo::imprime() const {
    std::cout << "Estas en el mundo [" << nombre << "]" << std::endl;
}


