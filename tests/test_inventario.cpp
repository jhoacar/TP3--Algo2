#include "../src/funcionalidades/Datos.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

int main(){
    Coordenada posicion(3, 5);
    Casilla casilla(posicion);
    Objeto* humano_prueba = new Humano(casilla, 'h');
    ((Ser *)humano_prueba)->encuentro_con_elemento();
    retunr 0;
}
