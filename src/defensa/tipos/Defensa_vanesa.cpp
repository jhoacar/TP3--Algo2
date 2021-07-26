#include "Defensa_vanesa.h"

Defensa_vanesa::Defensa_vanesa(Vanessa *personaje):Defensa_humano(personaje){
}



void Defensa_vanesa::defender(Tablero* tablero) {

    Lista<Coordenada> lista_coordenadas;
    if (tengo_objeto(NOMBRES_CHAR[AGUA])) {
        lista_coordenadas = obtener_cuadrado(personaje->obtener_casilla()->obtener_posicion(), 2);
        consumir_objeto(NOMBRES_CHAR[AGUA]);
        Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);

        int i = 0;
        while (lista_casillas.existe_siguiente()) {
            Objeto *objeto;
            while(((Ser*)objeto)->obtener_inventario().existe_siguiente()) {
                objeto = lista_casillas[i]->obtener_objetos().siguiente_dato();
                char nombre = objeto->obtener_nombre();
                if (nombre == NOMBRES_CHAR[HUMANO] || nombre == NOMBRES_CHAR[HUMANO_CAZADOR] ||
                    nombre == NOMBRES_CHAR[VANESA])
                    (((Humano *) objeto)->frenar_transformacion());
            }
            i++;
        }
    }
    if(tengo_objeto(NOMBRES_CHAR[ESTACA]))
        ((Vanessa*) personaje)->proteccion_de_ataque_vampiro();
    else
        personaje ->regenerar_vida_defensa(10);

}







