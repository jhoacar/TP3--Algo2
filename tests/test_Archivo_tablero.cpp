#include "../src/archivo/Archivo_tablero.h"
void imprimir_casillas(Casilla *casilla){
    if(casilla!=nullptr){
        color(casilla->obtener_color());
        color(NEGRO);
        cout<<"("<<casilla->obtener_fila()<<","<<casilla->obtener_columna()<<")";
        color(RESET);
        cout<<" "<<endl;
    }
}

int main(){
    
    activar_color();
    
    Tablero* mapa = nullptr;
    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();
    
    mapa->mostrar_tablero();

    Lista<Casilla*> casillas = mapa->obtener_camino_minimo({0,0},{0,3},TIPO_ZOMBIE);
    cout<<"COSTE (ZOMBIE): "<<mapa->obtener_energia_total({0,0},{0,3},TIPO_ZOMBIE)<<endl;

    casillas.imprimir(imprimir_casillas);

    delete mapa;

    pausa();

    return 0;
}