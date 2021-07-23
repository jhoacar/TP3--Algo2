#include "Ataque_vampiro.h"


Ataque_vampiro::Ataque_vampiro(Vampiro *personaje): Ataque(personaje){
}

Ataque_vampiro::~Ataque_vampiro(){
}

bool Ataque_vampiro::validacion_ataque(int energia){
    return energia_suficiente(energia);
}


Casilla* Ataque_vampiro::devolver_casilla_especifica_en_tablero(Tablero* tablero, Casilla* casilla){
    Casilla* casilla_atacar = tablero->obtener_casilla(casilla->obtener_posicion());
    return casilla_atacar;
}

bool Ataque_vampiro::validacion_rango_especifico(Casilla* casilla_a_atacar){

    bool validacion_rango;

    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();

    Lista<Coordenada> lista_casillas_posibles;
    lista_casillas_posibles = obtener_cruz(centro, 1);

    validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);

    return validacion_rango;
}

bool Ataque_vampiro::validacion_rango_aleatorio(Tablero* tablero, Coordenada centro){

    bool validacion = false;

    Lista<Coordenada> lista_coordenadas;

    lista_coordenadas = obtener_cruz(centro, 1);
    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "humano");

    if(casilla_objeto != nullptr) {
        validacion = true;
    }
    return validacion;
}

Casilla* Ataque_vampiro::devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro){

    Lista<Coordenada> lista_coordenadas;

    lista_coordenadas = obtener_cruz(centro, 1);

    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "humano");

    return casilla_objeto;

}


void Ataque_vampiro::atacar(Casilla *casilla, Tablero* tablero) {

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
            consumir_energia(2);
            bajar_vida(casilla_en_tablero);
        }
    }
}

void Ataque_vampiro::atacar(Casilla *casilla, Tablero *tablero, char arma) {
}



void Ataque_vampiro::bajar_vida(Casilla* casilla){

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


