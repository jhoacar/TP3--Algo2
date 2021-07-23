#include "jugador.h"

Jugador::Jugador(string bando){
    this->bando = bando;

}

Jugador::~Jugador(){

}

string Jugador::obtener_bando(){ return bando; }

void Jugador::guardar_datos_de_jugador(int numero_jugador, Lista<string> &datos){
   
    string cant_pjs = " "+std::to_string(datos.obtener_tamano());

    datos_personajes.agregar(std::to_string(numero_jugador));
    datos_personajes.agregar(bando+cant_pjs);
    datos_personajes+=datos;

}

Lista<string> Jugador::obtener_datos_partida(){ return datos_personajes; }
