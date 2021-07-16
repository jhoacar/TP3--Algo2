#include "../src/funcionalidades/Datos.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

int main(){
    Coordenada posicion(10, 10);
    Casilla* camino = new Camino(posicion);
    Objeto* humano_simple = new Humano(camino, 'h', "id");

    // ((Ser *)humano_simple)->defenderse();

    cout << "Probando defensa del humano" << endl;

    return 0;
}
