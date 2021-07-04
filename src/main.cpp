#include "funcionalidades/Funciones.h"
#include "funcionalidades/Datos.h"
#include <iostream>
int main(int argc, char *argv[]){
    
    activar_color();

    string archivo = "estado.txt";
    
    if(argc>1)
        archivo = argv[1];

    Datos dato(archivo);
    cout<<dato.obtener_resumen();
    dato.obtener_tablero()->mostrar_tablero();
    pausa();
    return 0;
}