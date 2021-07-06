#include "Precipicio.h"

Precipicio::Precipicio():Casilla(){

}
Precipicio::Precipicio(Coordenada posicion):Casilla(posicion){

}
Precipicio::~Precipicio(){

}
char Precipicio::obtener_tipo(){
    
    return TIPO_MAPA_CHAR[PRECIPICIO];

}
int Precipicio::obtener_energia(int tipo_personaje){

    if(tipo_personaje>=0 && tipo_personaje<=MAX_TIPO_PERSONAJE)

        return ENERGIAS[tipo_personaje][PRECIPICIO];
    
    else
        return NO_ENCONTRADO;
}

