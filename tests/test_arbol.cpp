#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/tda/AVL.h"
#include <iostream>
#include <string>
using namespace std;


void imprimir_numero(int numero){
    cout<<numero<<endl;
}

int main(){
    activar_color();
    AVL<int,int> a;
    bool s;
    a.buscar(33,s,comparacion) = 4;
    a.buscar(25,s,comparacion) = 2;
    a.buscar(28,s,comparacion) = 1;
    a.buscar(40,s,comparacion) = 0;
    a.buscar(66,s,comparacion) = 0;
    a.buscar(18,s,comparacion) = 0;
    a.buscar(15,s,comparacion) = 0;
    a.buscar(100,s,comparacion) = 0;
    cout<<"Altura del arbol: "<<a.obtener_altura(a.obtener_arbol())<<endl;
    cout<<"Factor de equilibrio del arbol: "<<a.obtener_factor_equilibrio(a.obtener_arbol())<<endl;
    cout<<endl;
    Lista<int> llaves;
    a.obtener_llaves(a.obtener_arbol(),llaves);
    llaves.imprimir(imprimir_numero);
    cout<<endl<<endl;

    Lista<int> valores;
    a.obtener_valores(a.obtener_arbol(),valores);
    valores.imprimir(imprimir_numero);

    pausa();
}
