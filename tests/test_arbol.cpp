#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/tda/Arbol.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    activar_color();
    Arbol_B<string,int> a;
    
    a.buscar("004",comparacion) = 4;
    a.buscar("002",comparacion) = 2;
    a.buscar("001",comparacion) = 1;
    a.buscar("000",comparacion) = 0;
    cout<<"Altura del arbol: "<<a.obtener_altura(a.obtener_arbol())<<endl;
    cout<<"Factor de equilibrio del arbol: "<<a.obtener_factor_equilibrio(a.obtener_arbol())<<endl;
    cout<<endl;

    pausa();
}