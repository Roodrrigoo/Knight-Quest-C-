#include <iostream>//se incluye las librerias necesarias para el funcionamiento del programa
#include <fstream>//iostream y fstream se utlizan para trabajar con entrada y salida de datos
#include "personaje.hpp"
#include "guerrero.hpp"// Los archivos .hpp tienen las definiciones de clases para el programa
#include "mundo.hpp"
#include "personaje_amistoso.hpp"
#include <limits> 
#include <algorithm> //limits y algoritm son librerias que nos van ayudar para nuestra excepcion 

void cargarDatosPersonaje(Personaje& personaje) {//Se declara una funcion que llama cargar datos recibe como parametro una referencia a un objeto
//tipo personaje
    std::ifstream datos("datos.txt");// se crea un objeto ifstream llamado datos que se utiliza para leer el contenido del archivo datos.txt
    if (datos.is_open()) {//verificamos si el archivo se a abierto correctamente 
        std::string clave, valor;// se declaran vairables de tipo string 
        //llamadas clave y valor

        while (datos >> clave) {// se incia un bucle while que se repetira mientras lea claves del archivo

            datos.ignore();
            std::getline(datos, valor);// se utiliza getline para leer toda la linea y almacenarlo en la variale valor

            if (clave == "Nombre:") {// Se realiza una serie de comparaciones para identificar la clave que leyo del archivo
                personaje.setNombre(valor);//en funcion de esa clave se asigna el valor correspondiente al objeto personaje
            } else if (clave == "Descripción:") {
                personaje.setDescripcion(valor);
            } else if (clave == "Ubicación:") {
                personaje.setUbicacion(valor);
            } else if (clave == "Puntos de Salud Totales:") {
                personaje.setPuntosSaludTotales(std::stoi(valor));
                personaje.setPuntosSaludActuales(std::stoi(valor));
            } else if (clave == "Máximo Ataque:") {
                personaje.setMaximoAtaque(std::stoi(valor));
            } else if (clave == "Monedas:") {
                personaje.setMonedas(std::stoi(valor));
            }
        }
        datos.close();// cuando se han leido todos los datos del archivo se cierra
    } else {
        std::cout << "Error al abrir el archivo" << std::endl;//si no se pudo abrir manda un mensaje de error
    }
}

void guardarDatosPersonaje(const Personaje& personaje) {// esta funcion se encarga de guardar los datos de un personaje en un archivo datos.txt
// la funcion toma como parametro una referencia constante a un objeto de tipo personaje esto quiere decir que no modificara el original 
//se declara una funcion guardarDatosPersonaje que recibe como parametro una referencia a "Personaje"   
    
    std::ofstream datos("datos.txt");//se utiliza para escribir en el archivo datos.txt

    if (datos.is_open()) {// Se verifica si el archivo esta abierto 

        //Se utiliza los operadores<< para escribir los datos del personaje en el archivo
        //Se escribe cadaa atributo del personaje seguido de su valor y una linea separada
        datos << "Nombre: " << personaje.getNombre() << std::endl;
        datos << "Descripción: " << personaje.getDescripcion() << std::endl;
        datos << "Ubicación: " << personaje.getUbicacion() << std::endl;
        datos << "Puntos de Salud Totales: " << personaje.getPuntosSaludTotales() << std::endl;
        datos << "Puntos de Salud Actuales: " << personaje.getPuntosSaludActuales() << std::endl;
        datos << "Máximo Ataque: " << personaje.getMaximoAtaque() << std::endl;
        datos << "Monedas: " << personaje.getMonedas() << std::endl;

       

        datos.close();//se cierra el archivo 
    } else {
        std::cout << "Error al abrir el archivo" << std::endl;//manda un mensaje de error si no se pudo abrir 
    }
}

