#include "Ataque_zombie.h"

#include "../../../defensa/monstruos/zombies/Defensa_zombie.h"

Ataque_zombie::Ataque_zombie(Zombie *personaje):Ataque_monstruo(personaje){

}

void Ataque_zombie::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[ZOMBIE]);
}


bool Ataque_zombie::tiene_energia(){
    return personaje->obtener_energia()>=GASTO_ENERGIA[ZOMBIE];
}

bool Ataque_zombie::esta_en_rango_ataque(Coordenada posicion,char arma){
    Coordenada centro = personaje->obtener_posicion();
    if(centro == POSICION_INVALIDA)
        return false;
    else
        return obtener_cruz(centro,1).existe(posicion);
}

void Ataque_zombie::convertir_zombie(Humano *humano){
    humano->asignar_nombre(NOMBRES_CHAR[ZOMBIE]);
    delete humano->obtener_ataque();
    humano->asignar_ataque(new Ataque_zombie((Zombie*)humano));
    delete humano->obtener_defensa();
    humano->asignar_defensa(new Defensa_zombie((Zombie*)humano));
}

void Ataque_zombie::atacar_casilla(Casilla *casilla_ataque, char arma){

    Humano *humano =  (Humano*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_humano)[0];

    convertir_zombie(humano);
}