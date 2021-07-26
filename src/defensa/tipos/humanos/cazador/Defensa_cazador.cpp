#include "Defensa_cazador.h"


Defensa_cazador::Defensa_cazador(Cazador *personaje):Defensa_humano(personaje){
}


int Defensa_cazador::posicion_en_lista(char personaje, Lista<Objeto*> lista_objetos){

    Objeto *objeto_referencia = new Humano();
    objeto_referencia -> asignar_nombre(personaje);
    int indice = lista_objetos.buscar_dato(0, objeto_referencia, comparacion_por_nombre);
    return indice;

}




void Defensa_cazador::defender(int accion, Tablero* tablero) {

    if (accion == REGENERAR_ENERGIA_PROPIA)
        personaje->regenerar_vida_defensa(50);
    else {
        Lista<Coordenada> lista_coordenadas = obtener_cuadrado(personaje->obtener_casilla()->obtener_posicion(),tablero->obtener_filas());
        Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);

        Lista<Casilla *> lista_casillas_con_personaje = obtener_casilla_con_personaje(lista_casillas, NOMBRES_STRING[HUMANO]);

        while(lista_casillas_con_personaje.existe_siguiente()) {
            Casilla* casilla = lista_casillas_con_personaje.siguiente_dato();
            regenerar_vida_aliados(casilla);
            }
    }
}