void mostrarInformacionPersonaje(const Personaje& personaje) {//se encarga de imprimir la informacion del personaje
// Imprmie sus distintos atributos

// mediante el metodo get obtenemos toda la informacion necesaria y la imprimimos
    std::cout << "Información del personaje:" << std::endl;
    std::cout << "Nombre: " << personaje.getNombre() << std::endl;
    std::cout << "Descripción: " << personaje.getDescripcion() << std::endl;
    std::cout << "Ubicación: " << personaje.getUbicacion() << std::endl;
    std::cout << "Puntos de Salud Totales: " << personaje.getPuntosSaludTotales() << std::endl;
    std::cout << "Puntos de Salud Actuales: " << personaje.getPuntosSaludActuales() << std::endl;
    std::cout << "Máximo Ataque: " << personaje.getMaximoAtaque() << std::endl;
    std::cout << "Monedas: " << personaje.getMonedas() << std::endl;
}

void mostrarInventario(const Personaje& personaje) {
    std::cout << "Inventario del personaje:" << std::endl;
    const Item* inventario = personaje.getInventario();
    for (int i = 0; i < 4; i++) {
        const Item& item = inventario[i];
        if (item.getNombre() != "") {
            std::cout << i + 1 << ") " << item.getNombre() << " - " << item.getDescripcion() << " - Precio: " << item.getPrecio() << " monedas" << std::endl;
        }
    }
}

void mostrarTienda() {// esta funcion se encarga unicamente de imprimir los objetos de la tienda 
    std::cout << "Tienda:" << std::endl;
    std::cout << "1) Escalibur (Espada encantada y poderosa. Aumenta el máximo ataque en 30) - Precio: 25 monedas" << std::endl;
    std::cout << "2) Lanza (Ideal para cazar bestias. Aumenta el máximo ataque en 20) - Precio: 25 monedas" << std::endl;
    std::cout << "3) Daga (Arma poderosa y sigilosa. Aumenta el máximo ataque en 10) - Precio: 25 monedas" << std::endl;
    std::cout << "4) Ballesta (Arma a distancia con gran potencia. Aumenta el máximo ataque en 5) - Precio: 25 monedas" << std::endl;
}

void comprarItem(Personaje& personaje, int opcion) {//Se declara la funcion comprarItem
//sus parametros son una referencia a personaje y opcion esta representara la eleccion del jugador 
    if (opcion < 1 || opcion > 4) {// esta parte valida si la opcion esta entre 1 o 4
        std::cout << "Opcion invalida, selecciona otra." << std::endl;
        return;
    }

    Item item;// declara una varianle item crea un objeto de la clase item usando el constructor predeterminado 
    switch (opcion) {//utilizamos un switch para las opciones:
    // cada item tiene su nombre , descripcion tiene su costo y el ataque que da al jugador 
        case 1:
            item = Item("Escalibur", "Espada encantada y poderosa. Aumenta el máximo ataque en 30", 25, 30);
            break;
        case 2:
            item = Item("Lanza", "Ideal para cazar bestias. Aumenta el máximo ataque en 20", 25, 20);
            break;
        case 3:
            item = Item("Daga", "Arma poderosa y sigilosa. Aumenta el máximo ataque en 10", 25, 10);
            break;
        case 4:
            item = Item("Ballesta", "Arma a distancia con gran potencia. Aumenta el máximo ataque en 5", 25, 5);
            break;
        default:
            break;
    }

    personaje.agregarItem(item);//se agrega el articulo item al inventario del personaje
    personaje.restarMonedas(25);//se restan 25 monedas al personaje , cada item vale 25 monedas
    personaje.setMaximoAtaque(personaje.getMaximoAtaque() + item.getIncrementoMaxAtaque());//se incrementa el ataque del personaje


    std::cout << "Has comprado el objeto." << std::endl;// s
}

