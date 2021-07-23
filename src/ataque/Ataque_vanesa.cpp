#include "Ataque_vanesa.h"

Ataque_vanesa::Ataque_vanesa(Humano *personaje):Ataque_humano(personaje){
}

Ataque_vanesa::~Ataque_vanesa(){
}

/*
bool Ataque_vanesa::validacion_ataque(Casilla *casilla_a_atacar, char arma_elegida){

    bool validacion_ataque = false;
    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();
    Lista<Coordenada> lista_casillas_posibles;
    bool tiene_suficientes_balas;

    if(arma_elegida == NOMBRES_CHAR[ESCOPETA]) {
        lista_casillas_posibles = obtener_cuadrado(centro, 2);
        tiene_suficientes_balas = tiene_balas(2);
    }
    else if(arma_elegida == NOMBRES_CHAR[AGUA])
        lista_casillas_posibles = obtener_cuadrado(centro, 1);
    else if(arma_elegida == NOMBRES_CHAR[ESTACA])
        lista_casillas_posibles = obtener_cruz(centro, 1);

    bool validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);
    bool energia_suficiente_ = energia_suficiente(8);
    bool tiene_arma_ = tiene_arma(arma_elegida);
    bool mounstruo_oculto = validacion_mounstruo_oculto(casilla_a_atacar, arma_elegida);

    if(arma_elegida == NOMBRES_CHAR[ESCOPETA]) {
        if (validacion_rango && energia_suficiente_ && tiene_arma_ && !mounstruo_oculto && tiene_suficientes_balas)
            validacion_ataque = true;
    }
    else{
        if (validacion_rango && energia_suficiente_ && tiene_arma_ && !mounstruo_oculto)
            validacion_ataque = true;
    }

    return validacion_ataque;
}
*/

void Ataque_vanesa::bajar_vida_completa(int indice, Casilla *casilla){

    int valor_final;
    int vida = ((Ser*)casilla -> obtener_objetos()[indice]) -> devolver_vida();
    valor_final = calcular_vida_con_armadura(vida);

    ((Ser*)casilla -> obtener_objetos()[indice]) -> bajar_vida(valor_final);
}


void Ataque_vanesa::bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, Casilla* casilla, char arma_elegida){

    if (arma_elegida == NOMBRES_CHAR[ESCOPETA])
        calcular_valores_ataque(indice, porcentaje_escopeta, casilla);
    else if (arma_elegida == NOMBRES_CHAR[AGUA])
        calcular_ataque_valores_fijos(indice, porcentaje_agua, casilla);
    else if (arma_elegida == NOMBRES_CHAR[ESTACA])
        bajar_vida_completa(indice, casilla);
}


void Ataque_vanesa::bajar_vida(Casilla* casilla, char arma_elegida){

    int indice_zombie = indice_personaje(NOMBRES_CHAR[ZOMBIE], casilla);
    int indice_vampiro = indice_personaje(NOMBRES_CHAR[VAMPIRO], casilla);
    int indice_nosferatu = indice_personaje(NOMBRES_CHAR[NOSFERATU], casilla);
    int indice_vampirella = indice_personaje(NOMBRES_CHAR[VAMPIRELLA], casilla);

    if(indice_zombie != NO_ENCONTRADO) {
        if (arma_elegida == NOMBRES_CHAR[ESCOPETA])
            calcular_valores_ataque(indice_zombie, 125, casilla);
        else if (arma_elegida == NOMBRES_CHAR[ESTACA])
            calcular_valores_ataque(indice_zombie, 25, casilla);
    }
    if(indice_vampiro != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_vampiro, 40, 20, casilla, arma_elegida);
    if(indice_nosferatu != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_nosferatu, 40, 20, casilla, arma_elegida);
    if(indice_vampirella != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_vampirella, 40, 20, casilla, arma_elegida);
}

void Ataque_vanesa::atacar(Casilla *casilla, Tablero* tablero, char arma){

    Coordenada centro = personaje->obtener_casilla()->obtener_posicion();
    bool ataque_validacion;
    bool validacion_rango;
    Lista<Objeto*> lista_objetos;

    Casilla* casilla_en_tablero;

    if(casilla == nullptr)
        validacion_rango = validacion_rango_aleatorio(tablero, centro, arma, 2);
    else {
        Casilla *casilla_elegida = tablero->obtener_casilla(casilla->obtener_posicion());
        validacion_rango = validacion_rango_especifico(casilla_elegida, arma, 2);
    }
    ataque_validacion = validacion_ataque( arma, 8);

    if(validacion_rango && ataque_validacion){

        if(casilla == nullptr)
            casilla_en_tablero = devolver_casilla_aleatoria_en_tablero(tablero, centro, arma, 2);
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
            consumir_energia(8);
            bajar_cantidad_objeto(arma);
            bajar_vida(casilla_en_tablero, arma);
        }
    }
}
