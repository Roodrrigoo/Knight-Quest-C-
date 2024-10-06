#include "personaje.hpp"
#include <iostream>
Personaje::Personaje()
    : puntosSaludTotales(120), puntosSaludActuales(120), maximoAtaque(95), monedas(100) {
    for (int i = 0; i < 4; i++) {
        inventario[i] = Item();
    }
}

std::string Personaje::getNombre() const {
    return nombre;
}

std::string Personaje::getDescripcion() const {
    return descripcion;
}

std::string Personaje::getUbicacion() const {
    return ubicacion;
}

int Personaje::getPuntosSaludTotales() const {
    return puntosSaludTotales;
}

int Personaje::getPuntosSaludActuales() const {
    return puntosSaludActuales;
}

int Personaje::getMaximoAtaque() const {
    return maximoAtaque;
}

int Personaje::getMonedas() const {
    return monedas;
}

const Item* Personaje::getInventario() const {
    return inventario;
}

void Personaje::setNombre(const std::string& nombre) {//usamos this que apunta al objeto actual sobre el metodo 
    this->nombre = nombre;
}

void Personaje::setDescripcion(const std::string& descripcion) {
    this->descripcion = descripcion;
}

void Personaje::setUbicacion(const std::string& ubicacion) {
    this->ubicacion = ubicacion;
}

void Personaje::setPuntosSaludTotales(int puntosSaludTotales) {
    this->puntosSaludTotales = puntosSaludTotales;
}

void Personaje::setPuntosSaludActuales(int puntosSaludActuales) {
    if (puntosSaludActuales < 0) {// hacemos esto para evitar que sean negativos
        this->puntosSaludActuales = 0;
    } else if (puntosSaludActuales > puntosSaludTotales) {// evitamos que sean mayores 
        this->puntosSaludActuales = puntosSaludTotales;
    } else {
        this->puntosSaludActuales = puntosSaludActuales;
    }
}

void Personaje::setMaximoAtaque(int maximoAtaque) {
    this->maximoAtaque = maximoAtaque;
}

void Personaje::setMonedas(int monedas) {
    this->monedas = monedas;
}

bool Personaje::estaVivo() const {
    return puntosSaludActuales > 0;
}

void Personaje::recibirDanio(int danio) {
    puntosSaludActuales -= danio;
    if (puntosSaludActuales < 0) {
        puntosSaludActuales = 0;
    }
}

int Personaje::atacar() {
    // Generar un número aleatorio entre 0 y el máximo de ataque del personaje
    return rand() % (maximoAtaque + 1);//se utiliza modulo para obtener el resultado del la division 
}//sumamos uno para que se enecuentre en el rango 

float Personaje::calcularPorcentajeSalud() const {
    return static_cast<float>(puntosSaludActuales) / puntosSaludTotales * 100.0f;
}

std::string Personaje::imprimirBarraVida() const {//Devuelve una cadena de caracteres
    int porcentajeSalud = static_cast<int>(calcularPorcentajeSalud());//Calcula el porcentaje de salud
    //actual del personaje realiza una conversion  a entero para objeter el porcentaje del 1 al 100
    int numCaracteres = porcentajeSalud / 5;//calcula la cantidad de caracteres % necesarios para representar l a barre cada 5 puntos se representan con%
    std::string barraVida(numCaracteres, '%');//crea un objeto strin llamado barravida repetido numCaracteres
    return barraVida;
}

void Personaje::agregarItem(const Item& item) {
    for (int i = 0; i < 4; i++) {
        if (inventario[i].getNombre() == "") {
            inventario[i] = item;
            break;
        }
    }
}

void Personaje::restarMonedas(int cantidad) {
    monedas -= cantidad;
    if (monedas < 0) {
        monedas = 0;
    }
}


void Personaje::recibirInteraccion(int cantidad) {

    std::cout << "Personaje ha recibido una interacción" << std::endl;
}