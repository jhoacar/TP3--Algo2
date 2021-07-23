#include "Ataque_vampirella.h"


Ataque_vampirella::Ataque_vampirella(Vampirella *personaje): Ataque_vampiro(personaje){
}

Ataque_vampirella::~Ataque_vampirella(){
}

void Ataque_vampirella::atacar(Casilla *casilla, Tablero*tablero) {

    Coordenada centro = personaje->obtener_casilla()->obtener_posicion();
    bool ataque_validacion;
    bool validacion_rango;
    Lista<Objeto*> lista_objetos;

    Casilla* casilla_en_tablero;

    if(casilla == nullptr)
        validacion_rango = validacion_rango_aleatorio(tablero, centro);
    else {
        Casilla *casilla_elegida = tablero->obtener_casilla(casilla->obtener_posicion());
        validacion_rango = validacion_rango_especifico(casilla_elegida);
    }
    ataque_validacion = validacion_ataque(personaje->devolver_energia());

    if(validacion_rango && ataque_validacion){

        if(casilla == nullptr)
            casilla_en_tablero = devolver_casilla_aleatoria_en_tablero(tablero, centro);
        else
            casilla_en_tablero = devolver_casilla_especifica_en_tablero(tablero, casilla);

        int posicion;
        posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[ZOMBIE]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[VAMPIRO]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[VAMPIRELLA]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[NOSFERATU]);

        if(posicion != NO_ENCONTRADO){
            consumir_energia(4);
            bajar_vida(casilla_en_tablero);
        }
    }
}



void Ataque_vampirella::bajar_vida(Casilla* casilla){

    int indice_humano = indice_personaje(NOMBRES_CHAR[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_CHAR[HUMANO_CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_CHAR[VANESA], casilla);


    if(indice_humano != NO_ENCONTRADO)
        calcular_valores_ataque(indice_humano, 100, casilla);
    if(indice_cazador != NO_ENCONTRADO)
        calcular_valores_ataque(indice_cazador, 100, casilla);
    if(indice_vanesa != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vanesa, 100, casilla);

}


