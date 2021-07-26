#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>


using namespace std;

// Tests:
// (1) No tiene agua bendita en su inventario, aumenta +3 su energía => Bien!
// (2) Tiene agua bendita en su inventario, regenera toda su energía => Pendiente
// (3) Tiene agua bendita en su inventario, aumenta +1 su armadura   => Pendiente



int main() {

    Tablero* tablero = new Tablero(10, 10);

   ;

    Coordenada posicion_2(6, 5);
    Casilla *casilla_2 = new Camino(posicion_2);

    Coordenada posicion_3(5, 5);
    Casilla *casilla_3 = new Camino(posicion_3);

    Coordenada posicion_4(5, 6);
    Casilla *casilla_4 = new Camino(posicion_4);


    tablero->asignar_casilla(casilla_2);
    tablero->asignar_casilla(casilla_3);
    tablero->asignar_casilla(casilla_4);


    Objeto *nosferatu = new Nosferatu(casilla_2, 'N', "id");
    casilla_2-> agregar_objeto(nosferatu);
    Objeto *vampiro = new Vampiro(casilla_3, 'v', "id");
    casilla_2-> agregar_objeto(vampiro);




    int vida_humano = ((Ser *) nosferatu)->devolver_vida();
    int energia_humano = ((Ser *) nosferatu)->devolver_energia();
    int armadura_humano = ((Ser *) nosferatu)->devolver_armadura();
    int fuerza_humano = ((Ser *) nosferatu)->devolver_fuerza();


    cout << "vida nosferatu : " << vida_humano << endl;
    cout << "energia nosferatu : " << energia_humano << endl;
    cout << "armadura nosferatu : " << armadura_humano << endl;
    cout << "fuerza nosferatu : " << fuerza_humano << endl;

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



    ((Ser *) nosferatu)->defender(tablero);



    int vida_humano_2 = ((Ser *) nosferatu)->devolver_vida();
    int energia_humano_2 = ((Ser *) nosferatu)->devolver_energia();
    int armadura_humano_2 = ((Ser *) nosferatu)->devolver_armadura();
    int fuerza_humano_2 = ((Ser *) nosferatu)->devolver_fuerza();


    int vida_zombie_2 = ((Ser *) vampiro)->devolver_vida();
    int energia_zombie_2 = ((Ser *) vampiro)->devolver_energia();
    int armadura_zombie_2 = ((Ser *) vampiro)->devolver_armadura();
    int fuerza_zombie_2 = ((Ser *) vampiro)->devolver_fuerza();


    cout << "vida nosferatu : " << vida_humano_2 << endl;
    cout << "energia nosferatu : " << energia_humano_2 << endl;
    cout << "armadura nosferatu : " << armadura_humano_2 << endl;
    cout << "fuerza nosferatu : " << fuerza_humano_2 << endl;

    cout << endl;


    cout << "vida vampiro : " << vida_zombie_2 << endl;
    cout << "energia vampiro : " << energia_zombie_2 << endl;
    cout << "armadura vampiro : " << armadura_zombie_2 << endl;
    cout << "fuerza vampiro : " << fuerza_zombie_2 << endl;


    return 0;

}