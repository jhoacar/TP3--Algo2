#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/tda/Arbol.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    activar_color();
    Arbol_B<int,int> a;
    
    a.buscar(33,comparacion) = 4;
    a.buscar(25,comparacion) = 2;
    a.buscar(28,comparacion) = 1;
    a.buscar(40,comparacion) = 0;
    a.buscar(66,comparacion) = 0;
    a.buscar(18,comparacion) = 0;
    a.buscar(15,comparacion) = 0;
    a.buscar(100,comparacion) = 0;
    a.buscar(75,comparacion) = 0;
    a.buscar(50,comparacion) = 0;
    cout<<"Altura del arbol: "<<a.obtener_altura(a.obtener_arbol())<<endl;
    cout<<"Factor de equilibrio del arbol: "<<a.obtener_factor_equilibrio(a.obtener_arbol())<<endl;
    cout<<endl;

    pausa();
}