void interactuarConGuerrero(Personaje& jugador, Guerrero& guerrero) {// esta parte del codigo define una funcion
    //interactuarConGuerrero que toma dos parametros de entrada un a referencia a un objeto de  del clase
    //personaje llamado jugador y una referencia a yb objeti de la calse guerrero llama 
    //la referencia &  se utiliza para evitar copiare el objeto del jugador de esta manera permite que la funcion acceda
    //y modifique los datos del objeto origal 
    
    // Mostrar información del jugador y del guerrero

    std::cout << "Información del jugador:" << std::endl;
    std::cout << "Nombre: " << jugador.getNombre() << std::endl;
    std::cout << "Descripción: " << jugador.getDescripcion() << std::endl;
    std::cout << "Puntos de Salud Totales: " << jugador.getPuntosSaludTotales() << std::endl;
    std::cout << "Puntos de Salud Actuales: " << jugador.getPuntosSaludActuales() << std::endl;
    std::cout << "Máximo Ataque: " << jugador.getMaximoAtaque() << std::endl;
    std::cout << "Monedas: " << jugador.getMonedas() << std::endl;

    std::cout << "\nInformación del guerrero:" << std::endl;
    std::cout << "Nombre: " << guerrero.getNombre() << std::endl;
    std::cout << "Descripción: " << guerrero.getDescripcion() << std::endl;
    std::cout << "Puntos de Salud Totales: " << guerrero.getPuntosSaludTotales() << std::endl;
    std::cout << "Puntos de Salud Actuales: " << guerrero.getPuntosSaludActuales() << std::endl;
    std::cout << "Máximo Ataque: " << guerrero.getMaximoAtaque() << std::endl;

    // Batalla entre el jugador y el guerrero
    while (jugador.estaVivo() && guerrero.estaVivo()) {
    // El jugador ataca al guerrero
    int ataqueJugador = jugador.atacar();
    guerrero.recibirInteraccion(ataqueJugador);
    std::cout << "El jugador ataca al guerrero con " << ataqueJugador << " puntos de salud." << std::endl;

    // Verificar si el guerrero sigue vivo después del ataque del jugador
    if (!guerrero.estaVivo()) {
        break; // Salir del bucle si el guerrero ha sido derrotado
    }

    // El guerrero ataca al jugador
    int ataqueGuerrero = guerrero.actuar();
    jugador.recibirDanio(ataqueGuerrero);
    std::cout << "El guerrero ataca al jugador con " << ataqueGuerrero << " puntos de salud." << std::endl;

    // Mostrar estado de salud del jugador y guerrero después de cada ataque
    std::cout << "Salud del jugador: " << jugador.getPuntosSaludActuales() << " / " << jugador.getPuntosSaludTotales() << std::endl;
    std::cout << "Salud del guerrero: " << guerrero.getPuntosSaludActuales() << " / " << guerrero.getPuntosSaludTotales() << std::endl;
    std::cout << std::endl;
}


    // Mostrar resultado de la batalla
    if (jugador.estaVivo()) {
        std::cout << "El jugador ha derrotado al guerrero. ¡Felicidades!" << std::endl;
    } else {
        std::cout << "El jugador ha sido derrotado por el guerrero. ¡Game Over!" << std::endl;
    }
}


