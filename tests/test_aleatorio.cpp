#include "../src/funcionalidades/Funciones.h"

#include <iostream>

using namespace std;

int main(){

    srand(2423424);

    for(int i=0;i<10;i++)
        cout<<obtener_numero_aleatorio(0,10)<<endl;
        
}