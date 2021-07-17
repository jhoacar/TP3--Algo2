#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/tda/Diccionario.h"
#include <iostream>
#include <string>
using namespace std;

void imprimir_string(string dato){
    cout<<dato<<endl;
}
void imprimir_entero(int dato){
    cout<<dato<<endl;
}


int main(){
    activar_color();
    Diccionario<string,int> NUMEROS;

    NUMEROS["1"] = 0;
    NUMEROS["2"] = 1;
    NUMEROS["3"] = 2;
    NUMEROS["4"] = 3;
    NUMEROS["5"] = 4;

    NUMEROS.obtener_llaves().imprimir(imprimir_string);
    cout<<endl;
    NUMEROS.obtener_valores().imprimir(imprimir_entero);

    pausa();
}