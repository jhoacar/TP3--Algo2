#include "Ataque_vampiro.h"


Ataque_vampiro::Ataque_vampiro(Vampiro *personaje): Ataque(personaje){
}

Ataque_vampiro::~Ataque_vampiro(){
}

void Ataque_vampiro::atacar(Casilla *casilla) {

    bool validacion = validacion_ataque(casilla);

    if(validacion){

        Lista<Objeto*> lista_objetos = casilla -> obtener_objetos();

        int posicion;
        posicion = buscar_personaje(casilla, NOMBRES_STRING[HUMANO]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[HUMANO_CAZADOR]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VANESA]);


        if(posicion != NO_ENCONTRADO){
            consumir_energia(2);
            bajar_vida(casilla);
        }


    }
}

Casilla* Ataque_vampiro::validacion_hay_personaje_en_casilla(Lista<Casilla *> lista_casillas){

    bool validacion_hay_personaje = false;
    Casilla* casilla_objeto;

    while(lista_casillas.existe_siguiente() && !validacion_hay_personaje) {
        Casilla *casilla_actual = lista_casillas.siguiente_dato();
        while (casilla_actual->obtener_objetos().existe_siguiente() && !validacion_hay_personaje) {

            Objeto *objeto_actual = casilla_actual->obtener_objetos().siguiente_dato();
            char nombre_actual = objeto_actual->obtener_nombre();


            if (nombre_actual == NOMBRES_CHAR[HUMANO] || nombre_actual == NOMBRES_CHAR[HUMANO_CAZADOR] ||
                nombre_actual == NOMBRES_CHAR[VANESA]) {
                validacion_hay_personaje = true;
                casilla_objeto = objeto_actual -> obtener_casilla();
            }
        }
    }
    return casilla_objeto;
}






bool Ataque_vampiro::validacion_ataque(Casilla *casilla_a_atacar){

    bool validacion_ataque;

    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();

    Lista<Coordenada> lista_casillas_posibles = obtener_cruz(centro, 1);

    bool validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);
    bool energia_suficiente_ = energia_suficiente(2);


    if(validacion_rango && energia_suficiente_)
        validacion_ataque = true;
    else
        validacion_ataque = false;

    return validacion_ataque;
}


void Ataque_vampiro::bajar_vida(Casilla* casilla){

    int indice_humano = indice_personaje(NOMBRES_CHAR[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_CHAR[HUMANO_CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_CHAR[VANESA], casilla);


    if(indice_humano != NO_ENCONTRADO)
        calcular_valores_ataque(indice_humano, 100, casilla);
    if(indice_cazador != NO_ENCONTRADO)
        calcular_valores_ataque(indice_cazador, 100, casilla);
    if(indice_vanesa != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vanesa, 100, casilla);

}



void Ataque_vampiro::atacar(Tablero* tablero) {

    Casilla *casilla_personaje = (personaje ->obtener_casilla());
    Coordenada centro = casilla_personaje->obtener_posicion();

    Lista<Coordenada> lista_coordenadas = obtener_cruz(centro, 1);
    Lista<Casilla *> lista_casillas = tablero -> obtener_lista_casillas(lista_coordenadas);

    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas);


    bool energia_suficiente_ = energia_suficiente(2);
    bool validacion;
    if(casilla_objeto != nullptr)
        validacion = validacion_ataque(casilla_objeto);

    if(casilla_objeto != nullptr && energia_suficiente_ && validacion){

        Lista<Objeto*> lista_objetos = casilla_objeto -> obtener_objetos();

        int posicion;
        posicion = buscar_personaje(casilla_objeto, NOMBRES_STRING[HUMANO]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_objeto, NOMBRES_STRING[HUMANO_CAZADOR]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_objeto, NOMBRES_STRING[VANESA]);


        if(posicion != NO_ENCONTRADO){
            consumir_energia(2);
            bajar_vida(casilla_objeto);
        }
    }
}