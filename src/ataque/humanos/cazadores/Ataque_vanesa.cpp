#include "Ataque_vanesa.h"

Ataque_vanesa::Ataque_vanesa(Vanessa *personaje):Ataque_cazador(personaje){

}

void Ataque_vanesa::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[VANESA]);
}

bool Ataque_vanesa::tiene_energia(){
    return  personaje->obtener_energia()>=GASTO_ENERGIA[VANESA];
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
