#include "archivo/Archivo_tablero.h"
#include "archivo/Archivo_objetos.h"
#include <iostream>
#include <ctime>

void imprimir_objetos(Objeto *objeto){
    if(objeto!=nullptr){
        cout<<objeto->obtener_ID();
        objeto->mostrar();
    }
}

int main(int argc, char *argv[]){
    

    srand(time(nullptr));

    activar_color();

    Archivo_tablero archivo_tablero(FICHERO_TABLERO);

    Archivo_objetos archivo_objetos(FICHERO_OBJETOS,archivo_tablero.obtener_tablero());

    Tablero *tablero = archivo_tablero.obtener_tablero();

    Lista<Objeto*> objetos = archivo_objetos.obtener_lista_objetos();

    if(tablero!=nullptr){
        tablero->mostrar_tablero();
        objetos.imprimir(imprimir_objetos);
        cout<<objetos.obtener_tamano();
    }

    pausa();
    return 0;
}