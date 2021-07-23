#include "Ataque_humano.h"
#include "../objetos/elementos/Escopeta.h"
#include "../objetos/elementos/Bala.h"
#include "../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../objetos/seres/monstruos/vampiros/Nosferatu.h"
#include "../objetos/seres/monstruos/vampiros/Vampirella.h"
#include "../objetos/seres/monstruos/zombies/Zombie.h"
#include <stdlib.h>
#include <iostream>
#include "../constantes/Constantes.h"

using namespace std;

Ataque_humano::Ataque_humano(Humano *personaje): Ataque(personaje){
}


Ataque_humano::~Ataque_humano(){
}



bool Ataque_humano::tiene_arma(char arma_elegida){

    Objeto *objeto_referencia = new Escopeta();
    objeto_referencia -> asignar_nombre(arma_elegida);
    Lista<Objeto*> inventario = personaje -> obtener_inventario();
    bool validacion = false;

    bool esta_en_inventario = personaje -> obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);

    if(esta_en_inventario){
        int posicion = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);

        int cantidad = ((Elemento*) personaje -> obtener_inventario()[posicion]) -> obtener_cantidad();

        if(cantidad >= 1)
            validacion = true;
    }
    delete objeto_referencia;
    return validacion;
}





bool Ataque_humano::tiene_balas(int cantidad_minima_balas){

    bool balas_necesarias = false;

    Objeto *objeto_referencia = new Bala();
    char inicial = NOMBRES_CHAR[BALA];
    objeto_referencia -> asignar_nombre(inicial);
    bool esta_en_inventario = personaje -> obtener_inventario().existe(objeto_referencia,comparacion_por_nombre);

    if(esta_en_inventario){
        int posicion_balas = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);

        int cantidad_balas = ((Elemento*) personaje -> obtener_inventario()[posicion_balas]) -> obtener_cantidad();

        if(cantidad_balas >= cantidad_minima_balas)
            balas_necesarias = true;
    }
    delete objeto_referencia;
    return balas_necesarias;
}

void Ataque_humano::bajar_cantidad_objeto(char arma){

    char a_bajar;
    if(arma == NOMBRES_CHAR[ESCOPETA])
        a_bajar = NOMBRES_CHAR[BALA];
    else if(arma == NOMBRES_CHAR[AGUA])
        a_bajar = NOMBRES_CHAR[AGUA];
    else
        a_bajar = NOMBRES_CHAR[ESTACA];

    Objeto *objeto_referencia = new Bala();
    objeto_referencia -> asignar_nombre(a_bajar);
    int posicion = personaje -> obtener_inventario().buscar_dato(0, objeto_referencia,comparacion_por_nombre);

    if(posicion != NO_ENCONTRADO){
        if(a_bajar == NOMBRES_CHAR[BALA])
            ((Elemento*) personaje -> obtener_inventario()[posicion]) -> disminuir_cantidad(2);
        else if(a_bajar == NOMBRES_CHAR[AGUA] || a_bajar == NOMBRES_CHAR[ESTACA])
            ((Elemento*) personaje -> obtener_inventario()[posicion]) -> disminuir_cantidad(1);

    }
    delete objeto_referencia;

}



bool Ataque_humano::validacion_mounstruo_oculto(Casilla *casilla, char arma_elegida){

    Objeto *objeto_referencia = new Vampiro();
    objeto_referencia -> asignar_nombre(NOMBRES_CHAR[VAMPIRO]);

    Lista<Objeto*> lista_objetos = casilla -> obtener_objetos();

    int indice_vampiro = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRO]);
    int indice_zombie = buscar_personaje(casilla, NOMBRES_STRING[ZOMBIE]);
    int indice_vampirella = buscar_personaje(casilla, NOMBRES_STRING[VAMPIRELLA]);

    bool oculto = false;

    if(indice_vampiro != NO_ENCONTRADO){
        oculto = ((Vampiro*)lista_objetos[indice_vampiro]) -> esta_oculto();
    }
    else if(indice_zombie != NO_ENCONTRADO) {
        oculto = ((Zombie*)lista_objetos[indice_zombie]) -> esta_escondido();
    }
    else if(indice_vampirella != NO_ENCONTRADO){
        oculto = ((Vampirella*)lista_objetos[indice_vampirella]) -> esta_oculto();
        if(arma_elegida == NOMBRES_CHAR[ESCOPETA])
            oculto = true;
    }
    delete objeto_referencia;
    return oculto;



}

bool Ataque_humano::validacion_ataque(char arma_elegida, int energia){

    bool validacion_ataque = false;
    bool tiene_suficientes_balas;
    bool energia_suficiente_ = energia_suficiente(energia);
    bool tiene_arma_ = tiene_arma(arma_elegida);
    if(arma_elegida == NOMBRES_CHAR[ESCOPETA]) {
        tiene_suficientes_balas = tiene_balas(2);
        if (energia_suficiente_ && tiene_arma_ && tiene_suficientes_balas)
            validacion_ataque = true;
    }
    else if(energia_suficiente_ && tiene_arma_)
        validacion_ataque = true;

    return validacion_ataque;
}



void Ataque_humano::calcular_ataque_valores_fijos(int indice, int valor_a_sacar, Casilla* casilla){

    int valor_final;
    valor_final = calcular_vida_con_armadura(valor_a_sacar, casilla, indice);
    ((Ser*) casilla -> obtener_objetos()[indice]) -> bajar_vida(valor_final);

}




