#include "../src/funcionalidades/Datos.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

int main(){
    Coordenada posicion(3, 5);
    Casilla *lago = new Lago(posicion);
    Objeto* humano_prueba = new Humano(lago, 'h', "312");
    ((Ser *)humano_prueba)->encuentro_con_elemento();
    return 0;
}
