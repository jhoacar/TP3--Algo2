#include "Ataque_cazador.h"

Ataque_cazador::Ataque_cazador(Cazador *cazador):Ataque_humano(cazador){

}

void Ataque_cazador::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[HUMANO_CAZADOR]);
}

bool Ataque_cazador::tiene_energia(){
    return  personaje->obtener_energia()>=GASTO_ENERGIA[HUMANO_CAZADOR];
}

bool Ataque_cazador::esta_en_rango_ataque(Coordenada posicion,char arma){

    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return false;
    else{

        if(arma == NOMBRES_CHAR[ESCOPETA])
            return obtener_cuadrado(centro,2).existe(posicion);

        else if(arma == NOMBRES_CHAR[AGUA])
           return obtener_cuadrado(centro,1).existe(posicion);
        
        else if(arma == NOMBRES_CHAR[ESTACA])
           return obtener_cruz(centro,1).existe(posicion);
        else
            return false;
    }
    
}

float Ataque_cazador::obtener_ataque(char nombre_monstruo,  char arma){

    float valor_ataque=0;

    if(nombre_monstruo==NOMBRES_CHAR[ZOMBIE]){

        if(arma == NOMBRES_CHAR[ESCOPETA])
            valor_ataque=((float)personaje->obtener_fuerza())*((float)1.05);
        else if(arma == NOMBRES_CHAR[AGUA])
            consumir_toda_agua();
        else if(arma == NOMBRES_CHAR[ESTACA])
            valor_ataque=((float)personaje->obtener_fuerza())*((float)0.2);

    }
    else{
        if(arma == NOMBRES_CHAR[ESCOPETA])
            valor_ataque=((float)personaje->obtener_fuerza())*((float)0.3);
        else if(arma == NOMBRES_CHAR[AGUA])
            valor_ataque=((float)10);
        else if(arma == NOMBRES_CHAR[ESTACA])
            valor_ataque=((float)60);
    }
    return valor_ataque;
}
