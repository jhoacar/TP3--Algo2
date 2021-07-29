#ifndef TP3_ALGO2_INTERFAZ_H
#define TP3_ALGO2_INTERFAZ_H

#include "../funcionalidades/Includes_Objetos.h"
#include "../ataque/Ataque.h"
#include "../defensa/Defensa.h"
#include "../mapa/Tablero.h"
#include "../archivo/Archivo_tablero.h"
#include "../archivo/Archivo_objetos.h"
#include "../constantes/Constantes.h"
#include "../funcionalidades/Funciones.h"
#include "../mapa/Coordenada.h"
#include "../juego/jugador.h"
#include "Movimientos.h"
#include <time.h>

const int OPCION_1 = 1;
const int OPCION_2 = 2;
const int OPCION_3 = 3;
const int OPCION_4 = 4;
const int OPCION_5 = 5;
const int OPCION_6 = 6;
const int OPCION_7 = 7;
const int ESPACIO = 3;


class Interfaz : public Movimientos{
private:
    int turnos;
public:
    Interfaz();
    void avanzar_turno();
    int devolver_turno();
    void desplegar_menu_principal();
    int desplegar_menu_secundario(Tablero* mapa, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos);
    Coordenada elegir_opcion(int empieza_menu_x, int empieza_menu_y, int primera_opcion, int ultima_opcion);
    void creditos();
    void salir();
    void busqueda_objeto(Tablero* mapa);
    void mostrar_tablero(Tablero* mapa);
    void guerra(Tablero* mapa);
    bool turno_jugador_1(Tablero* mapa, string bando);
    bool turno_jugador_2();
    void eleccion_movimiento_objeto(int eleccion, Objeto* personaje, Tablero* mapa);
    void ataque_humano(Objeto* personaje, Tablero* mapa);
    void ataque_mounstruo(Objeto* personaje, Tablero* mapa);
    void defensa_humano(Objeto* personaje, Tablero* mapa);
    void defensa_mounstruo(Objeto* personaje, Tablero* mapa);
    int eleccion_defensa_humano();
    int eleccion_arma();
    Coordenada eleccion_coordenada_ataque();
    int movimiento();
    void cantidad_integrantes(Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos);
    void agregar_objeto(Tablero* mapa, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos);
    void eliminar_objeto(Tablero* mapa);
    char eleccion_objeto();
    void eleccion_bando();
    int char_a_int(char tipo);
    Coordenada eleccion_casilla(Tablero* mapa);
    bool validar_id(int id, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos);
    string eleccion_id(char tipo, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos);
    int eleccion_cantidad();
    void crear_objeto_y_guardarlo(int tipo_objeto, char tipo, Tablero* mapa, int cantidad, string id, Objeto* objeto, Coordenada posicion);
    string ingresar_id(int tope_inferior, int tope_superior, Lista<Objeto*> lista_humanos, Lista<Objeto*> lista_mounstruos);
    Lista<Objeto*> extraer_humanos(Lista<Objeto*> lista_objetos);
    Lista<Objeto*> extraer_mounstruos(Lista<Objeto*> lista_objetos);
    void asignar_bando(Jugador &jugador_1, Jugador &jugador_2);
    void eleccion_movimiento();
    void jugar();
};


#endif //TP3_ALGO2_INTERFAZ_H
