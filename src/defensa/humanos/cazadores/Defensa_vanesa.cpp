#include "Defensa_vanesa.h"

Defensa_vanesa::Defensa_vanesa(Vanessa *personaje):Defensa_cazador(personaje){

}


void Defensa_vanesa::convertir_humano(Monstruo *personaje){

    char nombre_real = obtener_nombre(personaje->obtener_ID());

    if(es_tipo_humano(nombre_real)){

        personaje->asignar_nombre(nombre_real);

        delete personaje->obtener_ataque();
        personaje->asignar_ataque(nullptr);
        
        delete personaje->obtener_defensa();
        personaje->asignar_defensa(nullptr);
    }
}

void Defensa_vanesa::curar_aliados(Tablero *tablero){
    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return;

    Lista<Casilla*> casillas_curar = tablero->obtener_lista_casillas(obtener_cuadrado(centro,2)); 

    while(casillas_curar.existe_siguiente()){

        Lista<Objeto*> personajes_a_curar = casillas_curar.siguiente_dato()->obtener_objetos().filtrar_datos(0,es_tipo_monstruo);

        while(personajes_a_curar.existe_siguiente())
            convertir_humano((Monstruo*)personajes_a_curar.siguiente_dato());
    }
}

void Defensa_vanesa::defender(Tablero *tablero,int opcion){

    personaje->asignar_energia(personaje->obtener_energia()-10);

    if(((Humano*)personaje)->tiene_agua_bendita())
        curar_aliados(tablero);
    else if(!((Humano*)personaje)->tiene_cruz())
        personaje->asignar_vida(personaje->obtener_vida()+10);
}