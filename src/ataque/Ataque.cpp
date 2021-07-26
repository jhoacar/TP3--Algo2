#include "Ataque.h"
#include "../objetos/seres/Ser.h"

int extraer_cantidad(Objeto *objeto){
    if(objeto==nullptr)
        return 0;
    else
        return ((Elemento*)objeto)->obtener_cantidad();
}


Ataque::Ataque(Ser *personaje){
    this->personaje=personaje;
}
