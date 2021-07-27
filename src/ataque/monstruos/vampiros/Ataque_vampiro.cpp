#include "Ataque_vampiro.h"

Ataque_vampiro::Ataque_vampiro(Vampiro *personaje):Ataque(personaje){

}

void Ataque_vampiro::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[VAMPIRO]);
}


bool Ataque_vampiro::puede_atacar(){
    return personaje->obtener_energia()>=GASTO_ENERGIA[VAMPIRO];
}

void Ataque_vampiro::atacar(Coordenada posicion, Tablero *tablero, char arma){

    atacar_casilla(tablero->obtener_casilla(posicion));

    consumir_energia();
}
bool Ataque_vampiro::esta_en_rango_ataque(Coordenada posicion,char arma){
    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return false;
    else
        return obtener_cruz(centro,1).existe(posicion);
}

bool Ataque_vampiro::se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma){
    return  puede_atacar() &&
            esta_en_rango_ataque(posicion) &&
            tiene_humano(tablero->obtener_casilla(posicion));    
}

bool Ataque_vampiro::hay_casos_especiales(Humano *humano){
    return humano->obtener_nombre()==NOMBRES_CHAR[VANESA] && humano->tiene_cruz();
}

void Ataque_vampiro::atacar_casilla(Casilla *casilla_ataque){

    Humano *humano =  (Humano*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_humano)[0];

    if(hay_casos_especiales(humano))
        return;

    int vida_nueva = humano->obtener_vida() - (int)(((float)personaje->obtener_fuerza())*obtener_armadura(humano));

    humano->asignar_vida(vida_nueva);
}