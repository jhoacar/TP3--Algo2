#include "Ataque_cazador.h"


Ataque_cazador::Ataque_cazador(Cazador *personaje): Ataque_humano(personaje){
}

/*Ataque_cazador::~Ataque_cazador(){
}*/


bool Ataque_cazador::validacion_atacar_personaje(Casilla *casilla, Tablero* tablero){return true;}

bool Ataque_cazador::validacion_atacar_personaje(Casilla *casilla, Tablero* tablero, char arma){

    Coordenada centro = personaje->obtener_casilla()->obtener_posicion();
    bool ataque_validacion;
    bool validacion_rango;
    bool validacion = false;

    if(casilla == nullptr)
        validacion_rango = validacion_rango_aleatorio(tablero, centro, arma, 2);
    else {
        Casilla *casilla_elegida = tablero->obtener_casilla(casilla->obtener_posicion());
        validacion_rango = validacion_rango_especifico(casilla_elegida, arma, 2);
    }
    ataque_validacion = validacion_ataque( arma, 6);

    if(validacion_rango && ataque_validacion)
        validacion = true;

    return validacion;

}


void Ataque_cazador::atacar(Casilla *casilla, Tablero* tablero, char arma) {

    Coordenada centro = personaje->obtener_casilla()->obtener_posicion();
    Casilla* casilla_en_tablero;

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
        consumir_energia(6);
        bajar_cantidad_objeto(arma);
        bajar_vida(casilla_en_tablero, arma);
    }
}





void Ataque_cazador::bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, int porcentaje_estaca, Casilla* casilla, char arma_elegida){

    if (arma_elegida == NOMBRES_CHAR[ESCOPETA])
        calcular_valores_ataque(indice, porcentaje_escopeta, casilla);
    else if (arma_elegida == NOMBRES_CHAR[ESTACA])
        calcular_ataque_valores_fijos(indice, porcentaje_estaca, casilla);
    else if (arma_elegida == NOMBRES_CHAR[AGUA])
        calcular_ataque_valores_fijos(indice, porcentaje_agua, casilla);
}


void Ataque_cazador::bajar_vida(Casilla* casilla, char arma_elegida){

    int indice_zombie = indice_personaje(NOMBRES_CHAR[ZOMBIE], casilla);
    int indice_vampiro = indice_personaje(NOMBRES_CHAR[VAMPIRO], casilla);
    int indice_nosferatu = indice_personaje(NOMBRES_CHAR[NOSFERATU], casilla);
    int indice_vampirella = indice_personaje(NOMBRES_CHAR[VAMPIRELLA], casilla);

    if(indice_zombie != NO_ENCONTRADO) {
        if (arma_elegida == NOMBRES_CHAR[ESCOPETA])
            calcular_valores_ataque(indice_zombie, 105, casilla);
        else if (arma_elegida == NOMBRES_CHAR[ESTACA])
            calcular_valores_ataque(indice_zombie, 20, casilla);
    }
    if(indice_vampiro != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_vampiro, 30, 10, 60, casilla, arma_elegida);
    else if(indice_nosferatu != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_nosferatu, 30, 10, 60, casilla, arma_elegida);
    else if(indice_vampirella != NO_ENCONTRADO)
        bajar_vida_vampiro(indice_vampirella, 30, 10, 60, casilla, arma_elegida);
}



