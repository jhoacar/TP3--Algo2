#include "Defensa_vanesa.h"

Defensa_vanesa::Defensa_vanesa(Vanessa *personaje):Defensa_humano(personaje){
}



void Defensa_vanesa::defender(Tablero* tablero) {

    Lista<Coordenada> lista_coordenadas;
    if (tengo_objeto(NOMBRES_CHAR[AGUA])) {

        lista_coordenadas = obtener_cuadrado(personaje->obtener_casilla()->obtener_posicion(), 2);
        consumir_objeto(NOMBRES_CHAR[AGUA]);
        Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
        Lista<Casilla *> lista_casillas_con_personaje = obtener_casilla_con_personaje(lista_casillas, NOMBRES_STRING[HUMANO]);

        while(lista_casillas_con_personaje.existe_siguiente()) {
            Casilla* casilla = lista_casillas_con_personaje.siguiente_dato();
            cortar_transformacion(casilla);
        }
    }
    if(tengo_objeto(NOMBRES_CHAR[ESTACA]))
        ((Vanessa*) personaje)->proteccion_de_ataque_vampiro();
    else
        personaje ->regenerar_vida_defensa(10);

}


void Defensa_vanesa::cortar_transformacion(Casilla* casilla){

    int indice_humano = indice_personaje(NOMBRES_CHAR[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_CHAR[HUMANO_CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_CHAR[VANESA], casilla);

    if(indice_humano != NO_ENCONTRADO)
        ((Humano*)casilla->obtener_objetos()[indice_humano]) ->frenar_transformacion();
    else if(indice_cazador != NO_ENCONTRADO)
        ((Cazador*)casilla->obtener_objetos()[indice_humano]) ->frenar_transformacion();
    else if(indice_vanesa != NO_ENCONTRADO)
        ((Vanessa*)casilla->obtener_objetos()[indice_humano]) ->frenar_transformacion();

}





