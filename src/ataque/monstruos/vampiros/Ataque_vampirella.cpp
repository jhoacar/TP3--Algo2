#include "Ataque_vampirella.h"

Ataque_vampirella::Ataque_vampirella(Vampirella *personaje):Ataque_vampiro(personaje){

}
void Ataque_vampirella::consumir_energia(){
    personaje->asignar_energia(personaje->obtener_energia()-GASTO_ENERGIA[VAMPIRELLA]);
}

bool Ataque_vampirella::tiene_energia(){
    return personaje->obtener_energia()>=GASTO_ENERGIA[VAMPIRELLA];
}

void Ataque_vampirella::atacar_casilla(Casilla *casilla_ataque, char arma){

    Humano *humano =  (Humano*)casilla_ataque->obtener_objetos().filtrar_datos(0,es_tipo_humano)[0];

    if(hay_casos_especiales(humano))
        return;

    int vida_nueva = humano->obtener_vida() - (int)(((float)personaje->obtener_fuerza())*obtener_armadura(humano));

    humano->asignar_vida(vida_nueva);

    humano->asignar_armadura(humano->obtener_armadura()-1);
}