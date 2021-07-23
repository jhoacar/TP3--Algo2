#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

// Tests:
// (1) No tiene agua bendita en su inventario, aumenta +3 su energía => Bien!
// (2) Tiene agua bendita en su inventario, regenera toda su energía => Pendiente
// (3) Tiene agua bendita en su inventario, aumenta +1 su armadura   => Pendiente

int main(){
    Coordenada posicion(10, 10);
    Casilla* camino = new Camino(posicion);
    Objeto* humano_simple = new Humano(camino, 'h', "id");

    cout << "Energía previa: " << ((Ser*)humano_simple)->devolver_energia() << endl;
    ((Humano*)humano_simple)->defender();
    cout << "Energía posterior: " << ((Ser*)humano_simple)->devolver_energia() << endl;

    return 0;
}
