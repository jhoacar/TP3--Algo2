#include "Lago.h"

Lago::Lago():Casilla(){

}
Lago::Lago(Coordenada posicion):Casilla(posicion){

}
Lago::~Lago(){

}
char Lago::obtener_tipo(){
    
    return TIPO_MAPA_CHAR[LAGO];

}
int Lago::obtener_energia(int tipo_personaje){

    if(tipo_personaje>=0 && tipo_personaje <= (int)MAX_TIPO_PERSONAJE)

        return ENERGIAS[tipo_personaje][LAGO];
    
    else
        return NO_ENCONTRADO;
}

