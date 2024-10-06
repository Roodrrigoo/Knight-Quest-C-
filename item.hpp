//Rodrigo Fernando Rivera Olea
#ifndef ITEM_HPP
#define ITEM_HPP //estas dos lineas hacen que el archivo solo se incluye una vez en el programa

#include <string>// agregamos la libreria string para poder utilizar std::string

class Item {
public:
    Item();// se declaran los constructores item  y otro constructor con parametros para inicializar los miembros de la clase 
    Item(const std::string& _nombre, const std::string& _descripcion, int _precio, int _incrementoMaxAtaque);
    // //se declara la clase item que tiene cuatro datos privados nombre descripcion precio e incremento de ataque


    std::string getNombre() const;// Se declaran 4 metods que nos dan acceso a los atributos de clase
    std::string getDescripcion() const;// estos son getNombre(),getDescripcion(),getPrecio y getIncrementoMaxAtaque()
    int getPrecio() const;
    int getIncrementoMaxAtaque() const;

private:// en esta parte colocamos los miembors privados y estos son accedidos y modificados dentro de la clase item 
    std::string nombre;//variable de tipo string almacena el nombre
    std::string descripcion;//variable de tipo string que almacena decripcion
    int precio;//variable de tipo entero que da precio
    int incrementoMaxAtaque;//variable de tipo entero  que indica incrementoMaxAtaque 
};

#endif
