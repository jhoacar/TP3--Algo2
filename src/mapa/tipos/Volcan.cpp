#include "Volcan.h"

Volcan::Volcan():Casilla(){

}
Volcan::Volcan(Coordenada posicion):Casilla(posicion){

}
Volcan::~Volcan(){

}
char Volcan::obtener_tipo(){
    
    return TIPO_MAPA_CHAR[VOLCAN];

}
int Volcan::obtener_energia(int tipo_personaje){

    if(tipo_personaje>=0 && tipo_personaje<=MAX_TIPO_PERSONAJE)

        return ENERGIAS[tipo_personaje][VOLCAN];
    
    else
        return NO_ENCONTRADO;
}

