#include "Defensa_humano.h"



Defensa_humano::Defensa_humano(Humano *humano):Defensa(humano){

}

void Defensa_humano::defender(Tablero *tablero, int opcion){

    if(!((Humano*)personaje)->tiene_agua_bendita())
        personaje->asignar_energia(personaje->obtener_energia()+3);
    else if(opcion == OPCION_REGENERAR_ENERGIA)
        personaje->asignar_energia(ENERGIA_MAXIMA);
    else if(opcion == OPCION_AUMENTAR_ARMADURA)
        personaje->asignar_armadura(personaje->obtener_armadura()+1);
    
}