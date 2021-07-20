#include "Ataque_zombie.h"


Ataque_zombie::Ataque_zombie(Zombie *personaje): Ataque(personaje){
}

Ataque_zombie::~Ataque_zombie(){
}

void Ataque_zombie::atacar(Tablero* tablero) {

    Casilla *casilla_personaje = (personaje ->obtener_casilla());
    Coordenada *centro = casilla_personaje->obtener_posicion();

    Lista<Coordenada> lista_coordenadas = obtener_cruz(centro, 1);
    Lista<Casilla *> lista_casillas = obtener_lista_casillas(lista_coordenadas);

    bool validacion_hay_personaje = false;

    Casilla* casilla_objeto;


    while(lista_casillas.existe_siguiente() && !validacion) {
        Casilla *casilla_actual = lista_casillas.siguiente_dato();
        while(casilla_actual -> obtener_objetos().existe_siguiente() && !validacion){

            Objeto* objeto_actual = casilla_actual -> obtener_objetos().siguiente_dato();
            char nombre_actual = objeto_actual->obtener_nombre();


            if (nombre_actual == NOMBRES_CHAR[HUMANO] || nombre_actual == NOMBRES_CHAR[HUMANO_CAZADOR] || nombre_actual == NOMBRES_CHAR[VANESA]) {
                validacion_hay_personaje = true;
                casilla_objeto = objeto_actual -> obtener_casilla();
            }
        }
    }

    bool energia_suficiente_ = energia_suficiente(5);

    if(validacion_hay_personaje && energia_suficiente_){

        Lista<Objeto*> lista_objetos = casilla_objeto -> obtener_objetos();

        int posicion;
        posicion = buscar_personaje(casilla, NOMBRES_STRING[HUMANO]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[HUMANO_CAZADOR]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VANESA]);


        if(posicion != NO_ENCONTRADO){
            consumir_energia(5);
            bajar_vida(casilla_objeto);
        }


    }
}




void Ataque_zombie::bajar_vida(Casilla* casilla){

    int indice_humano = indice_personaje(NOMBRES_STRING[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_STRING[HUMANO_CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_STRING[VANESA], casilla);


    if(indice_humano != NO_ENCONTRADO)
        casilla -> obtener_objetos()[indice_humano] -> asignar_nombre(NOMBRES_CHAR[ZOMBIE]);
    if(indice_cazador != NO_ENCONTRADO)
        casilla -> obtener_objetos()[indice_cazador] -> asignar_nombre(NOMBRES_CHAR[ZOMBIE]);
    if(indice_vanesa != NO_ENCONTRADO)
        casilla -> obtener_objetos()[indice_vanesa] -> asignar_nombre(NOMBRES_CHAR[ZOMBIE]);

}
