#include "Ataque.h"
#include "../objetos/seres/Ser.h"

int extraer_cantidad(Objeto *objeto){
    if(objeto==nullptr)
        return 0;
    else
        return ((Elemento*)objeto)->obtener_cantidad();
}
bool tiene_monstruo(Casilla *casilla){
    if(casilla == nullptr)
        return false;
    else
        return casilla->obtener_objetos().filtrar_datos(0,es_tipo_monstruo).obtener_tamano()!=0;
}

bool tiene_humano(Casilla *casilla){
    if(casilla == nullptr)
        return false;
    else
        return casilla->obtener_objetos().filtrar_datos(0,es_tipo_humano).obtener_tamano()!=0;
}



Ataque::Ataque(Ser *personaje){
    this->personaje=personaje;
}
