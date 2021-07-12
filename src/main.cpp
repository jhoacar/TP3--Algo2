#include "funcionalidades/Funciones.h"
#include "funcionalidades/Datos.h"
#include <iostream>
int main(int argc, char *argv[]){
    

    srand(12324);

    activar_color();

    string archivo = "estado.txt";
    
    if(argc>1)
        archivo = argv[1];

    cout<<"Hay que arreglar el tema de ficheros";
    //Datos dato(archivo);
    //cout<<dato.obtener_resumen();
    //dato.obtener_tablero()->mostrar_tablero();
    pausa();
    return 0;
}