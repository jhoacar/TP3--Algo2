#include "../src/archivo/Archivo_objetos.h"
#include "../src/archivo/Archivo_tablero.h"

void imprimir_obj(Objeto *objeto){
    if(objeto!=nullptr)
        objeto->mostrar();
    cout<<endl;
}


int main(){
    
    limpiar_pantalla();

    Tablero* mapa = nullptr;

    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();

    mapa->mostrar_tablero();

    cout << "--- TEST ARCHIVO_OBJETOS ---" << endl;

    Archivo_objetos lectura_objetos(FICHERO_OBJETOS,mapa);
    
    cout << endl << "MAPA ACTUALIZADO CON LOS OBJETOS:" << endl;
    mapa->mostrar_tablero();

    lectura_objetos.obtener_lista_objetos().imprimir(imprimir_obj);

    //pausa();

    return 0;
}