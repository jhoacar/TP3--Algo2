#include "Ataque_cazador.h"
#include "../../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../../objetos/seres/monstruos/zombies/Zombie.h"


Ataque_cazador::Ataque_cazador(Cazador *cazador):Ataque_humano(cazador){

}

bool Ataque_cazador::puede_atacar(){
    return  personaje->obtener_energia()>=GASTO_ENERGIA[HUMANO_CAZADOR] &&
            ((Cazador*)personaje)->tiene_escopeta &&
            ((Cazador*)personaje)->cantidad_balas>=MINIMO_BALAS ;
}

bool Ataque_cazador::esta_en_rango_ataque(Coordenada posicion){

    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return false;
    else
        return obtener_cuadrado(centro,1).existe(posicion);
}

void Ataque_cazador::atacar(Coordenada posicion, Tablero *tablero){

    if(!puede_atacar()){
        cout<<"No puede atacar por falta de escopeta o cantidad de balas";
        return;
    }
    else if(!esta_en_rango_ataque(posicion)){
        cout<<"No puede atacar esta posicion porque no se encuentra en el rango de ataque";
        return;
    }
    else if(!tiene_monstruo(tablero->obtener_casilla(posicion))){
        cout<<"No puede atacar esta posicion porque no se encuentra ningun monstruo";
    }

    atacar_casilla(tablero->obtener_casilla(posicion));

}
void Ataque_cazador::atacar_casilla(Casilla *casilla_ataque){

    Monstruo *monstruo =  (Monstruo*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_monstruo)[0];

    int vida_nueva = monstruo->obtener_vida();

    if(monstruo->obtener_nombre()==NOMBRES_CHAR[ZOMBIE])
        vida_nueva-=personaje->obtener_fuerza();
    else
        vida_nueva-=(int)((float)personaje->obtener_fuerza())*0.20;

    monstruo->asignar_vida(vida_nueva);
}
