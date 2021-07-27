#include "../src/archivo/Archivo_tablero.h"
#include "../src/archivo/Archivo_objetos.h"
#include <iostream>

void imprimir_coordenada(Coordenada coord){
    cout<<"("<<coord.obtener_fila()<<","<<coord.obtener_columna()<<")\t";
}
void imprimir_objeto(Objeto *objeto){
    if(objeto!=nullptr){
        objeto->mostrar();
        imprimir_coordenada(objeto->obtener_posicion());
    }
    cout<<endl;
}


int main(){
    
    Archivo_tablero datos_tablero(FICHERO_TABLERO);
    Archivo_objetos datos_objeto(FICHERO_OBJETOS,datos_tablero.obtener_tablero());

    Tablero *tablero = datos_tablero.obtener_tablero();

    tablero->mostrar_tablero();

    datos_objeto.obtener_lista_objetos().imprimir(imprimir_objeto);

    return 0;
}
