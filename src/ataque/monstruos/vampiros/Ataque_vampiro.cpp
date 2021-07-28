#include "Ataque_vampiro.h"

bool hay_casos_especiales(Humano *humano){
    return humano->obtener_nombre()==NOMBRES_CHAR[VANESA] && humano->tiene_cruz();
}

Ataque_vampiro::Ataque_vampiro(Vampiro *personaje):Ataque_monstruo(personaje){

}

void Ataque_vampiro::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[VAMPIRO]);
}


bool Ataque_vampiro::tiene_energia(){
    return personaje->obtener_energia()>=GASTO_ENERGIA[VAMPIRO];
}


bool Ataque_vampiro::esta_en_rango_ataque(Coordenada posicion,char arma){
    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return false;
    else
        return obtener_cruz(centro,1).existe(posicion);
}


void Ataque_vampiro::atacar_casilla(Casilla *casilla_ataque, char arma){

    Humano *humano =  (Humano*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_humano)[0];

    if(hay_casos_especiales(humano))
        return;

    int vida_nueva = humano->obtener_vida() - (int)(((float)personaje->obtener_fuerza())*obtener_armadura(humano));

    humano->asignar_vida(vida_nueva);
}