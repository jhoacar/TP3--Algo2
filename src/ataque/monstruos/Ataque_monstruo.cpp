#include "Ataque_monstruo.h"

Ataque_monstruo::Ataque_monstruo(Monstruo *personaje):Ataque(personaje){

}
void Ataque_monstruo::atacar(Coordenada posicion, Tablero *tablero, char arma){

    atacar_casilla(tablero->obtener_casilla(posicion));

    consumir_energia();
}
int Ataque_monstruo::se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma){
    int validador_ataque = 0;

    if (!tiene_energia())
        validador_ataque = 1;

    else if (!esta_en_rango_ataque(posicion))
        validador_ataque = 2;

    else if (tiene_monstruo(tablero->obtener_casilla(posicion)))
        validador_ataque = 3;



    return  validador_ataque;
}