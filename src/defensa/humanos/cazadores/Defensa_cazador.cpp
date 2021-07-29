#include "Defensa_cazador.h"


Defensa_cazador::Defensa_cazador(Cazador *personaje):Defensa_humano(personaje){

}
void Defensa_cazador::aumentar_vida_aliados(Tablero *tablero, int vida){
    
    Lista<Objeto*> humanos = tablero->obtener_objetos(NOMBRES_CHAR[HUMANO]);
    Lista<Objeto*> vanesas = tablero->obtener_objetos(NOMBRES_CHAR[VANESA]);
    Lista<Objeto*> cazadores = tablero->obtener_objetos(NOMBRES_CHAR[HUMANO_CAZADOR]);

    while(humanos.existe_siguiente()){
        Humano *humano = (Humano*)humanos.siguiente_dato();
        humano->asignar_vida(humano->obtener_vida()+vida);
    }
    while(vanesas.existe_siguiente()){
        Vanessa *vanesa = (Vanessa*)vanesas.siguiente_dato();
        vanesa->asignar_vida(vanesa->obtener_vida()+vida);
    }
    while(cazadores.existe_siguiente()){
        Cazador *cazador = (Cazador*)cazadores.siguiente_dato();
        if(cazador!=personaje)
            cazador->asignar_vida(cazador->obtener_vida()+vida);
    }   
}

void Defensa_cazador::defender(Tablero *tablero, int opcion){
    personaje->asignar_energia(personaje->obtener_energia()-5);
    if(opcion == OPCION_CURARSE_VIDA)
        personaje->asignar_vida(personaje->obtener_vida()+50);
    else if(opcion == OPCION_CURAR_ALIADOS)
        aumentar_vida_aliados(tablero,20);
}