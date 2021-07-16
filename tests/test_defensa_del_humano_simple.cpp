#include "../src/funcionalidades/Datos.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>


int main(){
    Coordenada posicion(10, 10);
    Casilla* camino = new Camino(posicion);
    Objeto* humano_simple = new Humano(camino, 'h', "id");

    cout << "Energía previa: " << ((Ser*)humano_simple)->devolver_energia() << endl;
    ((Humano*)humano_simple)->defenderse();
    cout << "Energía posterior: " << ((Ser*)humano_simple)->devolver_energia() << endl;

    return 0;
}
