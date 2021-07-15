#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/tda/Diccionario.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    activar_color();
    Diccionario<string,int> NUMEROS;

    NUMEROS["1"] = 0;
    NUMEROS["2"] = 1;
    NUMEROS["3"] = 2;
    NUMEROS["4"] = 3;
    NUMEROS["5"] = 4;

    for(int i=1; i<6 ; i++)
        cout<<NUMEROS[to_string(i)]<<endl;
    
    pausa();
}