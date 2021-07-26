#include "Defensa_nosferatu.h"


Defensa_nosferatu::Defensa_nosferatu(Nosferatu *personaje):Defensa_vampiro(personaje){
}


void Defensa_nosferatu::defender(Tablero* tablero) {

    Lista<Coordenada> lista_coordenadas;
    lista_coordenadas = obtener_cuadrado(personaje -> obtener_casilla()->obtener_posicion(), 2);
    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);

    int i = 0;
    while (lista_coordenadas.existe_siguiente()) {
        Objeto *objeto;
        while(((Ser*)objeto)->obtener_inventario().existe_siguiente()) {

            objeto = lista_casillas[i]->obtener_objetos().siguiente_dato();
            int vida_otro_vampiro = ((Ser *) objeto) -> devolver_vida();
            int vida_nosferatu = personaje->devolver_vida();
            int aux = vida_otro_vampiro;
            ((Ser*)objeto) ->asignar_vida(vida_nosferatu);
            personaje->asignar_vida(aux);
        }
        i++;
    }

}