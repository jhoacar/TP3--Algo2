#include "../src/funcionalidades/Funciones.h"
#include <iostream>
using namespace std;

int main(){
    activar_color();
    for(int i=0;i<(int)CANTIDAD_COLORES;i++){
        color(i);
        cout<<"COLOR NUMERO "<<i<<endl;
    }
    pausa();
}