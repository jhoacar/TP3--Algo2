#include "../src/juego/jugador.h"
#include "../src/archivo/Archivo_partida.h"

int main(){
    Coordenada posicion1(3, 6);
    Coordenada posicion2(5, 2);
    Coordenada posicion3(0, 3);
    
    Casilla* casilla;
    Casilla* casilla2;
    Casilla* casilla3;
    casilla = new Camino(posicion1);
    casilla2 = new Camino(posicion2);
    casilla3 = new Camino(posicion3);
    
    Objeto* objeto;
    Objeto* objeto2;
    Objeto* objeto3;
    objeto = new Humano;
    objeto->asignar_nombre('h');
    objeto->asignar_ID("001");
    objeto->asignar_casilla(casilla);
    objeto2 = new Humano;
    objeto2->asignar_nombre('h');
    objeto2->asignar_ID("022");
    objeto2->asignar_casilla(casilla2);
    objeto3 = new Cazador;
    objeto3->asignar_nombre('H');
    objeto3->asignar_ID("624");
    objeto3->asignar_casilla(casilla3);

    Objeto* elemento1;
    Objeto* elemento2;
    Objeto* elemento3;

    elemento1 = new Agua(casilla, 'a', 10, "523");
    elemento2 = new Bala(casilla2, 'b', 3, "801");
    elemento3 = new Cruz(casilla3, 'c', 1, "033");

    Lista<Objeto*> elementos;
    elementos.agregar(elemento1);
    elementos.agregar(elemento2);
    elementos.agregar(elemento3);

    Lista<Objeto*> objetos;
    objetos.agregar(objeto);
    objetos.agregar(objeto2);
    objetos.agregar(objeto3);

    // PRUEBA DE ARCHIVO_PARTIDA
    
    Jugador* jugador1;
    jugador1 = new Jugador(1, "humanos");
    jugador1->guardar_personajes_de_jugador(objetos);

    Archivo_partida partida;

    cout << partida.obtener_contenido_datos_jugador(jugador1, false);
    cout << endl << partida.obtener_contenido_objetos(elementos) << endl;
    partida.guardar_partida(jugador1, jugador1, elementos);

    delete jugador1;

    return 0;
}