#include "Ataque_monstruo.h"

Ataque_monstruo::Ataque_monstruo(Monstruo *personaje):Ataque(personaje){

}
void Ataque_monstruo::atacar(Coordenada posicion, Tablero *tablero, char arma){

    atacar_casilla(tablero->obtener_casilla(posicion));

    consumir_energia();
}
bool Ataque_monstruo::se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma){
    return  tiene_energia() &&
            esta_en_rango_ataque(posicion) &&
            tiene_humano(tablero->obtener_casilla(posicion));    
}