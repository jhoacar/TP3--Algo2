#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>


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

    Coordenada posicion_3(4, 5);
    Casilla *casilla_3 = new Camino(posicion_3);

    Coordenada posicion_4(5, 6);
    Casilla *casilla_4 = new Camino(posicion_4);

    tablero->asignar_casilla(casilla);
    tablero->asignar_casilla(casilla_2);
    tablero->asignar_casilla(casilla_3);
    tablero->asignar_casilla(casilla_4);

    Objeto *agua = new Agua(casilla_4, 'a', 1, "id");
    Objeto *balas = new Bala(casilla, 'b', 2, "id");
    Objeto *escopeta = new Escopeta(casilla, 'E', 1, "ideee");

    casilla_4->agregar_objeto(agua);
    casilla->agregar_objeto(escopeta);
    casilla->agregar_objeto(balas);
    Objeto *cazador = new Cazador(casilla, 'H', "id");


    Objeto *humano = new Humano(casilla_2, 'h', "id");
    casilla-> agregar_objeto(humano);
    Objeto *humano_2 = new Humano(casilla_3, 'h', "id");
    casilla_2-> agregar_objeto(humano_2);
    Objeto *vanesa = new Vanessa(casilla_4, 'W', "id");
    casilla_4-> agregar_objeto(vanesa);




    //El humano se encuentra con el elemento
    ((Vanessa *) vanesa)->encuentro_con_elemento();
    Lista<Objeto *> inventario = ((Vanessa *) vanesa)->obtener_inventario();

    inventario.reiniciar();
    while (inventario.existe_siguiente()) {
        cout << "Elemento: " << inventario.siguiente_dato()->obtener_nombre() << endl;
    }

    ((Humano *) humano_2)->transformar();
    ((Humano *) vanesa)->transformar();

    bool en_transformacion_humano = ((Humano *) humano_2)->devolver_en_transformacion();
    int vida_humano = ((Ser *) humano_2)->devolver_vida();
    int energia_humano = ((Ser *) humano_2)->devolver_energia();
    int armadura_humano = ((Ser *) humano_2)->devolver_armadura();
    int fuerza_humano = ((Ser *) humano_2)->devolver_fuerza();

    cout << "en transformacion humano_2 : " << en_transformacion_humano << endl;
    cout << "vida humano_2 : " << vida_humano << endl;
    cout << "energia humano_2 : " << energia_humano << endl;
    cout << "armadura humano_2 : " << armadura_humano << endl;
    cout << "fuerza humano_2 : " << fuerza_humano << endl;

    cout << endl;

    bool en_transformacion_vanesa = ((Humano *) humano_2)->devolver_en_transformacion();
    int vida_zombie = ((Ser *) vanesa)->devolver_vida();
    int energia_zombie = ((Ser *) vanesa)->devolver_energia();
    int armadura_zombie = ((Ser *) vanesa)->devolver_armadura();
    int fuerza_zombie = ((Ser *) vanesa)->devolver_fuerza();

    cout << "en transformacion vanesa : " << en_transformacion_vanesa << endl;
    cout << "vida vanesa : " << vida_zombie << endl;
    cout << "energia vanesa : " << energia_zombie << endl;
    cout << "armadura vanesa : " << armadura_zombie << endl;
    cout << "fuerza vanesa : " << fuerza_zombie << endl;

    cout << endl << "ATACO................." << endl << endl;


    bool validacion = ((Vanessa *) cazador)->validacion_defensa(5);
    if(validacion)
        ((Ser *) vanesa)->defender(tablero);


    bool en_transformacion_humano_2 = ((Humano *) humano_2)->devolver_en_transformacion();
    int vida_humano_2 = ((Ser *) humano_2)->devolver_vida();
    int energia_humano_2 = ((Ser *) humano_2)->devolver_energia();
    int armadura_humano_2 = ((Ser *) humano_2)->devolver_armadura();
    int fuerza_humano_2 = ((Ser *) humano_2)->devolver_fuerza();

    bool en_transformacion_vanesa_2 = ((Humano *) humano_2)->devolver_en_transformacion();
    int vida_zombie_2 = ((Ser *) vanesa)->devolver_vida();
    int energia_zombie_2 = ((Ser *) vanesa)->devolver_energia();
    int armadura_zombie_2 = ((Ser *) vanesa)->devolver_armadura();
    int fuerza_zombie_2 = ((Ser *) vanesa)->devolver_fuerza();

    cout << "en transformacion humano_2 : " << en_transformacion_humano_2 << endl;
    cout << "vida humano_2 : " << vida_humano_2 << endl;
    cout << "energia humano_2 : " << energia_humano_2 << endl;
    cout << "armadura humano_2 : " << armadura_humano_2 << endl;
    cout << "fuerza humano_2 : " << fuerza_humano_2 << endl;

    cout << endl;

    cout << "en transformacion vanesa : " << en_transformacion_vanesa_2 << endl;
    cout << "vida vanesa : " << vida_zombie_2 << endl;
    cout << "energia vanesa : " << energia_zombie_2 << endl;
    cout << "armadura vanesa : " << armadura_zombie_2 << endl;
    cout << "fuerza vanesa : " << fuerza_zombie_2 << endl;


    return 0;

}
