#include "../src/funcionalidades/Funciones.h"
#include "../src/funcionalidades/Datos.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

int main(){
    Coordenada posicion(1, 3);
    Objeto* humano_prueba = new Vampirella(posicion, 'h');
    /*
    cout << "Energia: " << ((Ser *)humano_prueba)->devolver_energia();
    ((Ser *)humano_prueba)->regenerar_energia();
    cout << "Energia: " << ((Ser *)humano_prueba)->devolver_energia();
     */
    ((Ser *)humano_prueba)->encuentro_con_elemento();
    return 0;
}



