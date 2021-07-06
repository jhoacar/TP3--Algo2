#include "Camino.h"

Camino::Camino():Casilla(){

}
Camino::Camino(Coordenada posicion):Casilla(posicion){

}
Camino::~Camino(){

}
char Camino::obtener_tipo(){
    
    return TIPO_MAPA_CHAR[CAMINO];

}
int Camino::obtener_energia(int tipo_personaje){

    if(tipo_personaje>=0 && tipo_personaje<=MAX_TIPO_PERSONAJE)

        return ENERGIAS[tipo_personaje][CAMINO];
    
    else
        return NO_ENCONTRADO;
}

