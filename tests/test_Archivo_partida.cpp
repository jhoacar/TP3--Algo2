#include "../src/juego/jugador.h"
#include "../src/archivo/Archivo_partida.h"
#include "../src/archivo/Archivo_tablero.h"
#include "../src/constantes/Constantes.h"

int main(){
    Archivo_tablero leer_tablero(FICHERO_TABLERO);

    Jugador* j1;
    j1 = new Jugador;
    Jugador* j2; 
    j2 = new Jugador;

    Tablero* mapa;

    mapa = leer_tablero.obtener_tablero();

    Archivo_partida partida(FICHERO_PARTIDA);

    partida.cargar_datos_de_partida(mapa, j1, j2);   

    cout << endl << j2->obtener_datos_personajes()[2]->obtener_nombre() << endl;

    delete j1;
    delete j2;
    delete mapa;

    return 0;
}