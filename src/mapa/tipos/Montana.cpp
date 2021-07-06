#include "Montana.h"

Montana::Montana():Casilla(){

}
Montana::Montana(Coordenada posicion):Casilla(posicion){

}
Montana::~Montana(){

}
char Montana::obtener_tipo(){
    
    return TIPO_MAPA_CHAR[MONTANA];

}
int Montana::obtener_energia(int tipo_personaje){

    if(tipo_personaje>=0 && tipo_personaje<=MAX_TIPO_PERSONAJE)

        return ENERGIAS[tipo_personaje][MONTANA];
    
    else
        return NO_ENCONTRADO;
}

