#include "Interfaz.h"

Interfaz::Interfaz() {
    this->turnos = 0;
}
void Interfaz::avanzar_turno() {
    this ->turnos++;
}
int Interfaz::devolver_turno() {
    return this -> turnos;
}
void Interfaz::desplegar_menu_principal() {
    limpiar_pantalla();

    gotoxy(0, 0);

    // estps numeros los saque de probar varias veces y ver como encuadraba bien
    int empieza_x = 3;
    int empieza_y = 35;
    int primera_opcion = 3;
    int ultima_opcion = 5;

    Coordenada eleccion;

    cout << "BIENVENIDO AL JUEGO DE NOSFERATU" << endl;
    cout << endl;
    cout << "----------- Jugar -----------" << endl;
    cout << "----------- Creditos -----------" << endl;
    cout << "----------- Salir -----------" << endl;

    eleccion = this ->elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);

    switch(eleccion.obtener_fila()){
        case OPCION_1:
            this -> jugar();
            break;

        case OPCION_2:
            gotoxy(0, ultima_opcion + ESPACIO);
            this ->creditos();
            break;

        case OPCION_3:
            gotoxy(0, ultima_opcion + ESPACIO);
            this ->salir();
            break;

        default:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "Implemetar si se equivoca de opcion" << endl;
    }
}

void Interfaz::salir() {
    cout << "GRACIAS POR JUEGAR, ESPERO VUELVAS PRONTO!" << endl;
}

void Interfaz::creditos() {
    cout << "Este juego fue creado por:" << endl;
    cout << "Jhoan" << endl;
    cout << "Nico" << endl;
    cout << "Franco" << endl;
    cout << "Agustin" << endl;
}

void Interfaz::desplegar_menu_secundario(Tablero* mapa) {
    limpiar_pantalla();

    int empieza_x = 1;
    int empieza_y = 58;
    int primera_opcion = 1;
    int ultima_opcion = 5;

    Coordenada eleccion;

    cout << "> Buscar por ID un personaje u objeto en particular" << endl;
    cout << "> Mostrar tablero" << endl;
    cout << "> Mostrar cantidad de integrantes de un bando" << endl;
    cout << "> Seleccionar bando" << endl;
    cout << "> Atras" << endl;

    eleccion = this ->elegir_opcion(empieza_x, empieza_y, primera_opcion, ultima_opcion);

    gotoxy(0, ultima_opcion + ESPACIO);

    switch(eleccion.obtener_fila()){
        case OPCION_1:
            this ->busqueda_objeto(mapa);
            break;

        case OPCION_2:
            this ->mostrar_tablero(mapa);
            break;

        case OPCION_3:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "Ha elegido la opcion 3" << endl;
            break;

        case OPCION_4:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "Ha elegido la opcion 4" << endl;
            break;

        case OPCION_5:
            this -> desplegar_menu_principal();
            break;

        default:
            gotoxy(0, ultima_opcion + ESPACIO);
            cout << "Implementar si se equivoca de opcion" << endl;
    }
}

Coordenada Interfaz::elegir_opcion(int empieza_menu_x, int empieza_menu_y, int primera_opcion, int ultima_opcion) {
    char tecla=0;
    Coordenada posicion={empieza_menu_x, empieza_menu_y};

    while(tecla!=' '){

        gotoxy(posicion);
        tecla = caracter_mayuscula((char)tecla_pulsada());
        switch(tecla){
            case ARRIBA:
                gotoxy(posicion);
                mover_arriba_menu(posicion, primera_opcion, ultima_opcion);
                break;

            case ABAJO:
                gotoxy(posicion);
                mover_abajo_menu(posicion, primera_opcion, ultima_opcion);
                break;
        }
    }

    posicion = {(posicion.obtener_fila() - primera_opcion +1), posicion.obtener_columna()}; //esto lo haga para que me de el numero de la opcion real

    return posicion;

}

void Interfaz::jugar(){
    Lista<Objeto*> lista_objetos;
    Tablero* mapa = nullptr;
    Archivo_tablero lectura_tablero(FICHERO_TABLERO);

    mapa = lectura_tablero.obtener_tablero();

    Archivo_objetos lectura_objetos(FICHERO_OBJETOS, mapa);

    lista_objetos = lectura_objetos.obtener_lista_objetos();

    this -> desplegar_menu_secundario(mapa);


}

void Interfaz::busqueda_objeto(Tablero* mapa) {
    cout << "";
}

void Interfaz::mostrar_tablero(Tablero* mapa) {
    mapa ->mostrar_tablero();
}