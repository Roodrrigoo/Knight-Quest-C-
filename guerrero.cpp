#include "guerrero.hpp"
#include <iostream>
#include <cstdlib> // Para generar números aleatorios

Guerrero::Guerrero(const std::string& _nombre, const std::string& _descripcion)
    : Personaje() { // Llamamos al constructor predeterminado de la clase base
    setNombre(_nombre); // Establecemos el nombre del guerrero
    setDescripcion(_descripcion); // Establecemos la descripción del guerrero
    setPuntosSaludTotales(75); // Establecemos los puntos de salud totales del guerrero a 75
    setPuntosSaludActuales(75); // Establecemos los puntos de salud actuales del guerrero a 75
    setMaximoAtaque(0); // Establecemos el máximo de ataque del guerrero a 0
}

int Guerrero::actuar() {//se define la funcion actuar que devuelve un valor entero ,el ataque realizado por el guerrero 
    int ataqueRealizado = rand() % (getMaximoAtaque() + 1); // Generamos un número aleatorio entre 0 y el máximo ataque
    std::cout << getNombre() << " ataca con " << ataqueRealizado << " puntos de salud" << std::endl;
    return ataqueRealizado;
}

void Guerrero::recibirInteraccion(int cantidad) { 
    std::cout << getNombre() << " recibió " << cantidad << " puntos de daño" << std::endl;
    int nuevaSalud = getPuntosSaludActuales() - cantidad;
    if (nuevaSalud < 0) {
        nuevaSalud = 0;
    }
    setPuntosSaludActuales(nuevaSalud);

    if (nuevaSalud == 0) {
        std::cout << getNombre() << " ha muerto" << std::endl;
    } else {
        std::cout << "Barra de vida: " << imprimirBarraVida() << std::endl;
    }
}