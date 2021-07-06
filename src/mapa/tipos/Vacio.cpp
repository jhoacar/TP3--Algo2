#include "Vacio.h"

Vacio::Vacio():Casilla(){

}
Vacio::Vacio(Coordenada posicion):Casilla(posicion){

}
Vacio::~Vacio(){

}
char Vacio::obtener_tipo(){
    
    return TIPO_MAPA_CHAR[VACIO];

}
int Vacio::obtener_energia(int tipo_personaje){

    if(tipo_personaje>=0 && tipo_personaje<= (int)MAX_TIPO_PERSONAJE)

        return ENERGIAS[tipo_personaje][VACIO];
    
    else
        return NO_ENCONTRADO;
}

