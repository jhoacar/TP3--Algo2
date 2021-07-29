#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/tda/Lista.h"

#include <iostream>

using namespace std;

/*void imprimir_coordenada(Coordenada coord){
    cout<<"("<<coord.obtener_fila()<<","<<coord.obtener_columna()<<")"<<endl;
}
*/
int main(){

    limpiar_pantalla();
    Lista<Coordenada> cruz = obtener_cuadrado({5,5},1);
    gotoxy(1,1);
    cout<<"C";
    for(int i=0;i<cruz.obtener_tamano();i++){
        gotoxy(cruz[i].obtener_fila(),cruz[i].obtener_columna());
        cout<<"*";
    }
    //gotoxy(0,10);
    pausa();
    //cruz.imprimir(imprimir_coordenada);
        
}