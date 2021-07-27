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
#include "Movimientos.h"

const int OPCION_1 = 1;
const int OPCION_2 = 2;
const int OPCION_3 = 3;
const int OPCION_4 = 4;
const int OPCION_5 = 5;
const int ESPACIO = 5;


class Interfaz : public Movimientos{
private:
    int turnos;
public:
    Interfaz();
    void avanzar_turno();
    int devolver_turno();
    void desplegar_menu_principal();
    void desplegar_menu_secundario(Tablero* mapa);
    Coordenada elegir_opcion(int empieza_menu_x, int empieza_menu_y, int primera_opcion, int ultima_opcion);
    void creditos();
    void salir();
    void busqueda_objeto(Tablero* mapa);
    void mostrar_tablero(Tablero* mapa);
    void eleccion_movimiento();
    void jugar();
};


#endif //TP3_ALGO2_INTERFAZ_H