void interactuarConAmigo(Personaje& jugador, Mundo& mundoActual, bool& interactuoEnInfierno) {
    //


    PersonajeAmistoso* personajeAmistoso = dynamic_cast<PersonajeAmistoso*>(mundoActual.getPersonaje());
    //se declara un puntero a personajeAmistoso de tipo Personaje amistoso
    //Utilizamos dynamic cast para converitr el puntero a un puntero de tipo PersonajeAmistoso. mundoActual.getPersonaje()
    // de esta manera obtenemos el puntero del personaje presente en el mundo actual 

    if (personajeAmistoso == nullptr) {//se verifica si no se pudo realizar la conversion del puntero 
        std::cout << "No hay personaje amistoso para interactuar aquí." << std::endl;
        return;
    }

    while (personajeAmistoso->estaDispuestoHablar()) {//esta parte del codigo crea un bucle mientras el personaje amistoso este dispuesto hablar
        //esta dispuesto hablar devuelve tru 
        std::cout << personajeAmistoso->getNombre() << ": " << personajeAmistoso->getHistoria() << std::endl;

        int opcionInteraccion; //se declara una variable de tipo entero que almacenara la interaccion del usuario 
        try {//comineza el blo uqed de codigo donde apareceran excepciones 
            std::cout << "Trata de despertar a panchito el humanito (intenta con distintos numeros): ";
            std::cin >> opcionInteraccion;

            if (std::cin.fail()) {//verifica si ocurrio un error al leer el numero
                std::cin.clear();//si ocurrio un error se limpia el estado de cin 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//se descartan los caracteres restantes
                throw std::runtime_error("Error: Debes ingresar un número.");//si ocurrio un error se lanza una excepcion de tipo runtime 
            }

            personajeAmistoso->recibirInteraccion(opcionInteraccion);//Se llama a la funciom recibeInteraccion del objeto apuntado por personaje amsitos 
            //pasando como argumento el valor de opcion interaccion 
            if (mundoActual.getNombre() == "Carcel" && opcionInteraccion > 3) {//en esta parte ponemos el dinal del juego 
                interactuoEnInfierno = true;
                std::cout << "Felicidades, has terminado el juego" << std::endl;
                return;
            }

            if (!personajeAmistoso->estaDispuestoHablar()) {// si el personaje no esta dispuesto hablar despliega un mensaje 
                std::cout << personajeAmistoso->getNombre() << " está dormido" << std::endl;
                return;
            }

            if (mundoActual.getSiguienteMundo() != nullptr) {//esta parte verifica si el mundo actual tiene un siguiente mundo 
            //la funcion siguiente mundo devuelve un puntero al siguiente mundo en la secuenccia 
                mundoActual = *mundoActual.getSiguienteMundo();//Si existeun siguiente mundo se actualiza el mundo actual para que sea igaul al siguiente mudno 

                personajeAmistoso = dynamic_cast<PersonajeAmistoso*>(mundoActual.getPersonaje());
                //Una vez que se actualize el mundo actual intenta convertir el puntero del personaja del mundo actual en un puntero de tipo "personajeamistoso"

                if (personajeAmistoso == nullptr) {// si el puntero es null quiere decir que no hay personaje 
                    std::cout << "No hay personaje amistoso para interactuar aquí." << std::endl;
                    return;
                }
            }
        } catch (const std::runtime_error& error) {//Comienza el bloque catch donde se capturan las excepcioses 
            std::cout << error.what() << std::endl;//error es la referencia a la excepcion ,devuelve una cadena que describe el mensaje de la excepcion 
        }
    }
}

