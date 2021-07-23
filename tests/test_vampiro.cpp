/*#include "Includes_Objetos.h"
#include <iostream>
#include "Funciones.h"
using namespace std;

// Tests:
// (1) No tiene agua bendita en su inventario, aumenta +3 su energía => Bien!
// (2) Tiene agua bendita en su inventario, regenera toda su energía => Pendiente
// (3) Tiene agua bendita en su inventario, aumenta +1 su armadura   => Pendiente



int main(){



    Coordenada posicion(10, 10);
    Casilla* casilla = new Camino(posicion);
    Objeto* agua = new Agua(casilla,'a', 20, "id");
    Objeto* escopeta = new Escopeta(casilla,'E', 1, "ideee");
    Objeto* humano_simple = new Humano(casilla, 'h', "id");

    //Agrego agua a la casilla
    casilla->agregar_objeto(escopeta);
    casilla->agregar_objeto(agua);


    //El humano se encuentra con el elemento
    ((Humano*)humano_simple)->encuentro_con_elemento();
    Lista<Objeto*> inventario = ((Humano*)humano_simple)->obtener_inventario();

    inventario.reiniciar();
    while ( inventario.existe_siguiente() ) {
        cout << "Elemento: " << inventario.siguiente_dato()->obtener_nombre() << endl;
    }



    Coordenada posicion(4, 4);
    Casilla* camino = new Camino(posicion);

    Coordenada posicion_2(5, 4);
    Casilla* camino_2 = new Camino(posicion_2);


    Objeto* vampiro = new Vampiro(camino, 'v', "id");
    Objeto* humano = new Humano(camino_2, 'h', "id");

    Objeto* estaca = new Estaca(camino, 'e', 1, "id");
    Objeto* balas = new Bala(camino, 'b', 2, "idee");

    camino ->agregar_objeto(estaca);
    camino->agregar_objeto(balas);


    ((Cazador*)cazador)->encuentro_con_elemento();

    Lista<Objeto*> inventario = ((Cazador*)cazador)->obtener_inventario();

    inventario.reiniciar();


    while(inventario.existe_siguiente()) {

       cout << endl << "elemento:" << inventario.siguiente_dato()->obtener_nombre() << endl <<endl;
   }



    int vida_humano = ((Ser*) vampiro) -> devolver_vida();
    int energia_humano = ((Ser*) vampiro) -> devolver_energia();
    int armadura_humano = ((Ser*) vampiro) -> devolver_armadura();
    int fuerza_humano = ((Ser*) vampiro) -> devolver_fuerza();


    cout << "vida humano : " << vida_humano << endl;
    cout << "energia humano : " << energia_humano << endl;
    cout << "armadura humano : " << armadura_humano << endl;
    cout << "fuerza humano : " << fuerza_humano << endl;

    cout << endl;

    int vida_zombie = ((Ser*)humano) -> devolver_vida();
    int energia_zombie = ((Ser*) humano) -> devolver_energia();
    int armadura_zombie = ((Ser*) humano) -> devolver_armadura();
    int fuerza_zombie = ((Ser*) humano) -> devolver_fuerza();

    cout << "vida zombie : " << vida_zombie << endl;
    cout << "energia zombie : " << energia_zombie << endl;
    cout << "armadura zombie : " << armadura_zombie << endl;
    cout << "fuerza zombie : " << fuerza_zombie << endl;

    cout << endl << "ATACO................." << endl << endl;


    ((Ser*) vampiro) -> atacar(camino_2);

    cout << "vida vampiro : " << vida_humano << endl;
    cout << "energia vampiro : " << energia_humano << endl;
    cout << "armadura vampiro : " << armadura_humano << endl;
    cout << "fuerza vampiro : " << fuerza_humano << endl;

    cout << endl;

    cout << "vida humano : " << vida_zombie << endl;
    cout << "energia humano : " << energia_zombie << endl;
    cout << "armadura humano : " << armadura_zombie << endl;
    cout << "fuerza humano : " << fuerza_zombie << endl;





    return 0;
}*/