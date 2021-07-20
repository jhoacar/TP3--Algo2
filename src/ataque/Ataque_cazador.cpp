#include "Ataque_cazador.h"


Ataque_cazador::Ataque_cazador(Cazador *personaje): Ataque_humano(personaje){
}

Ataque_cazador::~Ataque_cazador(){
}


bool Ataque_cazador::validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida){


    bool validacion_ataque = false;
    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();
    Lista<Coordenada> lista_casillas_posibles;
    bool tiene_suficientes_balas;

    if(arma_elegida == NOMBRES_STRING[ESCOPETA]) {
        lista_casillas_posibles = obtener_cuadrado(centro, 2);
        tiene_suficientes_balas = tiene_balas(2);
    }
    else if(arma_elegida == NOMBRES_STRING[AGUA])
        lista_casillas_posibles = obtener_cuadrado(centro, 1);
    else if(arma_elegida == NOMBRES_STRING[ESTACA])
        lista_casillas_posibles = obtener_cruz(centro, 1);

    bool validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);
    bool energia_suficiente_ = energia_suficiente(6);
    bool tiene_arma_ = tiene_arma(arma_elegida);

    if(arma_elegida == NOMBRES_STRING[ESCOPETA]) {
        if (validacion_rango && energia_suficiente_ && tiene_arma_ && tiene_suficientes_balas)
            validacion_ataque = true;
    }
    else{
        if (validacion_rango && energia_suficiente_ && tiene_arma_)
            validacion_ataque = true;
    }

    return validacion_ataque;
}

void Ataque_cazador::atacar(Casilla *casilla) {


    string arma_elegida = eleccion_arma();
    bool validacion = validacion_ataque(casilla, arma_elegida);

    if(validacion){

        Lista<Objeto*> lista_objetos = casilla -> obtener_objetos();

        int posicion;

        posicion = buscar_personaje(casilla, NOMBRES_STRING[ZOMBIE]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRO]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRELLA]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[NOSFERATU]);

        if(posicion != NO_ENCONTRADO){
            consumir_energia(5);

            bajar_cantidad_objeto(arma_elegida);
            bajar_vida(casilla, arma_elegida);
        }
    }
}


void Ataque_cazador::bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, int porcentaje_estaca, Casilla* casilla, string arma_elegida){

    if (arma_elegida == NOMBRES_STRING[ESCOPETA])
        calcular_valores_ataque(indice, porcentaje_escopeta, casilla);
    else if (arma_elegida == NOMBRES_STRING[ESTACA])
        calcular_ataque_valores_fijos(indice, porcentaje_agua, casilla);
    else if (arma_elegida == NOMBRES_STRING[AGUA])
        calcular_ataque_valores_fijos(indice, porcentaje_estaca, casilla);
}


void Ataque_cazador::bajar_vida(Casilla* casilla, string arma_elegida){

    int indice_zombie = indice_personaje(NOMBRES_STRING[ZOMBIE], casilla);
    int indice_vampiro = indice_personaje(NOMBRES_STRING[VAMPIRO], casilla);
    int indice_nosferatu = indice_personaje(NOMBRES_STRING[NOSFERATU], casilla);
    int indice_vampirella = indice_personaje(NOMBRES_STRING[VAMPIRELLA], casilla);

    if(indice_zombie != NO_ENCONTRADO) {
        if (arma_elegida == NOMBRES_STRING[ESCOPETA])
            calcular_valores_ataque(indice_zombie, 105, casilla);
        else if (arma_elegida == NOMBRES_STRING[ESTACA])
            calcular_valores_ataque(indice_zombie, 20, casilla);
    }
    if(indice_vampiro != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_vampiro, 30, 10, 60, casilla, arma_elegida);
    if(indice_nosferatu != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_nosferatu, 30, 10, 60, casilla, arma_elegida);
    if(indice_vampirella != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_vampirella, 30, 10, 60, casilla, arma_elegida);
}

