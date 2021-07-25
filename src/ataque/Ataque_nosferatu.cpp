#include "Ataque_nosferatu.h"



Ataque_nosferatu::Ataque_nosferatu(Nosferatu *personaje): Ataque_vampiro(personaje){
}

Ataque_nosferatu::~Ataque_nosferatu(){
}


bool Ataque_nosferatu::validacion_rango_especifico(Casilla* casilla_a_atacar){

    bool validacion_rango;

    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();

    Lista<Coordenada> lista_casillas_posibles;
    lista_casillas_posibles = obtener_cuadrado(centro, 2);

    validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);

    return validacion_rango;
}

bool Ataque_nosferatu::validacion_rango_aleatorio(Tablero* tablero, Coordenada centro){

    bool validacion = false;

    Lista<Coordenada> lista_coordenadas;

    lista_coordenadas = obtener_cuadrado(centro, 2);
    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "humano");

    if(casilla_objeto != nullptr) {
        validacion = true;
    }
    return validacion;
}

Casilla* Ataque_nosferatu::devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro){

    Lista<Coordenada> lista_coordenadas;

    lista_coordenadas = obtener_cuadrado(centro, 2);

    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "humano");

    return casilla_objeto;

}

void Ataque_nosferatu::atacar(Casilla *casilla, Tablero* tablero) {

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
    ataque_validacion = validacion_ataque(6);

    if(validacion_rango && ataque_validacion){

        if(casilla == nullptr)
            casilla_en_tablero = devolver_casilla_aleatoria_en_tablero(tablero, centro);
        else
            casilla_en_tablero = devolver_casilla_especifica_en_tablero(tablero, casilla);

        int posicion;
        posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[HUMANO]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[HUMANO_CAZADOR]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[VANESA]);


        if(posicion != NO_ENCONTRADO){
            consumir_energia(6);
            bajar_vida(casilla_en_tablero);
        }
    }
}

void Ataque_nosferatu::verificar_transformacion_a_vampiro(int indice, Casilla* casilla){

    if((((Ser*) casilla -> obtener_objetos()[indice]) ->devolver_vida()) <= 30)
        ((Ser*) casilla -> obtener_objetos()[indice]) -> asignar_nombre(NOMBRES_CHAR[VAMPIRO]);
}


void Ataque_nosferatu::bajar_vida(Casilla* casilla){

    int indice_humano = indice_personaje(NOMBRES_CHAR[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_CHAR[HUMANO_CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_CHAR[VANESA], casilla);


    if(indice_humano != NO_ENCONTRADO) {
        calcular_valores_ataque(indice_humano, 100, casilla);
        verificar_transformacion_a_vampiro(indice_humano, casilla);
    }
    if(indice_cazador != NO_ENCONTRADO) {
        calcular_valores_ataque(indice_cazador, 100, casilla);
        verificar_transformacion_a_vampiro(indice_cazador, casilla);
    }
    if(indice_vanesa != NO_ENCONTRADO) {
        calcular_valores_ataque(indice_vanesa, 100, casilla);
        verificar_transformacion_a_vampiro(indice_vanesa, casilla);
    }
}

