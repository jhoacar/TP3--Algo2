/*#include "Includes_Objetos.h"
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
    Objeto *cazador = new Cazador(casilla, 'H', "id");


    Objeto *vampiro = new Vampiro(casilla_2, 'v', "id");
    casilla_2-> agregar_objeto(vampiro);

    casilla->agregar_objeto(estaca);
    casilla->agregar_objeto(agua);
    casilla->agregar_objeto(escopeta);
    casilla->agregar_objeto(balas);


    //El humano se encuentra con el elemento
    ((Cazador *) cazador)->encuentro_con_elemento();
    Lista<Objeto *> inventario = ((Cazador *) cazador)->obtener_inventario();

    inventario.reiniciar();
    while (inventario.existe_siguiente()) {
        cout << "Elemento: " << inventario.siguiente_dato()->obtener_nombre() << endl;
    }


    int vida_humano = ((Ser *) cazador)->devolver_vida();
    int energia_humano = ((Ser *) cazador)->devolver_energia();
    int armadura_humano = ((Ser *) cazador)->devolver_armadura();
    int fuerza_humano = ((Ser *) cazador)->devolver_fuerza();


    cout << "vida cazador : " << vida_humano << endl;
    cout << "energia cazador : " << energia_humano << endl;
    cout << "armadura cazador : " << armadura_humano << endl;
    cout << "fuerza cazador : " << fuerza_humano << endl;

    cout << endl;

    int vida_zombie = ((Ser *) vampiro)->devolver_vida();
    int energia_zombie = ((Ser *) vampiro)->devolver_energia();
    int armadura_zombie = ((Ser *) vampiro)->devolver_armadura();
    int fuerza_zombie = ((Ser *) vampiro)->devolver_fuerza();

    cout << "vida vampiro : " << vida_zombie << endl;
    cout << "energia vampiro : " << energia_zombie << endl;
    cout << "armadura vampiro : " << armadura_zombie << endl;
    cout << "fuerza vampiro : " << fuerza_zombie << endl;

    cout << endl << "ATACO................." << endl << endl;

    Casilla* casilla1= nullptr;

    ((Ser *) cazador)->atacar(casilla_2, tablero, 'e');


    int vida_humano_2 = ((Ser *) cazador)->devolver_vida();
    int energia_humano_2 = ((Ser *) cazador)->devolver_energia();
    int armadura_humano_2 = ((Ser *) cazador)->devolver_armadura();
    int fuerza_humano_2 = ((Ser *) cazador)->devolver_fuerza();

    int vida_zombie_2 = ((Ser *) vampiro)->devolver_vida();
    int energia_zombie_2 = ((Ser *) vampiro)->devolver_energia();
    int armadura_zombie_2 = ((Ser *) vampiro)->devolver_armadura();
    int fuerza_zombie_2 = ((Ser *) vampiro)->devolver_fuerza();


    cout << "vida cazador : " << vida_humano_2 << endl;
    cout << "energia cazador : " << energia_humano_2 << endl;
    cout << "armadura cazador : " << armadura_humano_2 << endl;
    cout << "fuerza cazador : " << fuerza_humano_2 << endl;

    cout << endl;

    cout << "vida vampiro : " << vida_zombie_2 << endl;
    cout << "energia vampiro : " << energia_zombie_2 << endl;
    cout << "armadura vampiro : " << armadura_zombie_2 << endl;
    cout << "fuerza vampiro : " << fuerza_zombie_2 << endl;


    return 0;

}*/