#include "../src/funcionalidades/Includes_Objetos.h"
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

    Coordenada posicion(5,  5);
    Casilla *casilla = new Camino(posicion);

    Coordenada posicion_2(6, 5);
    Casilla *casilla_2 = new Camino(posicion_2);

    tablero->asignar_casilla(casilla);
    tablero->asignar_casilla(casilla_2);

    Objeto *agua = new Agua(casilla, 'a', 1, "id");
    Objeto *balas = new Bala(casilla, 'b', 2, "id");
    Objeto *escopeta = new Escopeta(casilla, 'E', 1, "ideee");
    Objeto *humano_simple = new Humano(casilla, 'h', "id");


    Objeto *zombie = new Zombie(casilla_2, 'z', "id");
    casilla_2-> agregar_objeto(zombie);
    //Agrego agua a la casilla
    casilla->agregar_objeto(agua);
    casilla->agregar_objeto(escopeta);
    casilla->agregar_objeto(balas);


    //El humano se encuentra con el elemento
    ((Humano *) humano_simple)->encuentro_con_elemento();
    Lista<Objeto *> inventario = ((Humano *) humano_simple)->obtener_inventario();

    inventario.reiniciar();
    while (inventario.existe_siguiente()) {
        cout << "Elemento: " << inventario.siguiente_dato()->obtener_nombre() << endl;
    }


    int vida_humano = ((Ser *) humano_simple)->devolver_vida();
    int energia_humano = ((Ser *) humano_simple)->devolver_energia();
    int armadura_humano = ((Ser *) humano_simple)->devolver_armadura();
    int fuerza_humano = ((Ser *) humano_simple)->devolver_fuerza();


    cout << "vida humano : " << vida_humano << endl;
    cout << "energia humano : " << energia_humano << endl;
    cout << "armadura humano : " << armadura_humano << endl;
    cout << "fuerza humano : " << fuerza_humano << endl;

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

    //Casilla* casilla1= nullptr;

    ((Ser *) humano_simple)->atacar(casilla_2, tablero);


    int vida_humano_2 = ((Ser *) humano_simple)->devolver_vida();
    int energia_humano_2 = ((Ser *) humano_simple)->devolver_energia();
    int armadura_humano_2 = ((Ser *) humano_simple)->devolver_armadura();
    int fuerza_humano_2 = ((Ser *) humano_simple)->devolver_fuerza();

    int vida_zombie_2 = ((Ser *) zombie)->devolver_vida();
    int energia_zombie_2 = ((Ser *) zombie)->devolver_energia();
    int armadura_zombie_2 = ((Ser *) zombie)->devolver_armadura();
    int fuerza_zombie_2 = ((Ser *) zombie)->devolver_fuerza();


    cout << "vida humano : " << vida_humano_2 << endl;
    cout << "energia humano : " << energia_humano_2 << endl;
    cout << "armadura humano : " << armadura_humano_2 << endl;
    cout << "fuerza humano : " << fuerza_humano_2 << endl;

    cout << endl;

    cout << "vida zombie : " << vida_zombie_2 << endl;
    cout << "energia zombie : " << energia_zombie_2 << endl;
    cout << "armadura zombie : " << armadura_zombie_2 << endl;
    cout << "fuerza zombie : " << fuerza_zombie_2 << endl;

    char letra;
    cin >> letra;
    return 0;

}