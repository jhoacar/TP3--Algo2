#include "Ataque_vanesa.h"

Ataque_vanesa::Ataque_vanesa(Vanessa *personaje):Ataque_cazador(personaje){

    
}

void Ataque_vanesa::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[VANESA]);
}

bool Ataque_vanesa::puede_atacar(){
    return  personaje->obtener_energia()>=GASTO_ENERGIA[VANESA];
}

void Ataque_vanesa::atacar(Coordenada posicion, Tablero *tablero, char arma){

    atacar_casilla(tablero->obtener_casilla(posicion),arma);

    consumir_arma(arma);

    consumir_energia();
}

bool Ataque_vanesa::se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma){

    return  puede_atacar() &&
            esta_en_rango_ataque(posicion,arma) &&
            tiene_monstruo(tablero->obtener_casilla(posicion)) &&
            tiene_arma(arma);
}


void Ataque_vanesa::atacar_casilla(Casilla *casilla_ataque,char arma){

    
    Monstruo *monstruo =  (Monstruo*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_monstruo)[0];

    int vida_nueva = monstruo->obtener_vida();

    if(monstruo->obtener_nombre()==NOMBRES_CHAR[ZOMBIE]){
        if(arma == NOMBRES_CHAR[ESCOPETA])
            vida_nueva-=(int)((float)personaje->obtener_fuerza()*1.25);
        else if(arma == NOMBRES_CHAR[AGUA])
            consumir_toda_agua();
        else if(arma == NOMBRES_CHAR[ESTACA])
            vida_nueva-=(int)((float)personaje->obtener_fuerza()*0.25);
    }
    else{
        if(arma == NOMBRES_CHAR[ESCOPETA])
            vida_nueva-=(int)((float)personaje->obtener_fuerza()*0.4);
        else if(arma == NOMBRES_CHAR[AGUA])
            vida_nueva-=20;
        else if(arma == NOMBRES_CHAR[ESTACA])
            vida_nueva=0;

    }

    monstruo->asignar_vida(vida_nueva);
}
