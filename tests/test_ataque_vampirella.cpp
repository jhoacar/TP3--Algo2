#include "Includes_Objetos.h"
#include <iostream>
#include "../src/funcionalidades/Funciones.h"
#include "../src/mapa/Tablero.h"
#include "../src/objetos/seres/Ser.h"
#include "../src/objetos/elementos/Agua.h"

using namespace std;

// Tests:
// (1) No tiene agua bendita en su inventario, aumenta +3 su energía => Bien!
// (2) Tiene agua bendita en su inventario, regenera toda su energía => Pendiente
// (3) Tiene agua bendita en su inventario, aumenta +1 su armadura   => Pendiente



int main() {

    Tablero* tablero = new Tablero(10, 10);

    Coordenada posicion(4,  4);
    Casilla *casilla = new Camino(posicion);

    Coordenada posicion_2(4, 3);
    Casilla *casilla_2 = new Camino(posicion_2);

    tablero->asignar_casilla(casilla);
    tablero->asignar_casilla(casilla_2);


    Objeto *vampiro = new Vampirella(casilla, 'V', "id");


    Objeto *humano = new Humano(casilla_2, 'h', "id");
    casilla_2-> agregar_objeto(humano);


    //El humano se encuentra con el elemento
    ((Vampirella *) vampiro)->encuentro_con_elemento();
    Lista<Objeto *> inventario = ((Vampirella *) vampiro)->obtener_inventario();

    inventario.reiniciar();
    while (inventario.existe_siguiente()) {
        cout << "Elemento: " << inventario.siguiente_dato()->obtener_nombre() << endl;
    }


    int vida_humano = ((Ser *) vampiro)->devolver_vida();
    int energia_humano = ((Ser *) vampiro)->devolver_energia();
    int armadura_humano = ((Ser *) vampiro)->devolver_armadura();
    int fuerza_humano = ((Ser *) vampiro)->devolver_fuerza();


    cout << "vida vampirella : " << vida_humano << endl;
    cout << "energia vampirella : " << energia_humano << endl;
    cout << "armadura vampirella : " << armadura_humano << endl;
    cout << "fuerza vampirella : " << fuerza_humano << endl;

    cout << endl;

    int vida_zombie = ((Ser *) humano)->devolver_vida();
    int energia_zombie = ((Ser *) humano)->devolver_energia();
    int armadura_zombie = ((Ser *) humano)->devolver_armadura();
    int fuerza_zombie = ((Ser *) humano)->devolver_fuerza();

    cout << "vida humano : " << vida_zombie << endl;
    cout << "energia humano : " << energia_zombie << endl;
    cout << "armadura humano : " << armadura_zombie << endl;
    cout << "fuerza humano : " << fuerza_zombie << endl;

    cout << endl << "ATACO................." << endl << endl;

    Casilla* casilla1= nullptr;

    ((Ser *) vampiro)->atacar(casilla_2, tablero);


    int vida_humano_2 = ((Ser *) vampiro)->devolver_vida();
    int energia_humano_2 = ((Ser *) vampiro)->devolver_energia();
    int armadura_humano_2 = ((Ser *) vampiro)->devolver_armadura();
    int fuerza_humano_2 = ((Ser *) vampiro)->devolver_fuerza();

    int vida_zombie_2 = ((Ser *) humano)->devolver_vida();
    int energia_zombie_2 = ((Ser *) humano)->devolver_energia();
    int armadura_zombie_2 = ((Ser *) humano)->devolver_armadura();
    int fuerza_zombie_2 = ((Ser *) humano)->devolver_fuerza();




    cout << "vida vampirella : " << vida_humano_2 << endl;
    cout << "energia vampirella : " << energia_humano_2 << endl;
    cout << "armadura vampirella : " << armadura_humano_2 << endl;
    cout << "fuerza vampirella : " << fuerza_humano_2 << endl;

    cout << endl;

    cout << "vida humano : " << vida_zombie_2 << endl;
    cout << "energia humano : " << energia_zombie_2 << endl;
    cout << "armadura humano : " << armadura_zombie_2 << endl;
    cout << "fuerza humano : " << fuerza_zombie_2 << endl;


    return 0;

}
