#include "Ataque_nosferatu.h"

#include "../../../defensa/monstruos/vampiros/Defensa_vampiro.h"

Ataque_nosferatu::Ataque_nosferatu(Nosferatu *personaje):Ataque_vampiro(personaje){

}

void Ataque_nosferatu::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[NOSFERATU]);
}


bool Ataque_nosferatu::puede_atacar(){
    return personaje->obtener_energia()>=GASTO_ENERGIA[NOSFERATU];
}

void Ataque_nosferatu::atacar(Coordenada posicion, Tablero *tablero, char arma){

    atacar_casilla(tablero->obtener_casilla(posicion));

    consumir_energia();
}
bool Ataque_nosferatu::esta_en_rango_ataque(Coordenada posicion,char arma){
    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return false;
    else
        return obtener_cuadrado(centro,2).existe(posicion);
}

bool Ataque_nosferatu::se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma){
    return  puede_atacar() &&
            esta_en_rango_ataque(posicion) &&
            tiene_humano(tablero->obtener_casilla(posicion));    
}

void Ataque_nosferatu::convertir_vampiro(Humano *humano){
    humano->asignar_nombre(NOMBRES_CHAR[VAMPIRO]);
    delete humano->obtener_ataque();
    humano->asignar_ataque(new Ataque_vampiro((Vampiro*)humano));
    delete humano->obtener_defensa();
    humano->asignar_defensa(new Defensa_vampiro((Vampiro*)humano));
}

void Ataque_nosferatu::atacar_casilla(Casilla *casilla_ataque){

    Humano *humano =  (Humano*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_humano)[0];

    if(hay_casos_especiales(humano))
        return;

    int vida_humano = humano->obtener_vida();
    
    if(vida_humano<=30)
        convertir_vampiro(humano);
    else
        vida_humano-=(int)(((float)personaje->obtener_fuerza())*obtener_armadura(humano));

    humano->asignar_vida(vida_humano);
}