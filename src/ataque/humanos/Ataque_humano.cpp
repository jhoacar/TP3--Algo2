#include "Ataque_humano.h"

Ataque_humano::Ataque_humano(Humano *humano):Ataque(humano){

}

void Ataque_humano::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[HUMANO]);
}

bool Ataque_humano::puede_atacar(){
    
    return  personaje->obtener_energia()>=GASTO_ENERGIA[HUMANO] && 
            ((Humano*)personaje)->tiene_escopeta && 
            ((Humano*)personaje)->cantidad_balas>=MINIMO_BALAS ;
}

bool Ataque_humano::esta_en_rango_ataque(Coordenada posicion, char arma){
    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return false;
    else
        return obtener_cuadrado(centro,1).existe(posicion);
}

bool Ataque_humano::se_puede_atacar(Coordenada posicion,Tablero *tablero, char arma){

    return  puede_atacar() && 
            esta_en_rango_ataque(posicion) && 
            tiene_monstruo(tablero->obtener_casilla(posicion));
}

void Ataque_humano::atacar(Coordenada posicion, Tablero *tablero, char arma){

    atacar_casilla(tablero->obtener_casilla(posicion));
    
    consumir_balas();

    consumir_energia();
}

void Ataque_humano::eliminar_balas_inventario(){
    
    Lista<Objeto*> balas = personaje->obtener_inventario().filtrar_datos(0,es_bala);
    int consumido = 0;
    while(balas.existe_siguiente() && consumido<MINIMO_BALAS){
        
        Elemento *bala = (Elemento*)balas.siguiente_dato();

        int cantidad = bala->obtener_cantidad();
        if(cantidad>=MINIMO_BALAS){
            bala->asignar_cantidad(cantidad-MINIMO_BALAS);
            consumido=MINIMO_BALAS;
        }
        else if(cantidad==1){
            bala->asignar_cantidad(0);
            consumido++;
        }

        if(bala->obtener_cantidad()==0)
            personaje->obtener_inventario().borrar_dato(bala);
    }
}
void Ataque_humano::consumir_balas(){

    ((Humano*)personaje)->cantidad_balas-=MINIMO_BALAS;

    eliminar_balas_inventario();
}

bool Ataque_humano::hay_casos_especiales(Monstruo *monstruo, char arma){
    return  monstruo==nullptr ||
            ((monstruo->obtener_nombre()==NOMBRES_CHAR[VAMPIRO] && monstruo->esta_oculto() )||
            (monstruo->obtener_nombre()==NOMBRES_CHAR[VAMPIRELLA] && monstruo->esta_oculto() && arma!=NOMBRES_CHAR[ESCOPETA]));
}

float Ataque_humano::obtener_ataque(char nombre_monstruo,char arma){
    float valor_ataque=0;
    
    if(nombre_monstruo==NOMBRES_CHAR[ZOMBIE])
        valor_ataque=((float)personaje->obtener_fuerza());
    else
        valor_ataque=((float)personaje->obtener_fuerza())*((float)0.20);

    return valor_ataque;
}

void Ataque_humano::atacar_casilla(Casilla *casilla_ataque){

    Monstruo *monstruo =  (Monstruo*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_monstruo)[0];

    if(hay_casos_especiales(monstruo))
        return;

    int vida = monstruo->obtener_vida();

    float valor_ataque = obtener_ataque(monstruo->obtener_nombre())*obtener_armadura(monstruo);

    monstruo->asignar_vida(vida-(int)valor_ataque);
}
