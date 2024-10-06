#include "item.hpp"         //En esta seccion del codigo incluinos  item.hpp
                            //este contiene la declaracion de la clase intem
Item::Item() : precio(0), incrementoMaxAtaque(0) {}//iniciamos el precio e incrementoMaxAtaque con el valor de 0

Item::Item(const std::string& _nombre, const std::string& _descripcion, int _precio, int _incrementoMaxAtaque)
    : nombre(_nombre), descripcion(_descripcion), precio(_precio), incrementoMaxAtaque(_incrementoMaxAtaque) {}
     // tenemos el constructor item pero con parametros en este caso los componentes son nombre,descripcion precio e IncrementoMaxAtaque
     //con los valores proporcionados                                                                                                                                            



std::string Item::getNombre() const {// devuelve el nombre del item
    return nombre;
}

std::string Item::getDescripcion() const {// devuelve la descripcion del item 
    return descripcion;
}

int Item::getPrecio() const {//devuelve el precio del item 
    return precio;
}

int Item::getIncrementoMaxAtaque() const {//devuelve el incremento en ataque maximo 
    return incrementoMaxAtaque;
}

void agregarItem(const Item& item);
