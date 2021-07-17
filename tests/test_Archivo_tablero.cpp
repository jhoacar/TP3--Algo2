#include "../src/archivo/Archivo_tablero.h"
void imprimir_casillas(Casilla *casilla){
    if(casilla!=nullptr){
        color(casilla->obtener_color());
        cout<<" * "<<endl;
        color(RESET);
    }
}

int main(){
    
    activar_color();
    
    Tablero* mapa = nullptr;
    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();
    
    mapa->mostrar_tablero();

    Lista<Casilla*> casillas = mapa->obtener_camino_minimo({0,0},{3,3},TIPO_HUMANO);

    casillas.imprimir(imprimir_casillas);

    delete mapa;

    pausa();

    return 0;
}