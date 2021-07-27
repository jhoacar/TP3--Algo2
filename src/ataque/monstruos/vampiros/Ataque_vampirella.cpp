#include "Ataque_vampirella.h"

Ataque_vampirella::Ataque_vampirella(Vampirella *personaje):Ataque_vampiro(personaje){

}
void Ataque_vampirella::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[VAMPIRELLA]);
}

bool Ataque_vampirella::puede_atacar(){
    return personaje->obtener_energia()>=GASTO_ENERGIA[VAMPIRELLA];
}

bool Ataque_vampirella::se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma){
    return  puede_atacar() &&
            esta_en_rango_ataque(posicion) &&
            tiene_humano(tablero->obtener_casilla(posicion));    
}
void Ataque_vampirella::atacar(Coordenada posicion, Tablero *tablero,char arma){
    atacar_casilla(tablero->obtener_casilla(posicion));
    consumir_energia();
}

