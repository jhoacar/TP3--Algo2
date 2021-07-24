#include "jugador.h"

Jugador::Jugador(int num, string bando){
    this->num_jugador = num;
    this->bando = bando;
    this->cantidad_pjs = 0;
}

Jugador::~Jugador(){
    num_jugador = 0;
    bando = "";
    cantidad_pjs = 0;
}

void Jugador::guardar_personajes_de_jugador(Lista<Objeto*> &datos){
    datos_personajes=datos;
    cantidad_pjs = datos.obtener_tamano();
}

int Jugador::obtener_numero_jugador(){ return num_jugador; }

string Jugador::obtener_bando(){ return bando; }

Lista<Objeto*> Jugador::obtener_datos_personajes(){ return datos_personajes; }