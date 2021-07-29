#ifndef ARCHIVO_PARTIDA_H
#define ARCHIVO_PARTIDA_H

#include "Archivo.h"
#include "../mapa/Tablero.h"
#include "../funcionalidades/Includes_Objetos.h"
#include "../funcionalidades/tda/Lista.h"
#include "../juego/jugador.h"
#include "../funcionalidades/tda/Diccionario.h"

const string SALTO_LINEA = "\n";
const string ESPACIO = " ";
const string ITEMS = "items";

class Archivo_partida : Archivo {

    private:
    string contenido_jugador;
    string contenido_obhetos;
    Diccionario<string,Objeto*> objetos;

public:

    Archivo_partida(const string nombre_fichero);
    
    void cargar_datos_de_partida(Tablero* tablero, Jugador* jugador1, Jugador* jugador2);
    //PRE: recibe 2 punteros a Jugador y una Lista de Objetos
    //POST: Genera un archivo y graba en el todos los datos que se reciben en un archivo
    void guardar_partida(Jugador* jugador1, Jugador* jugador2, Lista<Objeto*> &objetos);
    //PRE: recibe un puntero a Jugador y un booleano
    // POST: retorna un string con todos los datos de partida del jugador
    string obtener_contenido_datos_jugador(Jugador* jugador, bool guardo_el_juego);
    //PRE: recibe una Lista de Objeto
    // POST: retorna un string con todos los datos de los objetos de la partida
    string obtener_contenido_objetos(Lista<Objeto*> &objetos);

private:

    void cargar_jugadores(Tablero* tablero, Jugador* jugador1, Jugador* jugador2, Lista<string> &lineas);
    
    Objeto* cargar_personaje(Tablero* tablero, Lista<string> &datos);

    Objeto* crear_objeto(const int tipo_objeto,const char nombre,Casilla *casilla, int cantidad, string ID);

    void cargar_elemento(Tablero* tablero, Lista<string> &datos);
    // PRE: recibe un puntero a Ser y un string.
    // POST: guarda los "atributos fisicos" de un Ser en un string
    void grabar_estatus(Ser* ente);
    // PRE: recibe un puntero a Ser y un string
    // POST: guarda las coordenadas del Ser en un string
    void grabar_posicion(Ser* ente);
    // PRE: recibe un puntero a Ser y un string
    // POST: guarda las cantidades de objetos del ser en un string
    void grabar_objetos(Ser* ente);
    // PRE: recibe un puntero a Elemento, un entero, y 5 strings pasados por referencia.
    // POST: guarda la cantidad de cada elemento en un string
    void grabar_cantidad(Elemento* objeto, int tipo, string &agua, string &cruz, string &estaca, string &escopeta,string &bala);
};

#endif