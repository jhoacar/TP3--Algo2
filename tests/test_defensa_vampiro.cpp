#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

// Test defensa vampiro:
// (1) El vampiro se defiende. Consume 4 puntos de energía y se oculta.
//     Ver antes y después del stat energía.              => Bien!
// (2) Ver si está oculto luego de defenderse.            => Bien!
//
// Test pasado con éxito!


int main(){

    Vampiro* vampiro = new Vampiro();

    // Estado inicial del vampiro
    cout << "Energía previa: " << vampiro->devolver_energia() << endl;

    if ( vampiro->esta_oculto() ){
        cout << "El vampiro está oculto." << endl;
    }
    else{
        cout << "El vampiro NO está oculto." << endl;
    }

    //El vampiro se defiende
    vampiro->defender();

    //Estado final del vampiro
    cout << "Energía previa: " << vampiro->devolver_energia() << endl;

    if ( vampiro->esta_oculto() ){
        cout << "El vampiro está oculto." << endl;
    }
    else{
        cout << "El vampiro NO está oculto." << endl;
    }

    return 0;
}

