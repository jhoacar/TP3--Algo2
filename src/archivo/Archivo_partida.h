#ifndef ARCHIVO_PARTIDA_H
#define ARCHIVO_PARTIDA_H

#include "Archivo.h"
#include "../mapa/Tablero.h"
#include "../funcionalidades/Includes_Objetos.h"
#include "../funcionalidades/tda/Lista.h"
#include "../juego/jugador.h"

const string SALTO_LINEA = "\n";
const string ESPACIO = " ";
const string ITEMS = "items";

class Archivo_partida : Archivo {

    private:
    Tablero* mapa_guardado;
    string contenido_jugador;
    string contenido_obhetos;

public:

    Archivo_partida(const string nombre_fichero);

    Archivo_partida();

    //POST: lee un archivo con los datos de la partida guardada, y retorna un puntero a una lista
    //con los datos del archivo en orden a medida que se leen de el mismo;
    Tablero* obtener_datos_de_partida();

    //PRE: recibe 2 punteros a Jugador y una Lista de Objetos
    //POST: Genera un archivo y graba en el todos los datos que se reciben en un archivo
    void guardar_partida(Jugador* jugador1, Jugador* jugador2, Lista<Objeto*> objetos);

    // POST: retorna un string con todos los datos de partida del jugador
    string obtener_contenido_datos_jugador(Jugador* jugador, bool guardo_el_juego);

    string obtener_contenido_objetos(Lista<Objeto*> objetos);

private:

    // PRE: recibe un puntero a Elemento, un entero, y 5 strings pasados por referencia.
    // POST: guarda la cantidad de cada elemento en un string
    void asignar_cantidad(Elemento* objeto, int tipo, string &agua, string &cruz, string &estaca, string &escopeta,string &bala);

    // PRE: recibe un puntero a Ser y un string.
    // POST: guarda los "atributos fisicos" de un Ser en un string
    void asignar_estatus(Ser* ente);

    // PRE: recibe un puntero a Ser y un string
    // POST: guarda las coordenadas del Ser en un string
    void asignar_posicion(Ser* ente);

    // PRE: recibe un puntero a Ser y un string
    // POST: guarda las cantidades de objetos del ser en un string
    void asignar_objetos(Ser* ente);

};

#endif