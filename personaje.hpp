#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <string>
#include "item.hpp"

class Personaje {
private:
    std::string nombre;
    std::string descripcion;
    std::string ubicacion;
    int puntosSaludTotales;
    int puntosSaludActuales;
    int maximoAtaque;
    int monedas;
    Item inventario[4];
    
public:
    Personaje();

    std::string getNombre() const;
    std::string getDescripcion() const;
    std::string getUbicacion() const;
    int getPuntosSaludTotales() const;
    int getPuntosSaludActuales() const;
    int getMaximoAtaque() const;
    int getMonedas() const;
    const Item* getInventario() const;// esta funcion devuelve un puntero a un objeto de la clase item
    // esto representa el inventario del personaje

    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);
    void setUbicacion(const std::string& ubicacion);
    void setPuntosSaludTotales(int puntosSaludTotales);
    void setPuntosSaludActuales(int puntosSaludActuales);
    void setMaximoAtaque(int maximoAtaque);
    void setMonedas(int monedas);

    bool estaVivo() const;
    void recibirDanio(int danio);
    int atacar();
    float calcularPorcentajeSalud() const;
    std::string imprimirBarraVida() const;

    void agregarItem(const Item& item);
    void restarMonedas(int cantidad);
    virtual void recibirInteraccion(int cantidad);
    // perimitimos que se pueda sobrescirbir 
};

#endif

