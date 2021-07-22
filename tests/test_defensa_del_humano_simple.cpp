#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

// Tests:
// (1) No tiene agua bendita en su inventario, aumenta +3 su energía => Bien!
// (2) Tiene agua bendita en su inventario, regenera toda su energía => Bien!
// (3) Tiene agua bendita en su inventario, aumenta +1 su armadura   => Bien!

int main(){

    Coordenada posicion(10, 10);
    Casilla* casilla = new Camino(posicion);
    Objeto* agua = new Agua(casilla,'a', 20, "id");
    Objeto* escopeta = new Escopeta(casilla,'e', 1, "ideee");
    Objeto* humano_simple = new Humano(casilla, 'h', "id");

    //Agrego agua a la casilla
    casilla->agregar_objeto(agua);
    casilla->agregar_objeto(escopeta);

    //El humano se encuentra con el elemento
    ((Humano*)humano_simple)->encuentro_con_elemento();
    Lista<Objeto*> inventario = ((Humano*)humano_simple)->obtener_inventario();

    inventario.reiniciar();
    while ( inventario.existe_siguiente() ) {
          cout << "Elemento: " << inventario.siguiente_dato()->obtener_nombre() << endl;
    }

    cout << "Energía previa: " << ((Ser*)humano_simple)->devolver_energia() << endl;
    ((Humano*)humano_simple)->defender();
    cout << "Energía posterior: " << ((Ser*)humano_simple)->devolver_energia() << endl;

    return 0;
}
