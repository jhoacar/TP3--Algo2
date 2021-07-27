#include "Defensa_nosferatu.h"

Defensa_nosferatu::Defensa_nosferatu(Nosferatu *personaje):Defensa_vampiro(personaje){

}

Lista<Objeto*> Defensa_nosferatu::obtener_vampiros(Tablero *tablero){
    
    Lista<Objeto*> vampiros_posibles;
    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return vampiros_posibles;

    Lista<Casilla*> casillas = tablero->obtener_lista_casillas(obtener_cuadrado(centro,2));
    while(casillas.existe_siguiente())
        vampiros_posibles+=casillas.siguiente_dato()->obtener_objetos(NOMBRES_CHAR[VAMPIRO]);
    return vampiros_posibles;
}


void Defensa_nosferatu::intercambiar_vida(Tablero *tablero){

    Lista<Objeto*> vampiros_posibles = obtener_vampiros(tablero);

    bool intercambiado=false;

    while(vampiros_posibles.existe_siguiente() && !intercambiado){
        Vampiro *vampiro = (Vampiro*)vampiros_posibles.siguiente_dato();
        
        if(vampiro->obtener_vida()>personaje->obtener_vida()){
            
            int vida_nueva = vampiro->obtener_vida();
            vampiro->asignar_vida(personaje->obtener_vida());
            personaje->asignar_vida(vida_nueva);
            intercambiado=true;
        }
    }
}


void Defensa_nosferatu::defender(Tablero *tablero, int opcion){

    personaje->asignar_energia(personaje->obtener_energia()-10);

    intercambiar_vida(tablero);
    
}