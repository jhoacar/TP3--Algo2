#include "../src/mapa/Tablero.h"
#include <iostream>
int main(int argc, char *argv[]){
    
    string archivo = "estado.txt";
    
    if(argc>1){
        archivo = argv[1];	
	}
    
	color(AMARILLO);
	limpiar_pantalla();
	pausa();
    
    return 0;
}
