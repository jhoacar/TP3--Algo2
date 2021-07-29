#include "../src/funcionalidades/Funciones.h"
#include <iostream>
using namespace std;

int main(){
    limpiar_pantalla();
    int matriz[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            gotoxy(10+j*5, i+5);
            cin >> matriz[i][j];

        }

    cout << endl;

    pausa();
}