void Ataque_humano::bajar_vida(Casilla* casilla){

    int indice_zombie = indice_personaje(NOMBRES_CHAR[ZOMBIE], casilla);
    int indice_vampiro = indice_personaje(NOMBRES_CHAR[VAMPIRO], casilla);
    int indice_nosferatu = indice_personaje(NOMBRES_CHAR[NOSFERATU], casilla);
    int indice_vampirella = indice_personaje(NOMBRES_CHAR[VAMPIRELLA], casilla);

    if(indice_zombie != NO_ENCONTRADO)
        calcular_valores_ataque(indice_zombie, 100, casilla);
    else if(indice_vampiro != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vampiro, 20, casilla);
    else if(indice_nosferatu != NO_ENCONTRADO)
        calcular_valores_ataque(indice_nosferatu, 20, casilla);
    else if(indice_vampirella != NO_ENCONTRADO)
        calcular_valores_ataque(indice_vampirella, 20, casilla);
}


Casilla* Ataque_humano::devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro, char arma_elegida, int rango_escopeta){

    Lista<Coordenada> lista_coordenadas;

    if(arma_elegida == NOMBRES_CHAR[ESCOPETA])
        lista_coordenadas = obtener_cuadrado(centro, rango_escopeta);
    else if(arma_elegida == NOMBRES_CHAR[AGUA])
        lista_coordenadas = obtener_cuadrado(centro, 1);
    else if(arma_elegida == NOMBRES_CHAR[ESTACA])
        lista_coordenadas = obtener_cruz(centro, 1);

    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "monstruo");

    return casilla_objeto;

}

Casilla* Ataque_humano::devolver_casilla_especifica_en_tablero(Tablero* tablero, Casilla* casilla){
    Casilla* casilla_atacar = tablero->obtener_casilla(casilla->obtener_posicion());
    return casilla_atacar;
}





bool Ataque_humano::validacion_rango_aleatorio(Tablero* tablero, Coordenada centro, char arma_elegida, int rango_escopeta){

    bool validacion = false;
    bool validacion_hay_objeto = false;
    bool mounstruo_oculto;
    Lista<Coordenada> lista_coordenadas;

    lista_coordenadas = obtener_lista_coordenadas_segun_arma(centro, arma_elegida, rango_escopeta);

    Lista<Casilla *> lista_casillas = tablero->obtener_lista_casillas(lista_coordenadas);
    Casilla* casilla_objeto = validacion_hay_personaje_en_casilla(lista_casillas, "monstruo");

    if(casilla_objeto != nullptr) {
        mounstruo_oculto = validacion_mounstruo_oculto(casilla_objeto, arma_elegida);
        validacion_hay_objeto = true;
    }
    if(validacion_hay_objeto && !mounstruo_oculto)
        validacion = true;
    return validacion;
}



bool Ataque_humano::validacion_rango_especifico(Casilla* casilla_a_atacar, char arma_elegida, int rango_escopeta){
    bool validacion = false;
    bool validacion_rango;
    bool mounstruo_oculto;
    Casilla* casilla_personaje = personaje ->obtener_casilla();
    Coordenada centro = casilla_personaje ->obtener_posicion();

    Lista<Coordenada> lista_casillas_posibles;
    lista_casillas_posibles = obtener_lista_coordenadas_segun_arma(centro, arma_elegida, rango_escopeta);

    validacion_rango = validacion_rango_ataque(lista_casillas_posibles, casilla_a_atacar);
    mounstruo_oculto = validacion_mounstruo_oculto(casilla_a_atacar, arma_elegida);

    if(validacion_rango && !mounstruo_oculto)
        validacion = true;

    return validacion;
}


void Ataque_humano::atacar(Casilla *casilla, Tablero* tablero) {

    Coordenada centro = personaje->obtener_casilla()->obtener_posicion();
    char arma_elegida = NOMBRES_CHAR[ESCOPETA];
    bool ataque_validacion;
    bool validacion_rango;
    Lista<Objeto*> lista_objetos;

    Casilla* casilla_en_tablero;

    if(casilla == nullptr)
        validacion_rango = validacion_rango_aleatorio(tablero, centro, arma_elegida, 1);
    else {
        Coordenada posicion_atacar = casilla->obtener_posicion();
        Casilla *casilla_elegida = tablero->obtener_casilla(posicion_atacar);
        validacion_rango = validacion_rango_especifico(casilla_elegida, arma_elegida, 1);
    }
    ataque_validacion = validacion_ataque(arma_elegida, 5);


    if(validacion_rango && ataque_validacion){

        if(casilla == nullptr)
            casilla_en_tablero = devolver_casilla_aleatoria_en_tablero(tablero, centro, arma_elegida, 1);
        else
            casilla_en_tablero = devolver_casilla_especifica_en_tablero(tablero, casilla);


        int posicion;
        posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[ZOMBIE]);

        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[VAMPIRO]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[VAMPIRELLA]);
        if(posicion == NO_ENCONTRADO)
            posicion = buscar_personaje(casilla_en_tablero, NOMBRES_STRING[NOSFERATU]);

        if(posicion != NO_ENCONTRADO){
            consumir_energia(5);
            bajar_cantidad_objeto(arma_elegida);
            bajar_vida(casilla_en_tablero);
        }
    }
}


void Ataque_humano::atacar(Casilla *casilla, Tablero *tablero, char arma) {
}

Lista<Coordenada> Ataque_humano::obtener_lista_coordenadas_segun_arma(Coordenada centro, char arma_elegida, int rango_escopeta) {
    Lista<Coordenada> lista_coordenadas;
    if(arma_elegida == NOMBRES_CHAR[ESCOPETA])
        lista_coordenadas = obtener_cuadrado(centro, rango_escopeta);
    else if(arma_elegida == NOMBRES_CHAR[AGUA])
        lista_coordenadas = obtener_cuadrado(centro, 1);
    else if(arma_elegida == NOMBRES_CHAR[ESTACA])
        lista_coordenadas = obtener_cruz(centro, 1);

    return lista_coordenadas;
}






