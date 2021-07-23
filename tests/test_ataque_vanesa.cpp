#include "Includes_Objetos.h"
#include <iostream>
#include "Funciones.h"
#include "Tablero.h"
#include "Ser.h"
#include "Agua.h"

using namespace std;

// Tests:
// (1) No tiene agua bendita en su inventario, aumenta +3 su energía => Bien!
// (2) Tiene agua bendita en su inventario, regenera toda su energía => Pendiente
// (3) Tiene agua bendita en su inventario, aumenta +1 su armadura   => Pendiente



int main() {

    Tablero* tablero = new Tablero(10, 10);

    Coordenada posicion(5,  5);
    Casilla *casilla = new Camino(posicion);

    Coordenada posicion_2(6, 5);
    Casilla *casilla_2 = new Camino(posicion_2);

    tablero->asignar_casilla(casilla);
    tablero->asignar_casilla(casilla_2);

    Objeto *estaca = new Estaca(casilla, 'e', 1, "id");
    Objeto *agua = new Agua(casilla, 'a', 1, "id");
    Objeto *balas = new Bala(casilla, 'b', 2, "id");
    Objeto *escopeta = new Escopeta(casilla, 'E', 1, "ideee");
    Objeto *vanesa = new Vanessa(casilla, 'W', "id");


    Objeto *zombie = new Zombie(casilla_2, 'z', "id");
    casilla_2-> agregar_objeto(zombie);

    casilla->agregar_objeto(estaca);
    casilla->agregar_objeto(agua);
    casilla->agregar_objeto(escopeta);
    casilla->agregar_objeto(balas);


    //El humano se encuentra con el elemento
    ((Vanessa *) vanesa)->encuentro_con_elemento();
    Lista<Objeto *> inventario = ((Vanessa *) vanesa)->obtener_inventario();

    inventario.reiniciar();
    while (inventario.existe_siguiente()) {
        cout << "Elemento: " << inventario.siguiente_dato()->obtener_nombre() << endl;
    }


    int vida_humano = ((Ser *) vanesa)->devolver_vida();
    int energia_humano = ((Ser *) vanesa)->devolver_energia();
    int armadura_humano = ((Ser *) vanesa)->devolver_armadura();
    int fuerza_humano = ((Ser *) vanesa)->devolver_fuerza();


    cout << "vida vanesa : " << vida_humano << endl;
    cout << "energia vanesa : " << energia_humano << endl;
    cout << "armadura vanesa : " << armadura_humano << endl;
    cout << "fuerza vanesa : " << fuerza_humano << endl;

    cout << endl;

    int vida_zombie = ((Ser *) zombie)->devolver_vida();
    int energia_zombie = ((Ser *) zombie)->devolver_energia();
    int armadura_zombie = ((Ser *) zombie)->devolver_armadura();
    int fuerza_zombie = ((Ser *) zombie)->devolver_fuerza();

    cout << "vida zombie : " << vida_zombie << endl;
    cout << "energia zombie : " << energia_zombie << endl;
    cout << "armadura zombie : " << armadura_zombie << endl;
    cout << "fuerza zombie : " << fuerza_zombie << endl;

    cout << endl << "ATACO................." << endl << endl;

    Casilla* casilla1= nullptr;

    ((Ser *) vanesa)->atacar(casilla_2, tablero, 'E');


    int vida_humano_2 = ((Ser *) vanesa)->devolver_vida();
    int energia_humano_2 = ((Ser *) vanesa)->devolver_energia();
    int armadura_humano_2 = ((Ser *) vanesa)->devolver_armadura();
    int fuerza_humano_2 = ((Ser *) vanesa)->devolver_fuerza();

    int vida_zombie_2 = ((Ser *) zombie)->devolver_vida();
    int energia_zombie_2 = ((Ser *) zombie)->devolver_energia();
    int armadura_zombie_2 = ((Ser *) zombie)->devolver_armadura();
    int fuerza_zombie_2 = ((Ser *) zombie)->devolver_fuerza();


    cout << "vida vanesa : " << vida_humano_2 << endl;
    cout << "energia vanesa : " << energia_humano_2 << endl;
    cout << "armadura vanesa : " << armadura_humano_2 << endl;
    cout << "fuerza vanesa : " << fuerza_humano_2 << endl;

    cout << endl;

    cout << "vida zombie : " << vida_zombie_2 << endl;
    cout << "energia zombie : " << energia_zombie_2 << endl;
    cout << "armadura zombie : " << armadura_zombie_2 << endl;
    cout << "fuerza zombie : " << fuerza_zombie_2 << endl;


    return 0;

}