int main() {
    Personaje jugador;//se crea un jugador de la clase personaje 
    cargarDatosPersonaje(jugador);//se invoco a la funcion para cargar los datos del jugardor desde datos.txt
    Guerrero guerrero("Hechizero", "Este hechizero fue corrrompido por el rey para infiltrarse desde adentro , tiene una gran habilidad magica explosiva ");
    guerrero.setMaximoAtaque(20);
    //Se crea un objeto guerrero de la clase Guerrero con un nombre y descricpcion tambien establecemos su ataque 
    Guerrero odin("Rey", "Es aquel que trajo la corrupcion en el reino por su desesperada ambicion"); // Modificamos la descripción de "odin" aquí
    odin.setMaximoAtaque(50); 
    PersonajeAmistoso personajeAmistoso("Panchitoelhumanito", "Un amigable personaje", true, "este fue un personaje encarcelado por el regimen y es muy amigable");
    //se declara al personaje amistoso con un nombre descripcion y si esta dispuesto hablar
    Mundo parque("Patio");
    Mundo trono("Trono");
    Mundo carcel("Carcel"); //se crean tres objetis mundo con distintos nombres
    bool interactuoEnInfierno = false;// esta interaccion nos servira para terminar el juego 

    parque.setSiguienteMundo(trono);
    trono.setSiguienteMundo(carcel);       //se configuran los mundos y se asigan personajes
    trono.setPersonaje(odin);
    carcel.setPersonaje(personajeAmistoso);
    Mundo* mundoActual = &parque; //se crea un punto que apunta a parque esto indica que el jugador comenzara su aventura en parque 
    
    std::cout << "KINGDOM OF FREEDOM"<< std::endl;//Iniciamos el titulo y la introduccion del juego 
    std::cout << ""<< std::endl;
    std::cout << "Habiase una vez un reino propspero y feliz , hasta que un dia un rey malvado junto a su hechizero ,robo el trono y la miseria cayo en el reino "<< std::endl;
    std::cout << "Fue una epoca de terror,los que lo desafiaron sufrieron terribles consecuencias  "<< std::endl;
    std::cout << "¿Podras ser el guerrero que acabe con este regimen?  "<< std::endl;
    std::cout << ""<< std::endl;

    bool jugadorPerdio=false;// 
    char opcion;
     do {
        std::cout << "Estás en el mundo [" << mundoActual->getNombre() << "]" << std::endl;

        if (mundoActual == &parque) {
            std::cout << "Hay un personaje [" << guerrero.getNombre() << "]" << std::endl;
        } else {
            Personaje* personajeMundoActual = mundoActual->getPersonaje();
            if (personajeMundoActual != nullptr) {
                std::cout << "Hay un personaje [" << personajeMundoActual->getNombre() << "]" << std::endl;
            } else {
                std::cout << "No hay personaje en este mundo." << std::endl;
            }
        }

        if (jugador.getPuntosSaludActuales() <= 0) {
            jugadorPerdio = true;
            break;
        }

        std::cout << "Opciones disponibles:" << std::endl;
        std::cout << "1) Mostrar información del personaje" << std::endl;
        std::cout << "2) Mostrar inventario" << std::endl;
        std::cout << "3) Mostrar tienda" << std::endl;
        std::cout << "4) Comprar item" << std::endl;
        std::cout << "5) Mostrar puntos de vida" << std::endl;
        std::cout << "6) Interactuar" << std::endl;
        std::cout << "7) Salir" << std::endl;

        std::cin >> opcion;

        switch (opcion) {
            case '1':
                mostrarInformacionPersonaje(jugador);
                break;
            case '2':
                mostrarInventario(jugador);
                break;
            case '3':
                mostrarTienda();
                break;
            case '4': {
                int opcionItem;
                std::cout << "Selecciona el número del item que deseas comprar: ";
                std::cin >> opcionItem;
                comprarItem(jugador, opcionItem);
                break;
            }
            case '5':
                std::cout << "Porcentaje de salud: " << jugador.calcularPorcentajeSalud() << "%" << std::endl;
                std::cout << "Barra de vida: " << jugador.imprimirBarraVida() << std::endl;
                break;
            case '6':
                 if (mundoActual == &parque) {
                    std::cout << "Te encuentras en el patio del palacio rodeado de enemigos: "<<std::endl;
                    std::cout << ""<<std::endl;
                    interactuarConGuerrero(jugador, guerrero);

                    if (!guerrero.estaVivo()) {//verifica si el guerrero esta vivo la funcion esta vivo devuelve true o false 
                        mundoActual = mundoActual->getSiguienteMundo();//Si el jugador ha sido derrotado actualiza el puntero para el siguietne mundo 
                    }

                    if (jugador.getPuntosSaludActuales() <= 0) {
                        jugadorPerdio = true;
                    }
                } else if (mundoActual == &trono && trono.getPersonaje() != nullptr) {
                    std::cout << "Estas en el cuarto del trono estas apunto de enfrentarte al rey "<<std::endl;
                    std::cout << ""<<std::endl;
                    interactuarConGuerrero(jugador, odin);

                    if (!odin.estaVivo()) {
                        mundoActual = mundoActual->getSiguienteMundo();
                    }
                } else if (mundoActual == &carcel && carcel.getPersonaje() != nullptr) {
                    std::cout << "Te encuentras en los calabozos del reino ve a quien puedes liberar"<<std::endl;
                    std::cout << ""<<std::endl;
                    interactuarConAmigo(jugador, *mundoActual, interactuoEnInfierno);
                } else {
                    std::cout << "No hay personaje para interactuar aquí." << std::endl;
                }

                if (jugadorPerdio) {
                    std::cout << "¡Has perdido! las garras del mal triunfaron ." << std::endl;
                }
                if (interactuoEnInfierno) {
                std::cout << "" << std::endl;    
                std::cout << "Felicidades habil guerrero lograste derrotar al rey malvado ,liberar a panchito y  al pueblo de la exclavitud  ," << std::endl;
                std::cout << "Terminaste el juego  ," << std::endl;
                break; // Salimos del bucle si el jugador ha completado el juego
                }
                break;
             
            case '7':
                guardarDatosPersonaje(jugador);
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Selecciona otra opción." << std::endl;
                break;
            
        }

        
    } while (opcion != '7' && !jugadorPerdio && !interactuoEnInfierno);

    return 0;
}