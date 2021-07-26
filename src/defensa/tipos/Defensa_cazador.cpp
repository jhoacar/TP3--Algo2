#include "Defensa_cazador.h"


Defensa_cazador::Defensa_cazador(Cazador *personaje):Defensa_humano(personaje){
}


void Defensa_cazador::defender(int accion, Tablero* tablero) {

    if(accion == REGENERAR_ENERGIA_PROPIA)
        personaje ->regenerar_vida_defensa(50);
    else {
        Lista<Coordenada> lista_coordenadas = obtener_cuadrado(personaje->obtener_casilla()->obtener_posicion(),
                                                               tablero->obtener_filas());
        Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);

        int i = 0;
        while(lista_casillas.existe_siguiente()) {
            char nombre = lista_casillas[i]->obtener_objetos().siguiente_dato()->obtener_nombre();
            if(nombre == NOMBRES_CHAR[HUMANO] ||nombre == NOMBRES_CHAR[HUMANO_CAZADOR] || nombre == NOMBRES_CHAR[VANESA])
                ((Ser*) lista_casillas[i]->obtener_objetos().siguiente_dato())->regenerar_vida_defensa(20);
        }
    }
}

