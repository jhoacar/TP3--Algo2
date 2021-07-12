#include "jugador.h"

Jugador::Jugador(string nombre, string bando){

    this->nombre = nombre;
    this->bando = bando;
    datos_personajes = nullptr; 

}

Jugador::~Jugador(){

    delete datos_personajes;
    datos_personajes = nullptr;

}

string Jugador::obtener_nombre_jugador(){ return nombre; }

string Jugador::obtener_bando(){ return bando; }

void Jugador::guardar_datos_de_jugador(Lista<string> &datos){
   
    datos_personajes = new Lista<string>;
    string cant = " "+std::to_string(datos.obtener_tamano());

    datos_personajes->agregar(nombre);
    datos_personajes->agregar(bando+cant);
    *datos_personajes += datos;

}

Lista<string>* Jugador::obtener_datos_partida(){ return datos_personajes; }
