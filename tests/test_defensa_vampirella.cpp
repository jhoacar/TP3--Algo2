#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

// Test defensa Vampirella:
//     Vampirella se defiende. Consume 5 puntos de energía.
//     Se convierte en murcielago por un turno y no puede ser atacada por estacas o agua bendita.
// (1) Ver antes y después del stat energía.                        => Bien!
// (2) Antes de defenderse es vampiro y después es murcielago.      => Bien!
//
// Tests

int main(){

    Vampirella* vampirella = new Vampirella();

    // Estado inicial de Vampirella, antes de defenderse:
    cout << "Energía inicial: " << vampirella->devolver_energia() << endl;
    if ( vampirella->es_murcielago() ){
        cout << "Vampirella es un murcielago." << endl;
    }
    else{
        cout << "Vampirella es un vampiro." << endl;
    }

    vampirella->defender();

    // Estado final de Vampirella, después de defenderse:
    cout << "Energía final: " << vampirella->devolver_energia() << endl;
    if ( vampirella->es_murcielago() ){
        cout << "Vampirella es un murcielago." << endl;
    }
    else{
        cout << "Vampirella es un vampiro." << endl;
    }

    return 0;
}


