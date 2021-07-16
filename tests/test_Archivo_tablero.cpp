#include "../src/archivo/Archivo_tablero.h"

int main(){
    
    Tablero* mapa = nullptr;
    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_datos_de_terreno();
    
    mapa->mostrar_tablero();

    delete mapa;
    return 0;
}