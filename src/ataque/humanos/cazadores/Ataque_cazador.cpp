#include "Ataque_cazador.h"

Ataque_cazador::Ataque_cazador(Cazador *cazador):Ataque_humano(cazador){

}
void Ataque_cazador::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[HUMANO_CAZADOR]);
}


bool Ataque_cazador::puede_atacar(){
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

bool Ataque_cazador::tiene_arma(const char arma){
    
    if(arma == NOMBRES_CHAR[ESCOPETA])
        return  ((Cazador*)personaje)->tiene_escopeta &&
                ((Cazador*)personaje)->cantidad_balas>=MINIMO_BALAS;
    else if(arma == NOMBRES_CHAR[AGUA])
        return ((Cazador*)personaje)->cantidad_agua>0;
    else
        return false;
}

bool Ataque_cazador::se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma){

    return  puede_atacar() &&
            esta_en_rango_ataque(posicion,arma) &&
            tiene_monstruo(tablero->obtener_casilla(posicion)) &&
            tiene_arma(arma);
}
void Ataque_cazador::consumir_agua(){
    Lista<Objeto*> aguas = personaje->obtener_inventario().filtrar_datos(0,es_agua);
    if(aguas.obtener_tamano()>0)
        personaje->obtener_inventario().borrar_dato(aguas[0]);
}

void Ataque_cazador::consumir_toda_agua(){
    Objeto* agua = new Agua();
    agua->asignar_nombre(NOMBRES_CHAR[AGUA]);
    personaje->obtener_inventario().borrar_toda_occurrencia(agua,comparacion_por_nombre);
    delete agua;
}

void Ataque_cazador::consumir_arma(const char arma){

    if(arma==NOMBRES_CHAR[ESCOPETA])
        consumir_balas();
    else if(arma==NOMBRES_CHAR[AGUA])
        consumir_agua();
}
void Ataque_cazador::atacar(Coordenada posicion, Tablero *tablero, char arma){

    atacar_casilla(tablero->obtener_casilla(posicion),arma);

    consumir_arma(arma);

    consumir_energia();
}

void Ataque_cazador::atacar_casilla(Casilla *casilla_ataque,char arma){

    
    Monstruo *monstruo =  (Monstruo*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_monstruo)[0];

    int vida_nueva = monstruo->obtener_vida();

    if(monstruo->obtener_nombre()==NOMBRES_CHAR[ZOMBIE]){
        if(arma == NOMBRES_CHAR[ESCOPETA])
            vida_nueva-=(int)((float)personaje->obtener_fuerza()*1.05);
        else if(arma == NOMBRES_CHAR[AGUA])
            consumir_toda_agua();
        else if(arma == NOMBRES_CHAR[ESTACA])
            vida_nueva-=(int)((float)personaje->obtener_fuerza()*0.2);
    }
    else{
        if(arma == NOMBRES_CHAR[ESCOPETA])
            vida_nueva-=(int)((float)personaje->obtener_fuerza()*0.3);
        else if(arma == NOMBRES_CHAR[AGUA])
            vida_nueva-=10;
        else if(arma == NOMBRES_CHAR[ESTACA])
            vida_nueva-=60;

    }

    monstruo->asignar_vida(vida_nueva);
}
