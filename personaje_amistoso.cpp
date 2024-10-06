#include <iostream>
#include "personaje_amistoso.hpp"

PersonajeAmistoso::PersonajeAmistoso(const std::string& _nombre, const std::string& _descripcion, bool _dispuestoHablar, const std::string& _historia)
    : Personaje(), dispuestoHablar(_dispuestoHablar), historia(_historia) {
    setNombre(_nombre);
    setDescripcion(_descripcion);
    setPuntosSaludTotales(100);
    setPuntosSaludActuales(100);
    setMaximoAtaque(0);
}

bool PersonajeAmistoso::estaDispuestoHablar() const {
    return dispuestoHablar;
}

void PersonajeAmistoso::juega() {
    if (dispuestoHablar) {
        std::cout << historia << std::endl;
    } else {
        std::cout << "No están dispuestos a hablar." << std::endl;
    }
}

void PersonajeAmistoso::recibirInteraccion(int valor) { // Corregir el nombre de la función aquí
    if (dispuestoHablar) {
        if (valor > 3) {
            std::cout << historia << std::endl;
        } else {
            std::cout << getNombre() << " está dormido" << std::endl;
        }
    } else {
        std::cout << "No están dispuestos a hablar." << std::endl;
    }
}

std::string PersonajeAmistoso::getHistoria() const {
    return historia;
}