#include "Ataque_nosferatu.h"



Ataque_nosferatu::Ataque_nosferatu(Nosferatu *personaje): Ataque_vampiro(personaje){
}

Ataque_nosferatu::~Ataque_nosferatu(){
}


void Ataque_nosferatu::atacar(Casilla *casilla) {

    bool validacion = validacion_ataque(casilla);

    if(validacion){

        Lista<Objeto*> lista_objetos = casilla -> obtener_objetos();

        int posicion;
        posicion = buscar_personaje(casilla, NOMBRES_STRING[HUMANO]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[HUMANO_CAZADOR]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VANESA]);

        if(posicion != NO_ENCONTRADO){
            consumir_energia(6);
            bajar_vida(casilla);
        }
    }
}


bool Ataque_nosferatu::validacion_ataque(Casilla *casilla_a_atacar){

    bool validacion_ataque;

    Casilla* casilla_personaje = personaje -> obtener_casilla();
    Coordenada centro = casilla_personaje -> obtener_posicion();

    Lista<Coordenada> lista_casillas_posibles = obtener_cuadrado(centro, 2);

    bool validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);
    bool energia_suficiente_ = energia_suficiente(6);


    if(validacion_rango && energia_suficiente_)
        validacion_ataque = true;
    else
        validacion_ataque = false;

    return validacion_ataque;
}


void Ataque_nosferatu::bajar_vida(Casilla* casilla){

    int indice_humano = indice_personaje(NOMBRES_STRING[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_STRING[HUMANO_CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_STRING[VANESA], casilla);


    if(indice_humano != NO_ENCONTRADO)
        calcular_valores_ataque(indice_humano, 100, casilla);
    if(indice_cazador != NO_ENCONTRADO)
        calcular_valores_ataque(indice_cazador, 100, casilla);
    if(indice_vanesa != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vanesa, 100, casilla);

}