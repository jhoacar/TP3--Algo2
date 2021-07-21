#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

// Test defensa zombie:
// (1) El zombie se defiende. Consume 2 puntos de energía, aumenta 20 puntos de vida y se esconde.
//     Ver antes y después de los stats energía, vida.    => Bien!
// (2) Mostrar si está escondido luego de defenderse.


int main(){

    Zombie* zombie = new Zombie();

    // Estado inicial del zombie
    cout << "Energía previa: " << zombie->devolver_energia() << endl;
    cout << "Energía previa: " << zombie->devolver_vida() << endl;

    if (zombie->esta_escondido()){
        cout << "El zombie está escondido." << endl;
    }
    else{
        cout << "El zombie NO está escondido." << endl;
    }

    //El zombie se defiende
    zombie->defender();

    //Estado final del zombie
    cout << "Energía previa: " << zombie->devolver_energia() << endl;
    cout << "Energía previa: " << zombie->devolver_vida() << endl;

    if (zombie->esta_escondido()){
        cout << "El zombie está escondido." << endl;
    }
    else{
        cout << "El zombie NO está escondido." << endl;
    }

    return 0;
}

