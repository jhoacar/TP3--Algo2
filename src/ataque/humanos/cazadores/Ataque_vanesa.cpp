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

float Ataque_vanesa::obtener_ataque(char nombre_monstruo,  char arma){

    float valor_ataque=0;

    if(nombre_monstruo==NOMBRES_CHAR[ZOMBIE]){

        if(arma == NOMBRES_CHAR[ESCOPETA])
            valor_ataque=((float)personaje->obtener_fuerza())*((float)1.25);
        else if(arma == NOMBRES_CHAR[AGUA])
            consumir_toda_agua();
        else if(arma == NOMBRES_CHAR[ESTACA])
            valor_ataque=((float)personaje->obtener_fuerza())*((float)0.25);

    }
    else{
        if(arma == NOMBRES_CHAR[ESCOPETA])
            valor_ataque=((float)personaje->obtener_fuerza())*((float)0.4);
        else if(arma == NOMBRES_CHAR[AGUA])
            valor_ataque=((float)20);
        else if(arma == NOMBRES_CHAR[ESTACA])
            valor_ataque=((float)0);
    }
    return valor_ataque;
}

void Ataque_vanesa::atacar_casilla(Casilla *casilla_ataque,char arma){

    
    Monstruo *monstruo =  (Monstruo*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_monstruo)[0];

    if(hay_casos_especiales(monstruo,arma))
        return;
    
    int vida = monstruo->obtener_vida();
    float valor_ataque = obtener_ataque(monstruo->obtener_nombre(),arma)*obtener_armadura(monstruo);

    monstruo->asignar_vida(vida-(int)valor_ataque);
    
}
