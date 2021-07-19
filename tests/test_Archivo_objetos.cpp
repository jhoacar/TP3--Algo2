#include "../src/archivo/Archivo_objetos.h"
#include "../src/archivo/Archivo_tablero.h"

int main(){
    
    Tablero* mapa = nullptr;

    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();

    mapa->mostrar_tablero();

    cout << "--- TEST ARCHIVO_OBJETOS ---" << endl;

    Archivo_objetos lectura_objetos(FICHERO_OBJETOS);

    lectura_objetos.cargar_mapa_objetos(mapa);
    
    cout << endl << "MAPA ACTUALIZADO CON LOS OBJETOS:" << endl;
    mapa->mostrar_tablero();

    delete mapa;

    pausa();

    return 0;
}