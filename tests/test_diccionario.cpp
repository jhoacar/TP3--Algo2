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
    
    NUMEROS["036"] = 0;
    NUMEROS["263"] = 1;
    NUMEROS["983"] = 2;
    NUMEROS["625"] = 3;
    NUMEROS["142"] = 4;
    NUMEROS["526"] = 4;
    NUMEROS["762"] = 0;
    NUMEROS["003"] = 1;
    NUMEROS["034"] = 2;
    NUMEROS["027"] = 3;
    NUMEROS["152"] = 4;
    NUMEROS["827"] = 4;
    NUMEROS["623"] = 0;
    NUMEROS["652"] = 1;
    NUMEROS["028"] = 2;
    NUMEROS["048"] = 3;
    NUMEROS["726"] = 4;
    NUMEROS["947"] = 4;
    NUMEROS["619"] = 0;
    NUMEROS["965"] = 1;
    NUMEROS["123"] = 2;

    NUMEROS.obtener_llaves().imprimir(imprimir_string);
    cout<<endl;
    NUMEROS.obtener_valores().imprimir(imprimir_entero);

    pausa();
}