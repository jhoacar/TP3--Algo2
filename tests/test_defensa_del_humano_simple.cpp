#include "../src/archivo/Archivo_tablero.h"
#include "../src/archivo/Archivo_objetos.h"
#include <iostream>


int main(){
    
    Archivo_tablero datos_tablero(FICHERO_TABLERO);
    Archivo_objetos datos_objeto(FICHERO_OBJETOS,datos_tablero.obtener_tablero());

    Tablero *tablero = datos_tablero.obtener_tablero();

    tablero->mostrar_tablero();

    return 0;
}
