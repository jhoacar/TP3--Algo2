//#include "../src/funcionalidades/Datos.h"
#include "../src/funcionalidades/Includes_Objetos.h"
#include <iostream>

using namespace std;

// Tests:
// (1) No tiene agua bendita en su inventario, aumenta +3 su energía => Bien!
// (2) Tiene agua bendita en su inventario, regenera toda su energía => Pendiente
// (3) Tiene agua bendita en su inventario, aumenta +1 su armadura   => Pendiente

int main(){


    Coordenada posicion(4, 4);
    Casilla* camino = new Camino(posicion);

    Coordenada posicion_2(5, 4);
    Casilla* camino_2 = new Camino(posicion_2);


    Objeto* humano_simple = new Humano(camino, 'h', "id");
    Objeto* zombie = new Zombie(camino_2, 'z', "id");

    Objeto* escopeta = new Escopeta(camino, 'E', 1, "id");
    Objeto* balas = new Bala(camino, 'b', 2, "id");

   //humano_simple -> asignar_casilla(casilla);

    Lista<Objeto*> lista = ((Ser*) humano_simple)-> obtener_inventario();

    lista.agregar(escopeta);
    lista.agregar(balas);

    int vida_humano = ((Ser*) humano_simple) -> devolver_vida();
    int energia_humano = ((Ser*) humano_simple) -> devolver_energia();
    int armadura_humano = ((Ser*) humano_simple) -> devolver_armadura();
    int fuerza_humano = ((Ser*) humano_simple) -> devolver_fuerza();


    cout << "vida humano : " << vida_humano << endl;
    cout << "energia humano : " << energia_humano << endl;
    cout << "armadura humano : " << armadura_humano << endl;
    cout << "fuerza humano : " << fuerza_humano << endl;

    cout << endl;

    int vida_zombie = ((Ser*) zombie) -> devolver_vida();
    int energia_zombie = ((Ser*) zombie) -> devolver_energia();
    int armadura_zombie = ((Ser*) zombie) -> devolver_armadura();
    int fuerza_zombie = ((Ser*) zombie) -> devolver_fuerza();

    cout << "vida zombie : " << vida_zombie << endl;
    cout << "energia zombie : " << energia_zombie << endl;
    cout << "armadura zombie : " << armadura_zombie << endl;
    cout << "fuerza zombie : " << fuerza_zombie << endl;

    cout << endl << "ATACO................." << endl << endl;


    ((Ser*) humano_simple) -> atacar(camino_2);

    cout << "vida humano : " << vida_humano << endl;
    cout << "energia humano : " << energia_humano << endl;
    cout << "armadura humano : " << armadura_humano << endl;
    cout << "fuerza humano : " << fuerza_humano << endl;

    cout << endl;

    cout << "vida zombie : " << vida_zombie << endl;
    cout << "energia zombie : " << energia_zombie << endl;
    cout << "armadura zombie : " << armadura_zombie << endl;
    cout << "fuerza zombie : " << fuerza_zombie << endl;











    /*Coordenada posicion(10, 10);
    Casilla* camino = new Camino(posicion);
    Objeto* humano_simple = new Humano(camino, 'h', "id");

    cout << "Energía previa: " << ((Ser*)humano_simple)->devolver_energia() << endl;
    ((Humano*)humano_simple)->defenderse();
    cout << "Energía posterior: " << ((Ser*)humano_simple)->devolver_energia() << endl;
*/
    return 0;
}
