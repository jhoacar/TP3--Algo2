#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/Datos.h"
#include <iostream>
int main(int argc, char *argv[]){
    
    string archivo = "estado.txt";
    
    if(argc>1){
        archivo = argv[1];	
	}
    
	color(AMARILLO);
	limpiar_pantalla();
	pausa();
	
    Datos dato(archivo);
    cout<<dato.obtener_resumen();
    dato.obtener_tablero()->mostrar_tablero();
    pausa();
    return 0;
}
