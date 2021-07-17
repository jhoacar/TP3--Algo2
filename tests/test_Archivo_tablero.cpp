#include "../src/archivo/Archivo_tablero.h"

int main(){
    
    activar_color();
    
    Tablero* mapa = nullptr;
    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();
    
    mapa->mostrar_tablero();

    delete mapa;
    return 0;
}