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
            posicion = buscar_personaje(casilla, NOMBRES_STRING[CAZADOR]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla, NOMBRES_STRING[VANESA]);


        if(posicion != NO_ENCONTRADO){
            consumir_energia(5);
            bajar_vida(casilla);
        }


    }
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

    int indice_humano = indice_personaje(NOMBRES_STRING[HUMANO], casilla);
    int indice_cazador = indice_personaje(NOMBRES_STRING[CAZADOR], casilla);
    int indice_vanesa = indice_personaje(NOMBRES_STRING[VANESA], casilla);


    if(indice_humano != NO_ENCONTRADO)
        calcular_valores_ataque(indice_zombie, 100, casilla);
    if(indice_cazador != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vampiro, 100, casilla);
    if(indice_vanesa != NO_ENCONTRADO)
        calcular_valores_ataque(indice_nosferatu, 100, casilla);

}
