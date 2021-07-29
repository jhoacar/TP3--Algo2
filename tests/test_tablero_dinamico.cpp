#include "../src/funcionalidades/Funciones.h"
#include "../src/mapa/Tablero.h"
#include "../src/archivo/Archivo_tablero.h"
#include "../src/constantes/Constantes.h"
#include <iostream>

#ifdef __linux__
const char ARRIBA    = 65;//'W';
const char ABAJO     = 66;//'S';
const char DERECHA   = 67;//'D';
const char IZQUIERDA = 68;//'A';
const int PRIMERA_FILA = 1;
const int PRIMERA_COLUMNA = 2;
const int ESPACIO_CASILLERO_COLUMNA = 3;
const int ESPACIO_CASILLERO_FILA = 1;
#endif

#ifdef __MINGW32__
const char ARRIBA    = 72;//'W';
const char ABAJO     = 80;//'S';
const char DERECHA   = 77;//'D';
const char IZQUIERDA = 75;//'A';
const int PRIMERA_FILA = 1;
const int PRIMERA_COLUMNA = 2;
const int ESPACIO_CASILLERO_COLUMNA = 3;
const int ESPACIO_CASILLERO_FILA = 1;
#endif

void mover_arriba(Coordenada &posicion, Tablero* mapa){
    if (posicion.obtener_fila() == PRIMERA_FILA)
        posicion = {mapa ->obtener_filas(), posicion.obtener_columna()};
    else
        posicion={(posicion.obtener_fila()-ESPACIO_CASILLERO_FILA),posicion.obtener_columna()};
}
void mover_abajo(Coordenada &posicion, Tablero* mapa){
    if (posicion.obtener_fila() == mapa ->obtener_filas())
        posicion = {PRIMERA_FILA, posicion.obtener_columna()};
    else
        posicion={(posicion.obtener_fila()+ESPACIO_CASILLERO_FILA),posicion.obtener_columna()};
}
void mover_izquierda(Coordenada &posicion, Tablero *mapa){
    if (posicion.obtener_columna() == PRIMERA_COLUMNA)
        posicion = {posicion.obtener_fila(), (mapa -> obtener_columnas()*ESPACIO_CASILLERO_COLUMNA) -1}; //lo multiplico por 3porque el numero de columnas no es igual a la longitud del mapa
    else
        posicion={posicion.obtener_fila(),posicion.obtener_columna()-ESPACIO_CASILLERO_COLUMNA};
}
void mover_derecha(Coordenada &posicion, Tablero *mapa){
    if (posicion.obtener_columna() == (mapa ->obtener_columnas() * ESPACIO_CASILLERO_COLUMNA) -1)
        posicion = {posicion.obtener_fila(), PRIMERA_COLUMNA};
    else
        posicion={posicion.obtener_fila(),posicion.obtener_columna()+ ESPACIO_CASILLERO_COLUMNA};
}

int main(){


    limpiar_pantalla();

    Tablero* mapa = nullptr;

    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();

    mapa ->mostrar_tablero();


    char tecla=0;

    Coordenada posicion={1, 2};

    while(tecla!=' '){

        gotoxy(posicion);
        tecla = caracter_mayuscula((char)tecla_pulsada());
        //cout<<"TECLA: "<<tecla<<" NUMERO: "<<(int)tecla<<endl;
        switch(tecla){
            case ARRIBA:
                gotoxy(posicion);
                mover_arriba(posicion, mapa);
                break;
            case ABAJO:
                gotoxy(posicion);
                mover_abajo(posicion, mapa);
                break;
            case IZQUIERDA:
                gotoxy(posicion);
                mover_izquierda(posicion, mapa);
                break;
            case DERECHA:
                gotoxy(posicion);
                mover_derecha(posicion, mapa);
                break;
        }
    }

    gotoxy(1, 10);
    cout << "Seleccionaste la posicion x: " << posicion.obtener_fila() << "y: " << endl;

    return 0;
}