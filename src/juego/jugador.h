#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>
#include "../objetos/Objeto.h"
#include "../mapa/Casilla.h"
#include "../objetos/seres/Ser.h"
#include "../objetos/elementos/Elemento.h"
#include "../funcionalidades/tda/Lista.h"
#include "../funcionalidades/Funciones.h"
#include "../funcionalidades/Includes_Objetos.h"

using namespace std;


class Jugador {

private:
    int num_jugador;
    string bando;
    int cantidad_pjs;
    Lista<Objeto*> datos_personajes;

public:

    Jugador(int num, string bando);

    ~Jugador();

    // PRE: una lista con los datos de los personajes del bando del jugador
    // POST: se guarda la cantidad de personajes, y los datos en una lista.
    void guardar_personajes_de_jugador(Lista<Objeto*> &datos);

    //POST: retorna el numero asignado al jugador (1 o 2)
    int obtener_numero_jugador();

    // POST: retorna el bando del jugador
    string obtener_bando();

    // POST: devuelve una lista con los datos de los personajes
    Lista<Objeto*> obtener_datos_personajes();
    
};

#endif