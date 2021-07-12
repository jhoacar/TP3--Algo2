#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>
#include "../funcionalidades/Lista.h"

using namespace std;


class Jugador {

private:

    string nombre;
    string bando;
    Lista<string>* datos_personajes;

public:

    Jugador(string nombre, string bando);

    ~Jugador();

    // POST: retorna el nombre del juador
    string obtener_nombre_jugador();
    
    // POST: retorna el bando del jugador
    string obtener_bando();

    // PRE: un puntero a una lista con los datos 
    // de los personajes del bando del jugador
    // POST: se guardan los datos en una lista junto con el nombre y bando del jugador.
    void guardar_datos_de_jugador(Lista<string> &datos);

    // POST: devuelve una lista con todos los datos del jugador y los datos de partida
    Lista<string>* obtener_datos_partida();

    
};

#endif