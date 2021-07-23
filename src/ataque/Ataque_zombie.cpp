#include "Ataque_zombie.h"


Ataque_zombie::Ataque_zombie(Zombie *personaje): Ataque(personaje){
}

Ataque_zombie::~Ataque_zombie(){
}

bool Ataque_zombie::validacion_ataque(int energia){

    return energia_suficiente(energia);
}





bool Ataque_zombie::validacion_rango_aleatorio(Tablero* tablero, Coordenada centro){

    bool validacion = false;

    Lista<Coordenada> lista_coordenadas;

    lista_coordenadas = obtener_cruz(centro, 1);
    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "humano");

    if(casilla_objeto != nullptr) {
        validacion = true;
    }
    return validacion;
}

Casilla* Ataque_zombie::devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro){

    Lista<Coordenada> lista_coordenadas;

    lista_coordenadas = obtener_cruz(centro, 1);

    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "humano");

    return casilla_objeto;

}


void Ataque_zombie::atacar(Casilla* casilla, Tablero* tablero) {

    Coordenada centro = personaje->obtener_casilla()->obtener_posicion();
    bool ataque_validacion;
    bool validacion_rango;
    Lista<Objeto*> lista_objetos;

    Casilla* casilla_en_tablero;

    validacion_rango = validacion_rango_aleatorio(tablero, centro);
    ataque_validacion = validacion_ataque(personaje->devolver_energia());

    if(validacion_rango && ataque_validacion){

        casilla_en_tablero = devolver_casilla_aleatoria_en_tablero(tablero, centro);

        int posicion;
        posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[HUMANO]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[HUMANO_CAZADOR]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[VANESA]);

        if(posicion != NO_ENCONTRADO){
            consumir_energia(5);
            bajar_vida(casilla_en_tablero);
        }
    }
}



void Ataque_zombie::bajar_vida(Casilla* casilla){

    int indice_humano = indice_personaje(NOMBRES_CHAR[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_CHAR[HUMANO_CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_CHAR[VANESA], casilla);


    if(indice_humano != NO_ENCONTRADO)
        casilla -> obtener_objetos()[indice_humano] -> asignar_nombre(NOMBRES_CHAR[ZOMBIE]);
    if(indice_cazador != NO_ENCONTRADO)
        casilla -> obtener_objetos()[indice_cazador] -> asignar_nombre(NOMBRES_CHAR[ZOMBIE]);
    if(indice_vanesa != NO_ENCONTRADO)
        casilla -> obtener_objetos()[indice_vanesa] -> asignar_nombre(NOMBRES_CHAR[ZOMBIE]);

}
void Ataque_zombie::atacar(Casilla *casilla, Tablero* tablero, char arma){
}