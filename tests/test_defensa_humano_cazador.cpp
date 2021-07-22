#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

// Test defensa humano cazador:
//     El cazador se defiende. Consume 5 puntos de energía.
//     Puede elegir si curarse +50 puntos de vida o curar +20 puntos de vida a sus aliados.
// (1) Ver antes y después del stat energía.                  => Bien!
// (2) Elige curarse. Ver antes y después del stat vida.      => Bien!
// (3) Elige curar aliados. Ver stat de aliados.
//
// Tests 1 y 2 pasados con éxito!!

int main(){

    Cazador* cazador = new Cazador();

    cout << "Energía inicial: " << cazador->devolver_energia() << endl;
    cout << "Vida inicial: " << cazador->devolver_vida() << endl;
    cazador->defender();
    cout << "Energía final: " << cazador->devolver_energia() << endl;
    cout << "Vida final: " << cazador->devolver_vida() << endl;

    return 0;
}

